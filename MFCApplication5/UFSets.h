#pragma once
class UFSets
{
public:
	UFSets(int sz = 30);
	~UFSets() { delete[]parent; }
	void Union(int Root1, int Root2);
	int Find(int x);
private:
	int* parent;//并查集数据数组
	int size;//并查集大小
};
UFSets::UFSets(int sz)
{
	size = sz;
	parent = new int[size];
	for (int i = 0; i < size; i++)
	{
		parent[i] = -1;
	}
}
int UFSets::Find(int x)
{
	while (parent[x] >= 0)
	{
		x = parent[x];
	}
	return x;
}
void UFSets::Union(int Root1, int Root2)
{
	parent[Root1] += parent[Root2];
	parent[Root2] = Root1;
}