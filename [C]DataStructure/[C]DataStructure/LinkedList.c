#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

LinkedList* createLinkedList()
{
	LinkedList* pReturn = NULL;
	pReturn = (LinkedList*)malloc(sizeof(LinkedList));
	if (pReturn != NULL)
		memset(pReturn, 0, sizeof(LinkedList));
	else
	{
		printf("ERROR, MEMORY PROBLEM ON createLinkedList()");
		return NULL;
	}
	return pReturn;
}

int addLLElement(LinkedList* pList, int pos, ListNode element)
{
	int res = FALSE;
	ListNode* pPreNode = NULL;
	ListNode* pNewNode = NULL;

	if (pList != NULL)
	{
		if (pos >= 0 && pos <= pList->currentElementCnt)
		{
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL)
			{
				*pNewNode = element;
				pNewNode->pLink = NULL;

				pPreNode = &(pList->headerNode);
				for (int i = 0; i < pos; i++) //header is not counted
					pPreNode = pPreNode->pLink;

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode; 

				pList->currentElementCnt++;
				res = TRUE;
			}
			else
			{
				printf("ERROR, MEMORY PROBLEM ON addLLElement()");
				return res;
			}
		}
		else
			printf("ERROR, POSITION PROBLEM ON addLLElement()");
	}
	return res;
}

int removeLLElement(LinkedList* pList, int pos)
{
	int res = FALSE;
	ListNode* pNode = NULL;
	ListNode* pDelNode = NULL;

	if (pList != NULL)
	{
		if (pos >= 0 && pos <= pList->currentElementCnt)
		{
			pNode = &(pList->headerNode);
			for (int i = 0; i < pos; i++) //header is not counted
				pNode = pNode->pLink;

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink;
			free(pDelNode);

			pList->currentElementCnt--;
			res = TRUE;
			
		}
		else
			printf("ERROR, POSITION PROBLEM ON addLLElement()");
	}
	return res;
}

ListNode* getLLElement(LinkedList* pList, int pos)
{
	ListNode* pReturn = NULL;
	ListNode* pNode = NULL;
	if (pList != NULL)
	{
		if (pos >= 0 && pos <= pList->currentElementCnt)
		{
			pNode = &(pList->headerNode);
			for (int i = 0; i <= pos; i++)
				pNode = pNode->pLink;
			pReturn = pNode;
		}
	}
	return pReturn;
}

void clearLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		if (pList->currentElementCnt > 0)
		{
			for (int i = pList->currentElementCnt-1; i >= 0; i--)
				removeLLElement(pList, i);
		}
	}
	printf("LIST CLEARED");
}
void deleteLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		clearLinkedList(pList);
		free(pList);
	}
}

int getLinkedListLength(LinkedList* pList)
{
	int res = 0;
	if (pList != NULL)
		res = pList->currentElementCnt;
	return res;
}

void displayLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		printf("CURRENT ELEMENT COUNT = %d\n", pList->currentElementCnt);
		for (int i=0; i < pList->currentElementCnt; i++)
			printf("[%d]: %d\n", i, getLLElement(pList, i)->data);
	}
}