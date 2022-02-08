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
	int dest;//�ߵ���һ�����λ��
	E cost = INT_MAX;//�ߵ�Ȩֵ
	Edge<T, E>* link = NULL;//��һ����
	Edge(){}
	Edge(int num, E weight) :dest(num), cost(weight), link(NULL){}
};
template<class T,class E>
struct Vertex
{
	Vertex(){}
	Vertex(T d) { data = d; }
	int x = 0;//�ڵ��x����
	int y = 0;//�ڵ��y����
	int flag = 0;//���
	T data;//�ڵ�����
	Edge<T, E>* adj = NULL;//������ͷָ��
	Edge<T, E>* last = NULL;//������βָ��
	void Creat(int dest, E cost);
};
template<class T,class E>
class Graph
{
public:
	int sz = 34;//�ڵ����鳤��
	int numEdges;//����
	int numVertexs;//�ڵ���
	Vertex<T, E>* NodeTable;//�ڵ�����
	vector<Line> allLine;//ͼ������·����Ϣ
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
	bool Insert(T data, int x, int y);//����ڵ�
	void CreatG(T data, int dest, E cost);//�����
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