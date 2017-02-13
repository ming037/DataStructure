#pragma once
#include "commonListDef.h"
#ifndef _LINKEDLIST_
#define _LINKEDLIST_
//List 정리2 = Linked List(연결 리스트)
typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink; //pointer for next node
}ListNode;

typedef struct
{
	int currentElementCnt;
	ListNode headerNode;
}LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int pos, ListNode element);
int removeLLElement(LinkedList* pList, int pos);
ListNode* getLLElement(LinkedList* pList, int pos);

void clearLinkedList(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

int getLinkedListLength(LinkedList* pList);
void displayLinkedList(LinkedList* pList);


#endif 


