
// MFCApplication5Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "afxdialogex.h"
#include "Deep.cpp"
#include <windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int departure = 0;
int destination = 1;
int no_k = 1;
int avoid = INT_MAX;

int time1 = 10;//显示图的构建过程的时间间隔(ms)
int time2 = 10;//显示各算法过程的时间间隔(ms)

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 对话框



CMFCApplication5Dlg::CMFCApplication5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION5_DIALOG, pParent)
	, m_distance(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_departure);
	DDX_Control(pDX, IDC_COMBO2, m_destination);
	DDX_Text(pDX, IDC_EDIT1, m_distance);
	DDX_Control(pDX, IDC_COMBO3, m_avoid);
	DDX_Control(pDX, IDC_COMBO4, No_k);
}

BEGIN_MESSAGE_MAP(CMFCApplication5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication5Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication5Dlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication5Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication5Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication5Dlg::OnBnClickedButton3)
	ON_CBN_EDITCHANGE(IDC_COMBO1, &CMFCApplication5Dlg::OnCbnEditchangeCombo1)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &CMFCApplication5Dlg::OnCbnKillfocusCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication5Dlg::OnCbnSelchangeCombo2)
	ON_CBN_EDITCHANGE(IDC_COMBO2, &CMFCApplication5Dlg::OnCbnEditchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication5Dlg::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CMFCApplication5Dlg::OnCbnSelchangeCombo3)
	ON_CBN_EDITCHANGE(IDC_COMBO3, &CMFCApplication5Dlg::OnCbnEditchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication5Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication5Dlg::OnBnClickedButton6)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CMFCApplication5Dlg::OnCbnSelchangeCombo4)
	ON_CBN_EDITCHANGE(IDC_COMBO4, &CMFCApplication5Dlg::OnCbnEditchangeCombo4)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 消息处理程序

BOOL CMFCApplication5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	for (int i = 0; i < theApp.G.numVertexs; i++)
	{
		m_departure.InsertString(i, StringToLPCWSTR(theApp.G.NodeTable[i].data));
		m_destination.InsertString(i, StringToLPCWSTR(theApp.G.NodeTable[i].data));
		m_avoid.InsertString(i, StringToLPCWSTR(theApp.G.NodeTable[i].data));
		if (i < 5)
		{
			No_k.InsertString(i, double2cstring(i + 1));
		}
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CPaintDC  dc(this);
		CRect  rect;
		GetClientRect(&rect); //得到客户端的大小;      
		CBitmap  bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1);
		BITMAP  bitmap;
		bmpBackground.GetBitmap(&bitmap);  //得到位图信息
		CDC  dcMem;
		dcMem.CreateCompatibleDC(&dc);//创建内存DC;
		CBitmap  *pbmpOld = dcMem.SelectObject(&bmpBackground); //选择位图，将其装入内存设备上下文;
		dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);
		dcMem.SelectObject(pbmpOld);//将原来的位图重新载入
		dcMem.DeleteDC();//删除内存DC
	}


	CClientDC dc(this); 
	CDialog::OnPaint();
	CPoint start;
	CPoint end;
	CPen cPen;
	cPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&cPen);
	Edge<string, int>* temp = NULL;
	for (int i = 0; i < theApp.G.numVertexs; i++)//theApp.G.numVertexs,numEdges
	{
		start.x = theApp.G.NodeTable[i].x;
		start.y = theApp.G.NodeTable[i].y;
		temp = theApp.G.NodeTable[i].adj;
		while (temp != NULL)
		{
			Sleep(time1);
			int local = temp->dest;
			end.x = theApp.G.NodeTable[local].x;
			end.y = theApp.G.NodeTable[local].y;
			dc.MoveTo(start);
			dc.LineTo(end);
			temp = temp->link;
		}
		//start.x = theApp.G.NodeTable[theApp.G.allLine[i].departure].x;
		//start.y = theApp.G.NodeTable[theApp.G.allLine[i].departure].y;
		//end.x = theApp.G.NodeTable[theApp.G.allLine[i].destination].x;
		//end.y = theApp.G.NodeTable[theApp.G.allLine[i].destination].y;
		//dc.MoveTo(start);
		//dc.LineTo(end);
	}
}



//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication5Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (departure < 0 || destination < 0 || avoid < 0)
	{
		MessageBox(L"未找到该城市，请重新输入！", TEXT("ERROR!"), MB_OK | MB_ICONERROR);
		return;
	}
	if (departure == destination)
	{
		MessageBox(L"出发地和目的地一致，请重新输入！", TEXT("ERROR!"), MB_OK | MB_ICONERROR);
		return;
	}
	if (no_k < 1 || no_k > 5)
	{
		MessageBox(L"请输入1-34之间的数字！", TEXT("ERROR!"), MB_OK | MB_ICONERROR);
		return;
	}
	//MessageBox(StringToLPCWSTR(theApp.G.getValue(departure)));
	//MessageBox(StringToLPCWSTR(theApp.G.getValue(destination)));
	DrowLine(theApp.G.allLine,0);
	int local1 = departure;
	int local2 = destination;
	vector<Line> vec;
	//FLOYD
	//int dist[34][34];
	//int path[34][34];
	//Floyd(theApp.G, dist, path,avoid);
	//FloydPath(local1, local2, path, vec);
	//vec[0].cost = dist[local1][local2];;
	//FLOYD

	if (no_k == 1)
	{
		//DIJKSTRA
		vec = DijkstraPath(theApp.G, local1, local2, avoid);
		//DIJKSTRA
	}
	else
	{
		//Astra
		vec = AstraPath(theApp.G, local1, local2, no_k, avoid);
		//Astra
	}

	CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	CPoint start;
	CPoint end;
	for (size_t i = 0; i < vec.size(); i++)
	{
		//MessageBox(StringToLPCWSTR(theApp.G.NodeTable[vec[i].destination].data));
		start.x = theApp.G.NodeTable[vec[i].departure].x;
		start.y = theApp.G.NodeTable[vec[i].departure].y;
		end.x = theApp.G.NodeTable[vec[i].destination].x;
		end.y = theApp.G.NodeTable[vec[i].destination].y;
		//dc.SetROP2(R2_XORPEN);
		dc.MoveTo(start);
		dc.LineTo(end);
		Sleep(time2);
	}
	m_distance = (int2cstring(vec[0].cost));
	UpdateData(FALSE);
}

void CMFCApplication5Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (departure < 0)
	{
		MessageBox(L"未找到该城市，请重新输入！", TEXT("ERROR!"), MB_OK | MB_ICONERROR);
		return;
	}
	DrowLine(theApp.G.allLine, 0);
	int local = departure;
	vector<Line> vec = DFS(theApp.G, local);
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	CPoint start;
	CPoint end;
	for (int i = 0; i < vec.size(); i++)
	{
		start.x = theApp.G.NodeTable[vec[i].departure].x;
		start.y = theApp.G.NodeTable[vec[i].departure].y;
		end.x = theApp.G.NodeTable[vec[i].destination].x;
		end.y = theApp.G.NodeTable[vec[i].destination].y;
		//dc.SetROP2(R2_XORPEN);
		dc.MoveTo(start);
		dc.LineTo(end);
		Sleep(time2);
	}
}

void CMFCApplication5Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//num++;
	if (departure < 0)
	{
		MessageBox(L"未找到该城市，请重新输入！", TEXT("ERROR!"), MB_OK | MB_ICONERROR);
		return;
	}
	DrowLine(theApp.G.allLine, 0);
	int local = departure;
	vector<Line> vec = BFS(theApp.G, local);
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	CPoint start;
	CPoint end;
	for (int i = 0; i < vec.size(); i++)
	{
		start.x = theApp.G.NodeTable[vec[i].departure].x;
		start.y = theApp.G.NodeTable[vec[i].departure].y;
		end.x = theApp.G.NodeTable[vec[i].destination].x;
		end.y = theApp.G.NodeTable[vec[i].destination].y;
		//dc.SetROP2(R2_XORPEN);
		dc.MoveTo(start);
		dc.LineTo(end);
		Sleep(time2);
	}
}

void CMFCApplication5Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//num++;
	//vector<Line> vec = Prim(theApp.G, departure);
	vector<Line> vec = Kruskal(theApp.G);
	DrowLine(theApp.G.allLine, 0);
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	CPoint start;
	CPoint end;
	for (int i = 0; i < vec.size(); i++)
	{
		start.x = theApp.G.NodeTable[vec[i].departure].x;
		start.y = theApp.G.NodeTable[vec[i].departure].y;
		end.x = theApp.G.NodeTable[vec[i].destination].x;
		end.y = theApp.G.NodeTable[vec[i].destination].y;
		//dc.SetROP2(R2_XORPEN);
		dc.MoveTo(start);
		dc.LineTo(end);
		Sleep(time2);
	}
}

void CMFCApplication5Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	vector<Line> vec = Prim(theApp.G, departure);
	//vector<Line> vec = Kruskal(theApp.G);
	DrowLine(theApp.G.allLine, 0);
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	CPoint start;
	CPoint end;
	for (int i = 0; i < vec.size(); i++)
	{
		start.x = theApp.G.NodeTable[vec[i].departure].x;
		start.y = theApp.G.NodeTable[vec[i].departure].y;
		end.x = theApp.G.NodeTable[vec[i].destination].x;
		end.y = theApp.G.NodeTable[vec[i].destination].y;
		//dc.SetROP2(R2_XORPEN);
		dc.MoveTo(start);
		dc.LineTo(end);
		Sleep(time2);
	}
}


void CMFCApplication5Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	departure = m_departure.GetCurSel();//获取选择的下拉框的值的序号
}

void CMFCApplication5Dlg::OnCbnEditchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString cstr;
	GetDlgItem(IDC_COMBO1)->GetWindowText(cstr);
	int local = theApp.G.getVertexPos(CSTS(cstr));
	departure = local;
}

void CMFCApplication5Dlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	destination = m_destination.GetCurSel();//获取选择的下拉框的值的序号
}

void CMFCApplication5Dlg::OnCbnEditchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString cstr;
	GetDlgItem(IDC_COMBO2)->GetWindowText(cstr);
	int local = theApp.G.getVertexPos(CSTS(cstr));
	destination = local;
}

void CMFCApplication5Dlg::DrowLine(vector<Line> vec,int a)
{
	CPen pen(PS_SOLID, 1, RGB(a, a, a));
	CClientDC dc(this);
	CPen* pOldPen = dc.SelectObject(&pen);
	CPoint start;
	CPoint end;
	for (size_t i = 0; i < vec.size(); i++)
	{
		start.x = theApp.G.NodeTable[vec[i].departure].x;
		start.y = theApp.G.NodeTable[vec[i].departure].y;
		end.x = theApp.G.NodeTable[vec[i].destination].x;
		end.y = theApp.G.NodeTable[vec[i].destination].y;
		dc.MoveTo(start);
		dc.LineTo(end);
	}
}

void CMFCApplication5Dlg::OnCbnKillfocusCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	//CString cstr;
	//GetDlgItem(IDC_COMBO1)->GetWindowText(cstr);
	//int local = theApp.G.getVertexPos(CSTS(cstr));
	////if (local < 0)
	////{
	////	MessageBox(L"未找到该城市！", TEXT("ERROR!"), MB_OK | MB_ICONERROR);
	////	return;
	////}
	//departure = local;
}


void CMFCApplication5Dlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	avoid = m_avoid.GetCurSel();//获取选择的下拉框的值的序号
}


void CMFCApplication5Dlg::OnCbnEditchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString cstr;
	GetDlgItem(IDC_COMBO3)->GetWindowText(cstr);
	int local = theApp.G.getVertexPos(CSTS(cstr));
	avoid = local;
}


void CMFCApplication5Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int local = departure;
	vector<Line> l = BFS(theApp.G, local);
	vector<int> vec;
	vec = Height(l);
	string s;

	s += "全国所有其它省会城市到";
	s += theApp.G.getValue(local);
	s += "中间最多要经过";
	s += vec[0] + 46;
	s += "个城市";
	s += 10;//换行符
	s += "这些省会城市分别为:";
	s += 10;

	for (int i = 1; i < vec.size(); i++)
	{
		s += theApp.G.getValue(vec[i]) + ' ';
	}
	MessageBox(StringToLPCWSTR(s), StringToLPCWSTR("0oO"));
}


void CMFCApplication5Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	int local1 = departure;
	int local2 = destination;
	vector<vector<Line>> vec = AllPath(theApp.G, local1, local2);
	vector<Line> line;
	ofstream file("data\\AllPath.txt");
	for (int i = 0; i < vec.size(); i++)
	{
		line = vec[i];
		file << theApp.G.getValue(line[1].departure);
		for (int n = 1; n < line.size(); n++)
		{
			string city_name = theApp.G.getValue(line[n].destination);
			file <<"->"<< city_name;
		}
		file << line[0].cost << "km";
		file << endl;
	}

}


void CMFCApplication5Dlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	no_k = No_k.GetCurSel()+1;//获取选择的下拉框的值的序号
}


void CMFCApplication5Dlg::OnCbnEditchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString cstr;
	GetDlgItem(IDC_COMBO3)->GetWindowText(cstr);
	no_k = cstring2double(cstr)+1;
}
