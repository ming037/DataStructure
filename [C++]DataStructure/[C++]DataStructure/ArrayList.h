#pragma once
#include <iostream>
using namespace std;

template <class T>
class ArrayListNode
{
private:
	T data;
public:
	ArrayListNode(T _data = 0) { data = _data; };
	T getData() { return data; };
};

template <class T>
class ArrayList
{
private:
	int maxElementCnt; // 최대 원소 갯수
	int currentElementCnt; //현재 원소의 개수
	ArrayListNode<T> *pElement; //원소 저장을 위한 포인터(배열)
public:
	ArrayList(int _maxElementCnt);
	~ArrayList();

	bool isArrayListFull();
	bool addALElement(int pos, T element);
	bool removeALElement(int pos);
	ArrayListNode<T>* getALElement(int pos);
	void displayArrayList();
	void clearArrayList();
	int getArrayListLength();

};

//구현부
template <class T>
ArrayList<T>::ArrayList(int _maxElementCnt)
{
	if (_maxElementCnt < 0)
		throw "ERROR, MAX COUNT MUST > 0";
	else
	{
		maxElementCnt = _maxElementCnt;
		currentElementCnt = 0;
		pElement = new ArrayListNode<T>[maxElementCnt];
		if (pElement == NULL)
			throw "ERROR, CHECK THE MEMORY, createArrayList";
		memset(pElement, 0, sizeof(ArrayListNode<T>) * maxElementCnt);
	}
}

template<class T>
ArrayList<T>::~ArrayList()
{
	delete[]pElement;
}

template<class T>
bool ArrayList<T>::isArrayListFull()
{
	bool res = false;
	if (currentElementCnt == maxElementCnt) res = true;
	return res;
}

template<class T>
bool ArrayList<T>::addALElement(int pos, T element)
{
	bool res = false;
	if (!isArrayListFull())
	{
		if (pos >= 0 && pos <= currentElementCnt)
		{
			for (int i = currentElementCnt - 1; i >= pos; i--)
				pElement[i + 1] = pElement[i];
			pElement[pos] = element;
			currentElementCnt += 1;
			res = true;
		}
		else
			throw "ERROR, OUT OF RANGE";
	}
	else
		throw "ERROR, LIST IS FULL";

	return res;
}

template<class T>
bool ArrayList<T>::removeALElement(int pos)
{
	bool res = false;
	if (pos >= 0 && pos <= currentElementCnt)
	{
		for (int i = pos; i < currentElementCnt - 1; i++)
			pElement[i] = pElement[i + 1];
		currentElementCnt -= 1;
		res = true;
	}
	else
		throw "ERROR, OUT OF RANGE";
	return res;
}

template<class T>
ArrayListNode<T>* ArrayList<T>::getALElement(int pos)
{
	ArrayListNode<T>* res = NULL;
	if (pos >= 0 && pos <= currentElementCnt)
		res = &pElement[pos];
	else
		throw "ERROR, OUT OF RANGE";
	return res;
}

template<class T>
void ArrayList<T>::displayArrayList()
{
	ArrayListNode<T>* tmp = NULL;
	cout << "MAX ELEMENT COUNT = " << maxElementCnt << endl;
	cout << "CURRENT ELEMENT COUNT = " << currentElementCnt << endl;
	for (int i = 0; i < currentElementCnt; i++)
	{
		tmp = getALElement(i);
		cout << "[" << i << "]: " << tmp->getData() << endl;
	}

}

template<class T>
void ArrayList<T>::clearArrayList()
{
	currentElementCnt = 0;
	pElement = NULL;
	cout << "LIST CLEARED";
}

template<class T>
int ArrayList<T>::getArrayListLength()
{
	return currentElementCnt;
}

