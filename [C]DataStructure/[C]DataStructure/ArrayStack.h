#pragma once
#include "commonListDef.h"
#ifndef _ARRAYSTACK
#define _ARRAYSTACK

typedef struct
{
	char data;
}ArrayStackNode;

typedef struct
{
	int maxElementCnt;
	int currentElementCnt;
	ArrayStackNode *pElement; //노드 저장용 배열
}ArrayStack;

ArrayStack* createArrayStack(int maxElementCnt);
int push(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* pop(ArrayStack* pStack);
ArrayStackNode* peek(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);
void displayArrayStack(ArrayStack* pList);
#endif // !_STACK
