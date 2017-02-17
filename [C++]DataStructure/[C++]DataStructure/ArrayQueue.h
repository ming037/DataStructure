#pragma once
#include <iostream>
using namespace std;

template <class T>
class ArrayQueueNode
{
private:
	T data;
public:
	ArrayQueueNode(T _data = 0) { data = _data; };
	T getData() { return data; };
};

template <class T>
class ArrayQueue
{
private:
	int maxElementCnt;
	int currentElementCnt;
	int front;
	int rear;
	ArrayQueueNode<T> *pElement; //원소 저장을 위한 포인터(배열)
public:
	ArrayQueue(int _maxElementCnt);
	~ArrayQueue();

	bool enqueueAQ(T element);
	ArrayQueueNode<T>* dequeueAQ();
	ArrayQueueNode<T>* peekAQ();
	bool isArrayQueueFull();
	bool isArrayQueueEmpty();
	void displayArrayQueue();
};

//구현부

template<class T>
inline ArrayQueue<T>::ArrayQueue(int _maxElementCnt)
{
	if (_maxElementCnt > 0)
	{
		maxElementCnt = _maxElementCnt;
		currentElementCnt = 0;
		pElement = new ArrayQueueNode<T>[maxElementCnt];
		rear = -1;
		front = -1;
		if (pElement == NULL)
			throw "ERROR, MEMORY PROBLEM ON createArrayQueue()";
	}
	else
		throw "ERROR, MAX COUNT MUST > 0";
}

template<class T>
inline ArrayQueue<T>::~ArrayQueue()
{
	delete[] pElement;
}

template<class T>
inline bool ArrayQueue<T>::enqueueAQ(T element)
{
	bool res = false;
	if (!isArrayQueueFull())
	{
		rear++;
		pElement[rear] = element;
		currentElementCnt++;
		res = true;
	}
	else
		throw "ERROR, QUEUE IS FULL";
	return res;
}

template<class T>
inline ArrayQueueNode<T>* ArrayQueue<T>::dequeueAQ()
{
	ArrayQueueNode<T>* pReturn = NULL;
	if (!isArrayQueueEmpty())
	{
		front++;
		pReturn = &pElement[front];
		currentElementCnt--;
	}
	else
		throw "ERROR,QUEUE IS EMPTY";
	return pReturn;
}

template<class T>
inline ArrayQueueNode<T>* ArrayQueue<T>::peekAQ()
{
	ArrayQueueNode<T>* pReturn = NULL;
	if (!isArrayQueueEmpty())
		pReturn = &pElement[front+1];
	else
		throw "ERROR,QUEUE IS EMPTY";
	return pReturn;
}


template<class T>
inline bool ArrayQueue<T>::isArrayQueueFull()
{
	return maxElementCnt == rear+1;
}

template<class T>
inline bool ArrayQueue<T>::isArrayQueueEmpty()
{
	return currentElementCnt == 0;
}

template<class T>
inline void ArrayQueue<T>::displayArrayQueue()
{
	ArrayQueueNode<T> tmp = NULL;
	printf("MAX ELEMENT COUNT = %d \n", maxElementCnt);
	printf("CURRENT ELEMENT COUNT = %d\n", currentElementCnt);
	for (int i = front+1,cnt=0; i < rear+1; i++, cnt++)
	{
		tmp = pElement[i];
		cout << "[" << cnt << "]: " << tmp.getData() << endl;
	}
}
