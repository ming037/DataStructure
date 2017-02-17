#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayQueue.h"

ArrayQueue* createArrayQueue(int maxElementCnt)
{

	ArrayQueue* pReturn = NULL;

	if (maxElementCnt > 0)
	{
		pReturn = (ArrayQueue*)malloc(sizeof(ArrayQueue));
		if (pReturn != NULL)
		{
			memset(pReturn, 0, sizeof(ArrayQueue));
			pReturn->maxElementCnt = maxElementCnt;
			pReturn->front = -1;
			pReturn->rear = -1;
		}
		else
		{
			printf("ERROR, MEMORY PROBLEM ON createArrayQueue()");
			return pReturn;
		}

		pReturn->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode)*maxElementCnt);
		if (pReturn->pElement != NULL)
			memset(pReturn->pElement, 0, sizeof(ArrayQueueNode)*maxElementCnt);
		else
		{
			printf("ERROR, MEMORY PROBLEM2 ON createArrayQueue()");
			free(pReturn);
			return NULL;
		}
	}
	else
	{
		printf("ERROR, SIZE PROBLEM ON createArrayStack()");
		return NULL;
	}
	return pReturn;
}
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	int res = FALSE;
	if (pQueue != NULL)
	{
		if(!isArrayQueueFull(pQueue))
		{ 
			pQueue->rear++;
			pQueue->pElement[pQueue->rear] = element;
			pQueue->currentElementCnt++;
			res = TRUE;
		}
		else
			printf("ERROR,QUEUE IS FULL ");
	}
	return res;
}
ArrayQueueNode* dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode* pReturn = NULL;
	if (pQueue != NULL)
	{
		if (!isArrayQueueEmpty(pQueue))
		{
			pQueue->front++;
			pReturn = &(pQueue->pElement[pQueue->front]);
			pQueue->currentElementCnt--;
		}
		else
			printf("ERROR, QUEUE IS EMPTY");
	}
	return pReturn;
}

ArrayQueueNode* peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode* pReturn = NULL;
	if (pQueue != NULL)
	{
		if (!isArrayStackEmpty(pQueue))
		{
			pQueue = &(pQueue->pElement[pQueue->front + 1]);
		}
		else
			printf("ERROR,QUEUE IS EMPTY");
	}
	return pReturn;
}
void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (pQueue != NULL)
	{
		if (pQueue->pElement != NULL)
			free(pQueue->pElement);
		free(pQueue);
	}
}
int isArrayQueueFull(ArrayQueue* pQueue)
{
	int res = FALSE;
	if (pQueue != NULL)
		res = (pQueue->rear+1 == pQueue->maxElementCnt) ? TRUE : FALSE;
	return res;
}
int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	int res = FALSE;
	if (pQueue != NULL)
		res = (pQueue->currentElementCnt == 0) ? TRUE : FALSE;
	return res;
}
void displayArrayQueue(ArrayQueue* pQueue)
{
	if (pQueue != NULL)
	{
		printf("MAX ELEMENT COUNT = %d \n", pQueue->maxElementCnt);
		printf("CURRENT ELEMENT COUNT = %d\n", pQueue->currentElementCnt);
		for (int i= pQueue->front+1, cnt = 0; i < pQueue->rear+1; i++, cnt++)
			printf("[%d]: %c\n", cnt, pQueue->pElement[i]);
	}
}