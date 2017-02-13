#pragma once
#pragma once
//List ����1 - Array List(�迭 ����Ʈ)
#ifndef _ARRAYLIST_
#define _ARRAYLIST_
typedef struct
{
	int data;
}ArrayListNode;

typedef struct
{
	int maxElementCnt; // �ִ� ���� ����
	int currentElementCnt; //���� ������ ����
	ArrayListNode *pElement; //���� ������ ���� ������(�迭)
}ArrayList;

ArrayList* createArrayList(int maxElementCnt);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addALElement(ArrayList* pList, int pos, ArrayListNode element);
int removeALElement(ArrayList* pList, int pos);
ArrayListNode* getALElement(ArrayList* pList, int pos);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);
#endif

#ifndef _COMMON_LIST_DEF
#define _COMMON_LIST_DEF

#define TRUE 1
#define FALSE 0

#endif