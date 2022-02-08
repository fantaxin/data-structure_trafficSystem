#include"Line.h"
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<sstream>
using namespace std;
template<class T,class E>
struct Edge
{
	int dest;//边的另一顶点的位置
	E cost = INT_MAX;//边的权值
	Edge<T, E>* link = NULL;//下一条边
	Edge(){}
	Edge(int num, E weight) :dest(num), cost(weight), link(NULL){}
};
template<class T,class E>
struct Vertex
{
	Vertex(){}
	Vertex(T d) { data = d; }
	int x = 0;//节点的x坐标
	int y = 0;//节点的y坐标
	int flag = 0;//标记
	T data;//节点数据
	Edge<T, E>* adj = NULL;//边链表头指针
	Edge<T, E>* last = NULL;//边链表尾指针
	void Creat(int dest, E cost);
};
template<class T,class E>
class Graph
{
public:
	int sz = 34;//节点数组长度
	int numEdges;//边数
	int numVertexs;//节点数
	Vertex<T, E>* NodeTable;//节点数组
	vector<Line> allLine;//图的所有路径信息
	int getVertexPos(const T vertex)
	{
		for (int i = 0; i < numVertexs; i++)
		{
			if (NodeTable[i].data == vertex)
				return i;
		}
		return -1;
	}
	Graph(int sz = 34);
	Graph(T data[], int sz = 34);
	bool Insert(T data, int x, int y);//插入节点
	void CreatG(T data, int dest, E cost);//插入边
	void CreatG(int local, int dest, E cost);
	T getValue(int i)
	{
		return(i >= 0 && i < numVertexs) ? NodeTable[i].data:0;
	}
	void readfile();
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	E getWeight(int, int, int avoid = INT_MAX);
};