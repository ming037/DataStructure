#pragma once
#include "commonListDef.h"
//List 정리1 - Array List(배열 리스트)
#ifndef _ARRAYLIST_
#define _ARRAYLIST_
typedef struct
{
	int data;
}ArrayListNode;

typedef struct
{
	int maxElementCnt; // 최대 원소 갯수
	int currentElementCnt; //현재 원소의 개수
	ArrayListNode *pElement; //원소 저장을 위한 포인터(배열)
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
