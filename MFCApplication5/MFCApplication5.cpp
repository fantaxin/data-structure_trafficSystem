
// MFCApplication5.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "Graph.cpp"
#include "UFSets.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5App

BEGIN_MESSAGE_MAP(CMFCApplication5App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCApplication5App 构造

CMFCApplication5App::CMFCApplication5App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CMFCApplication5App 对象

CMFCApplication5App theApp;


// CMFCApplication5App 初始化

BOOL CMFCApplication5App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	//

	//读入文件，初始化图
	//Graph<string, int> G;
	G.readfile();


	//
	CMFCApplication5Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}


#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

string CSTS(CString cstr)
{
	LPCWSTR wstr(cstr);

	int size = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);

	char* p = new char[size + 1];

	WideCharToMultiByte(CP_ACP, 0, wstr, -1, p, size, NULL, NULL);

	return p;
}
LPCWSTR StringToLPCWSTR(string str)
{
	int size = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* buffer = new wchar_t[size + 1];

	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, buffer, size);

	return buffer;
}
string LPCWSTRToString(LPCWSTR wstr)
{
	int size = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);

	char* p = new char[size + 1];

	WideCharToMultiByte(CP_ACP, 0, wstr, -1, p, size, NULL, NULL);

	return p;
}
double cstring2double(CString cstr)
{
	double score1;
	string str1;
	str1 = CSTS(cstr);
	stringstream s1;
	s1 << str1;
	s1 >> score1;
	return score1;
}
CString int2cstring(int a)
{
	stringstream ss;
	ss << a;
	string str;
	str = ss.str();
	CString cstr;
	cstr = str.c_str();
	return cstr;
}
CString double2cstring(double a)
{
	stringstream ss;
	ss << a;
	string str;
	str = ss.str();
	CString cstr;
	cstr = str.c_str();
	return cstr;
}
string double2string(double a)
{
	stringstream ss;
	ss << a;
	string str;
	str = ss.str();
	return str;
}
double string2double(string str1)
{
	double score1;
	stringstream s1;
	s1 << str1;
	s1 >> score1;
	return score1;
}
vector<Line> DFS(Graph<string,int>& G, const int&v)
{
	vector<Line> vec;
	int local = v;
	bool* visited = new bool[G.numVertexs];
	for (int i = 0; i < G.numVertexs; i++)
	{
		visited[i] = false;
	}
	DFS(G, local, visited, vec);
	delete[] visited;
	return vec;
}
void DFS(Graph<string,int>& G, int v, bool visited[], vector<Line>& vec)
{
	Line l;
	l.departure = v;
	visited[v] = true;
	int w = G.getFirstNeighbor(v);
	while (w != -1)
	{
		if (visited[w] == false)
		{
			l.destination = w;
			vec.push_back(l);
			DFS(G, w, visited,vec);
		}
		w = G.getNextNeighbor(v,w);
	}
}
vector<Line> BFS(Graph<string, int>& G, const int&v)
{
	vector<Line> vec;
	Line l;
	int w;
	int local = v;
	bool* visited = new bool[G.numVertexs];
	for (int i = 0; i < G.numVertexs; i++)
	{
		visited[i] = false;
	}
	visited[local] = true;
	queue<int> q;
	q.push(local);
	while (!q.empty())
	{
		local = q.front();
		q.pop();
		w = G.getFirstNeighbor(local);
		while (w != -1)
		{
			if (visited[w] == false)
			{
				l.departure = local;
				l.destination = w;
				vec.push_back(l);
				visited[w] = true;
				q.push(w);
			}
			w = G.getNextNeighbor(local, w);
		}
	}
	return vec;
}
vector<Line> Kruskal(Graph<string, int>& G)
{
	Line l;
	vector<Line> vec;
	vector<Line> temp;
	int u, v;
	UFSets f(G.numVertexs);
	for ( u = 0; u < G.numVertexs; u++)
	{
		for ( v = u + 1; v < G.numVertexs; v++)
		{
			l.departure = u;
			l.destination = v;
			l.cost = G.getWeight(u, v);
			if (l.cost > 0)
			{
				temp.push_back(l);
			}
		}
	}
	QuickSort(temp, 0, temp.size() - 1);
	int count = 1;
	int tempNum = 0;
	while (count < G.numVertexs)
	{
		l = temp[tempNum];
		tempNum++;
		u = f.Find(l.departure);
		v = f.Find(l.destination);
		if (u != v)
		{
			f.Union(u, v);
			vec.push_back(l);
			count++;
		}
	}
	return vec;
}
vector<Line> Prim(Graph<string, int>& G,int u)
{
	Line l;
	vector<Line> vec;
	vector<Line> temp;
	int v=0;
	UFSets f(G.numVertexs);
	bool* Vmst = new bool[G.numVertexs];
	for (int i = 0; i < G.numVertexs; i++)
	{
		Vmst[i] = false;
	}
	Vmst[u] = true;
	int count = 1;
	do 
	{
		v = G.getFirstNeighbor(u);
		while (v != -1)
		{
			if (Vmst[v] == false)
			{
				l.departure = u;
				l.destination = v;
				l.cost = G.getWeight(u, v);
				temp.push_back(l);
			}
		v = G.getNextNeighbor(u, v);
		}
		QuickSort(temp, 0, temp.size() - 1);
		int tempNum = 0;
		while (count < G.numVertexs)
		{
			l = temp[tempNum];
			tempNum++;
			if (Vmst[l.destination] == false)
			{
				vec.push_back(l);
				u = l.destination;
				Vmst[u] = true;
				count++;
				break;
			}
		}
	} while (count < G.numVertexs);
	return vec;
}
vector<vector<Line>> AllPath(Graph<string, int>& G, int v, int destination)
{
	//输入：图、出发地、目的地
	//输出：从出发地到目的地的所有路径信息到文件中
	vector<vector<Line>> vec;//记录所有路径
	bool visited[34];//记录某个节点是否被访问过，防止形成环路
	for (int i = 0; i < 34; i++)//将所有节点都标记为为访问过
	{
		visited[i] = false;
	}
	stack<int> s;//栈
	s.push(v);//将出发地入栈
	visited[v] = true;//标记出发地为已访问过
	int local = G.getFirstNeighbor(v);//记录v的第一个邻接结点
	int temp;
	while (1)//每次循环输出一条路径信息
	{
		while (local != -1)//每次循环向后遍历一个节点
		{
			s.push(local);
			visited[local] = true;
			if (s.size() > 9)//如果城市个数达到某个值就停止
			{
				break;
			}
			if (local == destination)//如果到达目的地就停止
			{
				break;
			}
			temp = G.getFirstNeighbor(local);//第一个邻接结点
			//如果该节点没有邻接结点执行下一步操作
			//如果该节点第一个邻接结点未访问过则继续遍历
			if (temp == -1 || visited[temp] == false)
			{
				local = G.getFirstNeighbor(local);
				continue;
			}
			temp = G.getNextNeighbor(local, temp);
			while (temp != -1 && visited[temp] == true)
			//寻找下一个未访问过的邻接结点直到没有下一个邻接结点
			{
				temp = G.getNextNeighbor(local, temp);
			}
			local = temp;
		}

        //如果遍历到达目的地，添加一条路径信息
		if (s.top() == destination)
		{
			vec.push_back(Stack2vec(G,s));
		}

		do {//每次循环向前回溯一个节点
			temp = s.top();
			visited[temp] = false;
			s.pop();//回溯，退栈
			if (s.size()==0)//如果回溯到底，即此时已遍历完所有的路径，无路可走
			{
				QuickSort(vec, 0, vec.size() - 1);//排序，返回所有的路径信息
				return vec;
			}
			int top = s.top();
			temp = G.getNextNeighbor(top, temp);
			while (temp != -1 && visited[temp] == true)
			{//回溯后的第一个向后遍历的节点
				temp = G.getNextNeighbor(top, temp);
			}
			local = temp;
		} while (local == -1);
	}
}
vector<Line> Stack2vec(Graph<string, int>& G,stack<int> s)
{
	vector<Line> path;
	path.push_back(Line());
	Line l;
	int cost = 0;
	stack<int> reverse;
	int distance = 0;
	int max = s.size();
	for (int i = 0; i < max; i++)
	{
		reverse.push(s.top());
		s.pop();
	}
	for (int i = 0; i < max - 1; i++)
	{
		l.departure = reverse.top();
		reverse.pop();
		l.destination = reverse.top();
		cost += G.getWeight(l.departure, l.destination);
		path.push_back(l);
	}
	path[0].cost = cost;
	return path;
}
void QuickSort(vector<vector<Line>> &a, int left, int right)
{
	if (left >= right)
		return;
	int local = left;//以第一个元素为基准
	for (int i = local + 1; i <= right; i++)
	{
		if (a[i][0].cost <= a[left][0].cost)
		{
			local++;
			if (local != i)
			{
				swap(a[local], a[i]);
			}
		}
	}
	swap(a[left], a[local]);
	QuickSort(a, left, local - 1);
	QuickSort(a, local + 1, right);
}
void QuickSort(vector<Line> &a, int left, int right)
{
	if (left >= right)
		return;
	int local = left;//以第一个元素为基准
	for (int i = local + 1; i <= right; i++)
	{
		if (a[i].cost <= a[left].cost)
		{
			local++;
			if (local != i)
			{
				swap(a[local], a[i]);
			}
		}
	}
	swap(a[left], a[local]);
	QuickSort(a, left, local - 1);
	QuickSort(a, local + 1, right);
}
void Dijkstra(Graph<string, int>& G, int v, vector<int>& dist, vector<int>& path, int avoid)
{
	int n = G.numVertexs;
	bool* S = new bool[n];
	int i, j, k;
	int w, min;
	for (i = 0; i < n; i++)
	{
		dist.push_back(G.getWeight(v, i,avoid));
		S[i] = false;
		if (i != avoid && i != v && dist[i] < INT_MAX)
		{
			path.push_back(v);
		}
		else
		{
			path.push_back(-1);
		}
	}
	S[v] = true;
	dist[v] = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = INT_MAX;
		int u = v;
		for (j = 0; j < n; j++)
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;
		for (k = 0; k < n; k++)
		{
			w = G.getWeight(u, k,avoid);
			if (S[k] == false && w < INT_MAX && dist[u] + w < dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}
vector<Line> DijkstraPath(Graph<string, int>& G, int v, int u,int avoid)
{
	vector<int> dist;
	vector<int> path;
	Dijkstra(G, v, dist, path, avoid);
	int n = G.numVertexs;
	vector<Line> vec;
	vector<Line> vec2;
	Line l;
	int precity = u;
	l.destination = precity;
	for (size_t i = 0; i < n; i++)
	{
		if (path[precity] == -1)
		{
			l.departure = precity;
			break;
		}
		l.departure = path[precity];
		vec2.push_back(l);
		precity = l.departure;
		l.destination = precity;
	}
	for (int i = vec2.size() - 1; i >= 0; i--)
	{
		vec.push_back(vec2[i]);
	}
	vec[0].cost = dist[u];
	return vec;
}

void Floyd(Graph<string, int>& G, int dist[34][34], int path[34][34], int avoid)
{
	//int dist[34][34];
	//int path[34][34];
	for (int i = 0; i < G.numVertexs; i++)
	{
		for (int j = 0; j < G.numVertexs; j++)
		{
			dist[i][j] = G.getWeight(i, j, avoid);
			if (dist[i][j] >= 99999)
				dist[i][j] = 10000;
			if (i != j && dist[i][j] < INT_MAX)
			{
				path[i][j] = i;
			}
			else
			{
				dist[i][j] = 0;
				path[i][j] = -1;
			}
		}
	}
	for (int k = 0; k < G.numVertexs; k++)
	{
		for (int i = 0; i < G.numVertexs; i++)
		{
			for (int j = 0; j < G.numVertexs; j++)
			{
				if ((dist[i][k] + dist[k][j] )< dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

void FloydPath(int departure, int destination, int path[34][34], vector<Line>& vec)
{
	vector<Line> vec2;
	Line l;
	int n = 34;
	int precity = destination;
	l.destination = precity;
	for (size_t i = 0; i < n; i++)
	{
		if (path[departure][precity] == -1)
		{
			l.departure = precity;
			break;
		}
		l.departure = path[departure][precity];
		vec2.push_back(l);
		precity = l.departure;
		l.destination = precity;
	}
	for (int i = vec2.size() - 1; i >= 0; i--)
	{
		vec.push_back(vec2[i]);
	}
}

vector<int> Height(vector<Line> l)
{
	//输入：广度优先遍历结果
	//输出：广度优先最深的节点
	vector<int> result;
	BT<int> tree(l[0].departure);//以出发地为根节点的二叉树
	for (int i = 0; i < l.size(); i++)
	{
		Height_Insert(tree, l[i]);//向树中插入节点
	}
	result = Height_Max(tree.root);//求解答案
	return result;
}

void Height_Insert(BT<int> tree, Line l)
{
	//将节点插入兄弟孩子表示法的二叉树的合适的位置
	//输入：二叉树，路径
	BTNode<int>* ptr = Height_BTBFS(tree, l.departure);//广度优先寻找插入目标节点指针
	if (ptr->lChild == NULL)//如果目标节点没有孩子节点
	{
		ptr->lChild = new BTNode<int>(l.destination);//插入到其孩子节点位置
		return;
	}
	else if (ptr->lChild->rChild == NULL)//如果其第一个兄弟节点为空
	{
		ptr->lChild->rChild = new BTNode<int>(l.destination);//插到其第一个兄弟节点位置
		return;
	}
	else//否则一直递归直到出现空的兄弟节点
	{
		BTNode<int>* temp = ptr->lChild->rChild;
		while (temp->rChild != NULL)
		{
			temp = temp->rChild;
		}
		temp->rChild = new BTNode<int>(l.destination);
		return;
	}
}

//广度优先遍历寻找节点位置
BTNode<int>* Height_BTBFS(BT<int> tree, int data)
{
	//输入：二叉树、目标节点的元素值
	//输出：插入的目标节点的指针
	queue<BTNode<int>*> q;//利用队列进行广度优先遍历
	q.push(tree.root);
	BTNode<int>* temp = q.front();
	BTNode<int>* templ;
	BTNode<int>* tempr;
	while (temp->data != data)//遍历，直到找到目标节点
	{
		temp = q.front();
		q.pop();
		templ = temp->lChild;
		tempr = temp->rChild;
		if (templ != NULL)
		{
			q.push(templ);
		}
		if (tempr != NULL)
		{
			q.push(tempr);
		}
	}
	return temp;
}

//递归计算最大高度
vector<int> Height_Max(BTNode<int>* root)
{
	//输入：树的根节点
	//输出：最深（即高度为0且其祖宗节点高度最高）的若干个节点的数组
	vector<int> result, resultl, resultr;//三个数组分别储存自己的结果和孩子、兄弟的结果
	result.push_back(0);//第一个数据代表高度信息
	if (root == NULL)
	{
		return result;
	}
	resultl = Height_Max(root->lChild);
	resultr = Height_Max(root->rChild);

	//不管孩子是不是null，都计算自己的高度信息
	result[0] = resultl[0] + 1;//自己的高度应为孩子高度+1
	if (resultl[0] == 0)//如果自己高度为0（没有孩子）
	{
		result.push_back(root->data);
	}
	for (int i = 1; i <= resultl.size() - 1; i++)
	{
		result.push_back(resultl[i]);//将孩子的结果加入到自己的结果中
	}

	//如果该树的高度与其兄弟的高度一致，将其兄弟的高度信息加入到自己的高度信息中后返回
	if (result[0] == resultr[0])
	{
		for (int i = 1; i <= resultr.size() - 1; i++)
		{
			result.push_back(resultr[i]);
		}
		return result;
	}

	//如果该树的高度小于其兄弟的高度，将其兄弟的高度信息返回
	return (result[0] > resultr[0]) ? result : resultr;
}

int Astar(int departure, int destination, int k, vector<int>& dist1, vector<int>& dist2)//dijstra
{
	LineHeap h;//堆
	Line l;//Line.departure是当前节点,Line.cost是当前节点到出发地和目的地的总距离
	for (int i = 0; i < 34; i++)
	{
		l.departure = i;
		l.cost = dist1[i] + dist2[i];//从出发地到该节点的权值+从目的地到该节点的权值
		if (i == departure || i == destination)
		{
			continue;
		}
		h.Insert(l);//将该节点插入堆
	}
	for (int i = 0; i < k; i++)
	{
		h.RemoveMin(l);//取总权值第k小的节点
	}
	return l.departure;
}
vector<Line> AstraPath(Graph<string, int>& G, int departure, int destination, int k, int avoid)
{
	vector<int> dist1;
	vector<int> dist2;
	vector<int> path1;
	vector<int> path2;
	Dijkstra(G, departure, dist1, path1, avoid);
	Dijkstra(G, destination, dist2, path2, avoid);
	vector<Line> temp = DijkstraPath(G, departure, destination);
	int city = Astar(departure, destination, k + temp.size() - 2, dist1, dist2);
	int n = G.numVertexs;
	vector<Line> vec;
	vector<Line> vec2;
	Line l;

	//departure-city
	int precity = city;
	l.destination = precity;
	for (size_t i = 0; i < n; i++)
	{
		if (path1[precity] == -1)
		{
			l.departure = precity;
			break;
		}
		l.departure = path1[precity];
		vec2.push_back(l);
		precity = l.departure;
		l.destination = precity;
	}
	for (int i = vec2.size() - 1; i >= 0; i--)
	{
		vec.push_back(vec2[i]);
	}
	vec[0].cost += dist1[city];

	//city-destination(实际上是destination-city)
    precity = city;
	l.departure = precity;
	for (size_t i = 0; i < n; i++)
	{
		if (path2[precity] == -1)
		{
			l.destination = precity;
			break;
		}
		l.destination = path2[precity];
		vec.push_back(l);
		precity = l.destination;
		l.departure = precity;
	}
	vec[0].cost += dist2[city];

	return vec;
}
int Astar(int departure, int destination, int k, int dist[34][34])//floyd
{
	int city;
	int G[34];
	int H[34];
	LineHeap h;//Line.departure是当前节点,Line.cost是当前节点到出发地和目的地的总距离
	Line l;
	for (int i = 0; i < 34; i++)
	{
		l.departure = i;
		l.cost = dist[departure][i] + dist[destination][i];
		h.Insert(l);
	}
	for (int i = 0; i < k; i++)
	{
		h.RemoveMin(l);
	}
	return l.departure;
}