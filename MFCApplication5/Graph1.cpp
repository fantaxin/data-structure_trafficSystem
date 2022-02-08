#include "pch.h"
//
//#include"MFCApplication5.h"
//
//template<class T, class E>
//Graph<T, E>::Graph(int sz)
//{
//	for (auto &row : Matrix)
//	{
//		for (auto &line : row)
//		{
//			line = INT_MAX;
//		}
//	}
//}
//
//template<class T, class E>
//Graph<T, E>::Graph(T data[], int sz)
//{
//	numEdges = 0;
//	numVertexs = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		Node[i].data = data[i];
//	}
//	for (auto &row : Matrix)
//	{
//		for (auto &line : row)
//		{
//			line = INT_MAX;
//		}
//	}
//}
//template<class T, class E>
//void Graph<T, E>::CreatG(T data, int dest, E cost)
//{
//	int local = getVertexPos(data);
//	Matrix[local][dest] = cost;
//	Line l;
//	l.departure = local;
//	l.destination = dest;
//	allLine.push_back(l);
//	numEdges++;
//}
//template<class T, class E>
//void Graph<T, E>::CreatG(int data, int dest, E cost)
//{
//	Matrix[data][dest] = cost;
//	Line l;
//	l.departure = data;
//	l.destination = dest;
//	allLine.push_back(l);
//	numEdges++;
//}
//template<class T, class E>
//bool Graph<T, E>::Insert(T data, int x, int y)
//{
//	if (numVertexs >= sz)
//		return false;
//	NodeTable[numVertexs].data = data;
//	NodeTable[numVertexs].x = x;
//	NodeTable[numVertexs].y = y;
//	numVertexs++;
//	return true;
//}
//template<class T, class E>
//void Graph<T, E>::readfile()
//{
//	string cityName[34];
//	int cityLine[34][34];//城市之间是否连通
//	int cityDistance[34][34];
//	ifstream cityfile("data\\city.txt");
//	ifstream distancefile("data\\distance.txt");
//	ifstream mapfile("data\\map.txt");
//	string linedata;
//
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
//
//	//读取城市距离
//	int row1 = -1;
//	while (getline(distancefile, linedata))
//	{
//		stringstream data(linedata);
//		string name;
//
//		//读取城市距离矩阵
//		if (row1 != -1)
//		{
//			int line1 = 0;//相当于列
//			data >> name;
//			while (data >> name)
//			{
//				cityDistance[row1][line1] = string2double(name);
//				line1++;
//			}
//		}
//		row1++;
//	}
//
//	//读取城市邻接矩阵
//	int row = -1;//行
//	while (getline(cityfile, linedata))
//	{
//		stringstream data(linedata);
//		string name;
//
//		if (row != -1)
//		{
//			int line = 0;//相当于列
//			data >> name;
//			while (data >> name)
//			{
//				cityLine[row][line] = string2double(name);
//				if (string2double(name) == 1 && line < row)//如果值为0说明两城市没有直接连接
//				{
//					CreatG(row, line, cityDistance[row][line]);
//					CreatG(line, row, cityDistance[row][line]);
//				}
//				line++;
//			}
//		}
//		row++;
//	}
//}
//template<class T, class E>
//int Graph<T, E>::getFirstNeighbor(int v)
//{
//	if (v != -1)
//	{
//		for (int line = 0; line < numVertexs; line++)
//		{
//			int value = Matrix[v][line];
//			if (value > 0 && value < (INT_MAX / 10000))
//			{
//				return line;
//			}
//		}
//	}
//	return -1;
//}
//
////取v的邻接顶点w的下一邻接顶点位置
//template<class T, class E>
//int Graph<T, E>::getNextNeighbor(int v, int w)
//{
//	if (v != -1)
//	{
//		for (int line = w + 1; line < numVertexs; line++)
//		{
//			int value = Matrix[v][line];
//			if (value > 0 && value < (INT_MAX / 10000))
//			{
//				return line;
//			}
//		}
//	}
//	return -1;
//}
//template<class T, class E>
//E Graph<T, E>::getWeight(int v1, int v2, int avoid)
//{
//	if (v1 == avoid || v2 == avoid)
//		return INT_MAX;
//	if (v1 != -1 && v2 != -1)
//	{
//		return Matrix[v1][v2];
//	}
//	return INT_MAX;
//}