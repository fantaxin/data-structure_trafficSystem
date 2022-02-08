#include "pch.h"
#include"MinHeap.h"
LineHeap::LineHeap(int sz)
{
	maxHeapSize = sz;
	heap = new Line[maxHeapSize];
	currentSize = 0;
}
void LineHeap::siftDown(int start, int m)
{
	int i = start, j = 2 * i + 1;
	Line temp = heap[i];
	while (j <= m)
	{
		if ((j < m) && (heap[j].cost > heap[j + 1].cost))
		{
			j++;
		}
		if (temp.cost <= heap[j].cost)
		{
			break;
		}
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}
void LineHeap::siftUp(int start)
{
	int j = start, i = (j - 1) / 2;
	Line temp = heap[j];
	while (j > 0)
	{
		if (heap[i].cost <= temp.cost)
			break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;
}
bool LineHeap::Insert(const Line&x)
{
	if (currentSize == maxHeapSize)
		return false;
	heap[currentSize] = x;
	siftUp(currentSize);
	currentSize++;
	return true;
}
bool LineHeap::RemoveMin(Line& x)
{
	if (!currentSize)
		return false;
	x = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;
}