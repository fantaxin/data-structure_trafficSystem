#pragma once
#include"Line.h"
class LineHeap
{
public:
	LineHeap(int sz = 34);  //构造函数
	bool Insert(const Line& x);  //将x插入最小堆中
	bool RemoveMin(Line& x);  //删除堆顶最小元素
	bool IsEmpty()const { return(currentSize == 0) ? true : false; }  //判断堆是否空
	bool IsFull()const { return currentSize == maxHeapSize; }
private:
	Line* heap;  //存放元素数组
	int currentSize;  //当前元素个数
	int maxHeapSize;  //最大元素个数
	void siftDown(int start, int m);  //从start到m下滑调整为最小堆
	void siftUp(int start);  //从start到0上滑调整为最小堆
};
