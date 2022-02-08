#include "pch.h"

#include"MFCApplication5.h"

template<class T, class E>
Graph<T, E>::Graph(int sz)
{
	numEdges = 0;
	numVertexs = 0;
	NodeTable = new Vertex<T, E>[sz];
}
template<class T, class E>
Graph<T, E>::Graph(T data[], int sz)
{
	numEdges = 0;
	numVertexs = 0;
	NodeTable = new Vertex<T, E>[sz];
	for (int i = 0; i < sz; i++)
	{
		NodeTable[i].data = data[i];
	}
}
template<class T, class E>
//�������
void Vertex<T, E>::Creat(int dest, E cost)
{
	if (adj == NULL)
	{
		adj = new Edge<T, E>;
		adj->cost = cost;
		adj->dest = dest;
	}
	else
	{
		Edge<T, E>* temp = new Edge<T, E>;
		temp->cost = cost;
		temp->dest = dest;
		temp->link = adj->link;
		adj->link = temp;
	}
}
template<class T, class E>
void Graph<T, E>::CreatG(T data, int dest, E cost)
{
	int local = getVertexPos(data);
	NodeTable[local].Creat(dest, cost);
	Line l;
	l.departure = local;
	l.destination = dest;
	allLine.push_back(l);
	numEdges++;
}
template<class T, class E>
void Graph<T, E>::CreatG(int data, int dest, E cost)
{
	NodeTable[data].Creat(dest, cost);
	Line l;
	l.departure = data;
	l.destination = dest;
	allLine.push_back(l);
	numEdges++;
}
template<class T, class E>
bool Graph<T, E>::Insert(T data, int x, int y)
{
	if (numVertexs >= sz)
		return false;
	NodeTable[numVertexs].data = data;
	NodeTable[numVertexs].x = x;
	NodeTable[numVertexs].y = y;
	numVertexs++;
	return true;
}
template<class T, class E>
void Graph<T, E>::readfile()
{
	//��ȡ�ļ���Ϣ������ͼ
	string cityName[34];//������
	int cityLine[34][34];//�����ڽӾ���
	int cityDistance[34][34];//���о������
	ifstream cityfile("data\\city.txt");//���ļ�
	ifstream distancefile("data\\distance.txt");
	ifstream mapfile("data\\map.txt");
	string linedata;//�ļ��е�һ������

	//��ȡ������Ϣ
	while (getline(mapfile, linedata))
	{
		if (linedata == "#END")
		{
			break;
		}
		stringstream data(linedata);
		string name, x, y;
		data >> name >> x >> y;
		Insert(name, string2double(x), string2double(y));//����ͼ
	}

	//��ȡ���о���
	int row1 = -1;
	while (getline(distancefile, linedata))
	{
		stringstream data(linedata);
		string name;

		//��ȡ���о������
		if (row1 != -1)
		{
			int line1 = 0;//�൱����
			data >> name;
			while (data >> name)
			{
				cityDistance[row1][line1] = string2double(name);
				line1++;
			}
		}
		row1++;
	}

	//��ȡ�����ڽӾ���
	int row = -1;//��
	while (getline(cityfile, linedata))
	{
		stringstream data(linedata);
		string name;
		if (row != -1)
		{
			int line = 0;//��
			data >> name;
			while (data >> name)
			{
				cityLine[row][line] = string2double(name);
				if (string2double(name) == 1 && line < row)//���ֵΪ0˵��������û��ֱ������
				{
					CreatG(row, line, cityDistance[row][line]);//����ͼ��˫��·��
					CreatG(line, row, cityDistance[row][line]);
				}
				line++;
			}
		}
		row++;
	}
}
//template<class T, class E>
//void Graph<T, E>::readfile()
//{
//	ifstream mapfile("data\\map.txt");
//	ifstream edgefile("data\\edge.txt");
//	string linedata;
//	while (getline(mapfile, linedata))
//	{
//		if (linedata == "#END")
//		{
//			break;
//		}
//		stringstream data(linedata);
//		string name, x, y;
//		data >> name >> x >> y;
//		Insert(name, string2double(x), string2double(y));
//	}
//	while (getline(edgefile, linedata))
//	{
//		if (linedata == "#END")
//		{
//			break;
//		}
//		stringstream data(linedata);
//		string local, dest, cost;
//		data >> local >> dest >> cost;
//		CreatG(string2double(local), string2double(dest), string2double(cost));
//	}
//}
template<class T, class E>
int Graph<T, E>::getFirstNeighbor(int v) 
{
	if (v != -1) 
	{
		Edge<T, E>*p = NodeTable[v].adj;
		if (p != NULL)return p->dest;
	}
	return -1;
}

//ȡv���ڽӶ���w����һ�ڽӶ���λ��
template<class T, class E>
int Graph<T, E>::getNextNeighbor(int v, int w) 
{
	if (v != -1) 
	{
		Edge<T, E>*p = NodeTable[v].adj;
		while (p != NULL && p->dest != w)
			p = p->link;
		if (p != NULL && p->link != NULL)
			return p->link->dest;
	}
	return -1;
}
template<class T, class E>
E Graph<T, E>::getWeight(int v1, int v2, int avoid)
{
	if (v1 == avoid || v2 == avoid)
		return INT_MAX;
	if (v1 != -1 && v2 != -1)
	{
		Edge<T, E>* p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
			p = p->link;
		if (p != NULL)
			return p->cost;
	}
	return INT_MAX;
}