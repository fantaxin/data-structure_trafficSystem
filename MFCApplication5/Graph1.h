//#include"Line.h"
//#include<string>
//#include<iostream>
//#include<vector>
//#include<fstream>
//#include<iomanip>
//#include<sstream>
//using namespace std;
//template<class T, class E>
//struct Vertex
//{
//	Vertex() {}
//	Vertex(T d) { data = d; }
//	int x = 0;
//	int y = 0;
//	T data;
//};
//template<class T, class E>
//class Graph
//{
//public:
//	int sz = 34;
//	int numEdges;
//	int numVertexs;
//	
//	Vertex<T, E> NodeTable[34];
//	E Matrix[34][34];
//
//	vector<Line> allLine;
//	int getVertexPos(const T vertex)
//	{
//		for (int i = 0; i < numVertexs; i++)
//		{
//			if (NodeTable[i].data == vertex)
//				return i;
//		}
//		return -1;
//	}
//	Graph(int sz = 34);
//	Graph(T data[], int sz = 34);
//	bool Insert(T data, int x, int y);//插入节点
//	void CreatG(T data, int dest, E cost);//插入边
//	void CreatG(int local, int dest, E cost);
//	T getValue(int i)
//	{
//		return(i >= 0 && i < numVertexs) ? Node[i].data : 0;
//	}
//	void readfile();
//	int getFirstNeighbor(int v);
//	int getNextNeighbor(int v, int w);
//	E getWeight(int, int, int avoid = INT_MAX);
//};
//
