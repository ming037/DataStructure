#pragma once
#include "commonListDef.h"
#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

typedef struct ArrayQueueNodeType
{
	char data;
}ArrayQueueNode;

typedef struct
{
	int maxElementCnt;
	int currentElementCnt;
	int front;
	int rear;
	ArrayQueueNode *pElement;
}ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCnt);
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode* dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode* peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);
void displayArrayQueue(ArrayQueue* pQueue);

#endif