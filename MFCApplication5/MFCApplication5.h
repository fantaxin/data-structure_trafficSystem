
// MFCApplication5.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主符号
//#include<string>
//#include<iostream>
//#include<vector>
//#include<fstream>
//#include<iomanip>
//#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include"Graph.h"
#include"Line.h"
#include"BT.h"
#include"MinHeap.h"
using namespace std;
// CMFCApplication5App:
// 有关此类的实现，请参阅 MFCApplication5.cpp
//

class CMFCApplication5App : public CWinApp
{
public:
	CMFCApplication5App();
// 重写
public:
	virtual BOOL InitInstance();

	Graph<string, int> G;
// 实现
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication5App theApp;

//将CString转化成string类型
string CSTS(CString cstr);
//将多字节字符转换为宽字节字符
LPCWSTR StringToLPCWSTR(string str);
//将宽字节字符转换为多字节字符
string LPCWSTRToString(LPCWSTR wstr);
//将int类型转化为CString类型
CString int2cstring(int);
//将double类型转化为CString类型
CString double2cstring(double);
//将double类型转化为string类型
string double2string(double);
//将CString类型转化为double类型
double cstring2double(CString cstr);
//将string类型转化为double类型
double string2double(string);
vector<Line> DFS(Graph<string,int>& G, const int&departure);
void DFS(Graph<string,int>& G, int departure, bool visited[], vector<Line>&);
vector<Line> BFS(Graph<string, int>& G, const int&departure);
vector<Line> Kruskal(Graph<string, int>& G);
vector<Line> Prim(Graph<string, int>& G,int);
vector<vector<Line>> AllPath(Graph<string, int>&G, int departure, int destination);
vector<Line> Stack2vec(Graph<string, int>& G,stack<int>);
void QuickSort(vector<vector<Line>> &a, int left, int right);
void QuickSort(vector<Line> &a, int left, int right);
void Dijkstra(Graph<string, int>& G, int departure, vector<int>& dist, vector<int>& path,int avoid=INT_MAX);
vector<Line> DijkstraPath(Graph<string, int>& G, int departure, int destination,int avoid=INT_MAX);
void Floyd(Graph<string, int>& G, int dist[34][34], int path[34][34], int avoid = INT_MAX);
void FloydPath(int departure, int destination, int path[34][34], vector<Line>& vec);
vector<int> Height(vector<Line> l);
void Height_Insert(BT<int> tree, Line l);
BTNode<int>* Height_BTBFS(BT<int> tree, int data);
vector<int> Height_Max(BTNode<int>* root);
int Astar(int departure, int destination, int k, int[34][34]);
int Astar(int departure, int destination, int k, vector<int>& dist1, vector<int>& dist2);
vector<Line> AstraPath(Graph<string, int>& G, int departure, int destination, int k, int avoid = INT_MAX);