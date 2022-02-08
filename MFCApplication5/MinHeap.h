#pragma once
#include"Line.h"
class LineHeap
{
public:
	LineHeap(int sz = 34);  //���캯��
	bool Insert(const Line& x);  //��x������С����
	bool RemoveMin(Line& x);  //ɾ���Ѷ���СԪ��
	bool IsEmpty()const { return(currentSize == 0) ? true : false; }  //�ж϶��Ƿ��
	bool IsFull()const { return currentSize == maxHeapSize; }
private:
	Line* heap;  //���Ԫ������
	int currentSize;  //��ǰԪ�ظ���
	int maxHeapSize;  //���Ԫ�ظ���
	void siftDown(int start, int m);  //��start��m�»�����Ϊ��С��
	void siftUp(int start);  //��start��0�ϻ�����Ϊ��С��
};
