#pragma once
#include <iostream>
using namespace std;

template <class T>
class ArrayStackNode
{
private:
	T data;
public:
	ArrayStackNode(T _data = 0) { data = _data; };
	T getData() { return data; };
};

template <class T>
class ArrayStack
{
private:
	int maxElementCnt; 
	int currentElementCnt; 
	ArrayStackNode<T> *pElement; //원소 저장을 위한 포인터(배열)
public:
	ArrayStack(int _maxElementCnt);
	~ArrayStack();

	bool push(T element);
	ArrayStackNode<T>* pop();
	ArrayStackNode<T>* peek();
	bool isArrayStackFull();
	bool isArrayStackEmpty();
	void displayArrayStack();
};

//구현부

template<class T>
ArrayStack<T>::ArrayStack(int _maxElementCnt)
{
	if (_maxElementCnt > 0)
	{
		maxElementCnt = _maxElementCnt;
		currentElementCnt = 0;
		pElement = new ArrayStackNode<T>[maxElementCnt];
		if (pElement == NULL)
			throw "ERROR, MEMORY PROBLEM ON createArrayStack()";
	}
	else
		throw "ERROR, MAX COUNT MUST > 0";
}

template<class T>
inline ArrayStack<T>::~ArrayStack()
{
	delete []pElement;
}

template<class T>
inline bool ArrayStack<T>::push(T element)
{
	bool res = false;
	if (!isArrayStackFull())
	{
		pElement[currentElementCnt] = element;
		currentElementCnt++;
		res = true;
	}
	else
		throw "ERROR, STACK IS FULL";
	return res;
}

template<class T>
inline ArrayStackNode<T>* ArrayStack<T>::pop()
{
	ArrayStackNode<T>* pReturn = NULL;
	if (!isArrayStackEmpty())
	{
		pReturn = &pElement[currentElementCnt - 1];
		currentElementCnt--;
	}
	else
		throw "ERROR,STACK IS EMPTY";
	return pReturn;
}

template<class T>
inline ArrayStackNode<T>* ArrayStack<T>::peek()
{
	ArrayStackNode<T>* pReturn = NULL;
	if (!isArrayStackEmpty())
		pReturn = pElement[currentElementCnt - 1];
	else
		throw "ERROR,STACK IS EMPTY";
	return pReturn;
}

template<class T>
inline bool ArrayStack<T>::isArrayStackFull()
{
	return maxElementCnt == currentElementCnt;
}

template<class T>
inline bool ArrayStack<T>::isArrayStackEmpty()
{
	return currentElementCnt == 0;
}

template<class T>
inline void ArrayStack<T>::displayArrayStack()
{
	ArrayStackNode<T> tmp = NULL;
	printf("MAX ELEMENT COUNT = %d \n", maxElementCnt);
	printf("CURRENT ELEMENT COUNT = %d\n",currentElementCnt);
	for (int i=0 ; i < currentElementCnt; i++)
	{
		tmp = pElement[i];
		cout << "[" << i << "]: " << tmp.getData()<< endl;
	}
		
}
