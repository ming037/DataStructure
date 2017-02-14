#pragma once
#include <iostream>
using namespace std;

template <class T>
class ListNode
{
private:
	T data;
	
public:
	ListNode<T>* pLink; //pointer for next node
	ListNode(T _data = 0) { data = _data; pLink = NULL;};
	T getData() { return data; };
};

template <class T>
class LinkedList
{
private:
	int currentElementCnt; //현재 원소의 개수
	ListNode<T>* headerNode;
public:
	LinkedList();
	~LinkedList();
	bool addLLElement(int pos, T element);
	bool removeLLElement(int pos);
	ListNode<T>* getLLElement(int pos);
	void displayLinkedList();
	void clearLinkedList();
	int getLinkedListLength();

};

//구현부

template<class T>
LinkedList<T>::LinkedList()
{
	currentElementCnt = 0;
	headerNode = new ListNode<T>(0);
	if (headerNode == NULL)
		throw "ERROR, CHECK THE MEMORY, createLinkedList";	
}

template<class T>
LinkedList<T>::~LinkedList()
{
	clearLinkedList();
	delete headerNode;
}

template<class T>
bool LinkedList<T>::addLLElement(int pos, T element)
{
	bool res = false;
	ListNode<T>* pPreNode = NULL;
	ListNode<T>* pNewNode = NULL;
	
	if (pos >= 0 && pos <= currentElementCnt)
	{
		pNewNode = new ListNode<T>(element);
		if (pNewNode != NULL)
		{
			pPreNode = headerNode;
			for (int i = 0; i < pos; i++) //header is not counted
				pPreNode = pPreNode->pLink;

			pNewNode->pLink = pPreNode->pLink;
			pPreNode->pLink = pNewNode;

			currentElementCnt++;
			res = true;
		}
		else
		{
			throw "ERROR, MEMORY PROBLEM ON addLLElement()";
			return res;
		}
	}
	else
		throw "ERROR, POSITION PROBLEM ON addLLElement()";
	return res;
}

template<class T>
bool LinkedList<T>::removeLLElement(int pos)
{
	bool res = false;
	ListNode<T>* pNode = NULL;
	ListNode<T>* pDelNode = NULL;

	if (pos >= 0 && pos <= currentElementCnt)
	{
		pNode = headerNode;
		for (int i = 0; i < pos; i++) //header is not counted
			pNode = pNode->pLink;

		pDelNode = pNode->pLink;
		pNode->pLink = pDelNode->pLink;
		delete pDelNode;

		currentElementCnt--;
		res = true;
	}
	else
		throw "ERROR, POSITION PROBLEM ON addLLElement()";
	return res;
}

template<class T>
ListNode<T>* LinkedList<T>::getLLElement(int pos)
{
	ListNode<T>* pReturn = NULL;
	ListNode<T>* pNode = NULL;
	
	if (pos >= 0 && pos <= currentElementCnt)
	{
		pNode = headerNode;
		for (int i = 0; i <= pos; i++)
			pNode = pNode->pLink;
		pReturn = pNode;
	}
	return pReturn;
}

template<class T>
void LinkedList<T>::displayLinkedList()
{
	ListNode<T>* tmp = NULL;
	printf("CURRENT ELEMENT COUNT = %d\n", currentElementCnt);
	for (int i = 0; i < currentElementCnt; i++)
	{
		tmp = getLLElement(i);
		cout << "[" << i << "]: " << tmp->getData() << endl;
	}
}

template<class T>
void LinkedList<T>::clearLinkedList()
{
	if (currentElementCnt > 0)
	{
		for (int i = currentElementCnt - 1; i >= 0; i--)
			removeLLElement(i);
	}
	cout << "LIST CLEARED" <<endl;
}

template<class T>
int LinkedList<T>::getLinkedListLength()
{
	return currentElementCnt;
}
