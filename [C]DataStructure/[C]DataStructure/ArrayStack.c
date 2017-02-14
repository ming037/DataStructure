#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayStack.h"

ArrayStack* createArrayStack(int maxElementCnt)
{
	ArrayStack* pReturn = NULL;
	
	if (maxElementCnt > 0)
	{
		pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
		if (pReturn != NULL)
		{
			memset(pReturn, 0, sizeof(ArrayStack));
			pReturn->maxElementCnt = maxElementCnt;
		}
		else
		{
			printf("ERROR, MEMORY PROBLEM ON createArrayStack()");
			return pReturn;
		}

		pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode)*maxElementCnt);
		if (pReturn->pElement != NULL)
			memset(pReturn->pElement, 0, sizeof(ArrayStackNode)*maxElementCnt);
		else
		{
			printf("ERROR, MEMORY PROBLEM2 ON createArrayStack()");
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

int push(ArrayStack* pStack, ArrayStackNode element)
{
	int res = FALSE;
	if (pStack != NULL)
	{
		if (!isArrayStackFull(pStack))
		{
			pStack->pElement[pStack->currentElementCnt] = element;
			pStack->currentElementCnt++;
			res = TRUE;
		}
		else
			printf("ERROR, STACK IS FULL");
	}
	return res;
}

ArrayStackNode* pop(ArrayStack* pStack)
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL)
	{
		if (!isArrayStackEmpty(pStack))
		{
			//pReturn = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
			//*pReturn = pStack->pElement[pStack->currentElementCnt-1];
			pReturn = &(pStack->pElement[pStack->currentElementCnt - 1]);
			pStack->currentElementCnt--;
		}
		else
			printf("ERROR,STACK IS EMPTY");
		
	}
	return pReturn;
}

ArrayStackNode* peek(ArrayStack* pStack)
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL)
	{
		if (!isArrayStackEmpty(pStack))
		{
			//pReturn = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
			pReturn = &(pStack->pElement[pStack->currentElementCnt - 1]);
		}
		else
			printf("ERROR,STACK IS EMPTY");
	}
	return pReturn;
}


void deleteArrayStack(ArrayStack* pStack)
{
	if (pStack != NULL)
	{
		if (pStack->pElement != NULL)
			free(pStack->pElement);
		free(pStack);
	}
}
int isArrayStackFull(ArrayStack* pStack)
{
	int res = FALSE;
	if (pStack != NULL)
		res = (pStack->currentElementCnt == pStack->maxElementCnt) ? TRUE : FALSE;
	return res;
}
int isArrayStackEmpty(ArrayStack* pStack)
{
	int res = FALSE;
	if (pStack != NULL)
		res = (pStack->currentElementCnt == 0) ? TRUE : FALSE;
	return res;
}

void displayArrayStack(ArrayStack* pStack)
{
	int i = 0;
	if (pStack  != NULL)
	{
		printf("MAX ELEMENT COUNT = %d \n", pStack->maxElementCnt);
		printf("CURRENT ELEMENT COUNT = %d\n", pStack->currentElementCnt);
		for (i; i < pStack->currentElementCnt; i++)
			printf("[%d]: %c\n", i, pStack->pElement[i]);
	}
}