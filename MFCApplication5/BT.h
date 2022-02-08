#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
struct BTNode
{
	T data;
	BTNode<T> *lChild, *rChild;
	BTNode() : lChild(NULL), rChild(NULL) {}
	BTNode(T x, BTNode<T> *l = NULL, BTNode<T> *r = NULL)
		: data(x), lChild(l), rChild(r) {}
};
template <typename T>
class BT
{
public:
	BTNode<T> *root;

public:
	//vector<T> pre;
	//vector<T> in;
	BT() { root = NULL; }
	//BT(vector<T> vec1, vector<T> vec2);
	BT(T data) { root = new BTNode<T>(data); }
	BTNode<T> *Root() const { return root; }
	//BTNode<T> *Parent(BTNode<T> *current, BTNode<T> *subTree = root);
	//BTNode<T> *LChild(BTNode<T> *current);
	//BTNode<T> *RChild(BTNode<T> *current);
	//bool isEmpty() { return (root == NULL) ? true : false; }
	//bool Insert(BTNode<T> *&subTree, const T &x);
	//void preOrder();
	//void preOrder(BTNode<T> *subTree);
	//void inOrder();
	//void inOrder(BTNode<T> *subTree);
	//void postOrder();
	//void postOrder(BTNode<T> *subTree);
	//void printTree();
	//void printTree(BTNode<T> *subTree, int n);
	//BTNode<T> *CreatBT(vector<T>, vector<T>, int);
	//friend ostream &operator<<(ostream &os, BT<T> &t)//输出运算符重载
	//{
	//	os << "Preorder:";
	//	t.preOrder();
	//	os << endl;
	//	os << "Inorder:";
	//	t.inOrder();
	//	os << endl;
	//	os << "Postorder:";
	//	t.postOrder();
	//	os << endl;
	//	os << "BinaryTree:" << endl;
	//	t.printTree();
	//	return os;
	//}
	//friend istream &operator>>(istream &is, BT<T> &t)//输入运算符重载
	//{
	//	T one_data;
	//	string data;
	//	getline(is, data);//读入整行数据
	//	stringstream pre_data(data);//采用输入输出流输入一行中的每个元素
	//	while (pre_data >> one_data)
	//	{
	//		t.pre.push_back(one_data);//保存
	//	}
	//	data = ' ';
	//	getline(is, data);
	//	stringstream in_data(data);
	//	while (in_data >> one_data)
	//	{
	//		t.in.push_back(one_data);
	//	}
	//	t.root = t.CreatBT(t.pre, t.in, t.in.size());
	//	return is;
	//}
};
//template <typename T>
//BT<T>::BT(vector<T> pre1, vector<T> in1)
//{
//	pre = pre1;
//	in = in1;
//	int n = in.size();
//	root = CreatBT(pre1, in1, n);
//}
//template <typename T>
//BTNode<T> *BT<T>::Parent(BTNode<T> *current, BTNode<T> *subTree)
//{
//	if (subTree == NULL || subTree == current)
//		return NULL;
//	if (subTree->lChild == current || subTree->rChild == current)
//		return root;
//	BTNode<T> *p;
//	p = Parent(current, subTree->lChild);
//	return (p != NULL) ? p : Parent(current, subTree->rChild);
//}
//template <typename T>
//BTNode<T> *BT<T>::LChild(BTNode<T> *current)
//{
//	return (current == NULL) ? NULL : current->lChild;
//}
//template <typename T>
//BTNode<T> *BT<T>::RChild(BTNode<T> *current)
//{
//	return (current == NULL) ? NULL : current->rChild;
//}
//template <typename T>
//bool BT<T>::Insert(BTNode<T> *&subTree, const T &x)
//{
//	if (subTree = new BTNode<T>(x))
//	{
//		return true;
//	}
//	return false;
//}
//template <typename T>
//void BT<T>::printTree()
//{
//	int n = 0;//递归的层数
//	if (root->rChild != NULL)
//	{
//		printTree(root->rChild, n);
//	}
//	cout << root->data << endl;
//	if (root->lChild != NULL)
//	{
//		printTree(root->lChild, n);
//	}
//}
//template <typename T>
//void BT<T>::printTree(BTNode<T> *subTree, int n)
//{
//	n++;
//	if (subTree->rChild != NULL)
//		printTree(subTree->rChild, n);
//	cout << ' ';
//	for (int i = 1; i < n; i++)
//	{
//		cout << "   ";
//	}
//	cout << "**";
//	cout << subTree->data << endl;
//	if (subTree->lChild != NULL)
//		printTree(subTree->lChild, n);
//	return;
//}
//template <typename T>
//void BT<T>::preOrder()
//{
//	cout << root->data << ' ';
//	if (root->lChild != NULL)
//		preOrder(root->lChild);
//	if (root->rChild != NULL)
//		preOrder(root->rChild);
//	return;
//}
//template <typename T>
//void BT<T>::preOrder(BTNode<T> *subTree)
//{
//	cout << subTree->data << ' ';
//	if (subTree->lChild != NULL)
//		preOrder(subTree->lChild);
//	if (subTree->rChild != NULL)
//		preOrder(subTree->rChild);
//	return;
//}
//template <typename T>
//void BT<T>::inOrder()
//{
//	if (root->lChild != NULL)
//		inOrder(root->lChild);
//	cout << root->data << ' ';
//	if (root->rChild != NULL)
//		inOrder(root->rChild);
//	return;
//}
//template <typename T>
//void BT<T>::inOrder(BTNode<T> *subTree)
//{
//	if (subTree->lChild != NULL)
//		inOrder(subTree->lChild);
//	cout << subTree->data << ' ';
//	if (subTree->rChild != NULL)
//		inOrder(subTree->rChild);
//	return;
//}
//template <typename T>
//void BT<T>::postOrder()
//{
//	if (root->lChild != NULL)
//		postOrder(root->lChild);
//	if (root->rChild != NULL)
//		postOrder(root->rChild);
//	cout << root->data << ' ';
//	return;
//}
//template <typename T>
//void BT<T>::postOrder(BTNode<T> *subTree)
//{
//	if (subTree->lChild != NULL)
//		postOrder(subTree->lChild);
//	if (subTree->rChild != NULL)
//		postOrder(subTree->rChild);
//	cout << subTree->data << ' ';
//	return;
//}
//template <typename T>
//BTNode<T> *BT<T>::CreatBT(vector<T> pre, vector<T> in, int n)
//{
//	BTNode<T> *root1 = NULL;//新树的根节点
//	int root_local = 0;
//	if (n != 0)
//	{
//		while (in[root_local] != pre[0])
//		{
//			root_local++;
//		}
//		root1 = new BTNode<T>(pre[0]);
//		vector<T> npre1(pre.begin() + 1, pre.end());//分割vector
//		root1->lChild = CreatBT(npre1, in, root_local);//根节点的子树作为新的树创建
//		vector<T> npre(pre.begin() + root_local + 1, pre.end());
//		vector<T> nin(in.begin() + root_local + 1, in.end());
//		root1->rChild = CreatBT(npre, nin, n - root_local - 1);
//	}
//	return root1;//返回根节点
//}
