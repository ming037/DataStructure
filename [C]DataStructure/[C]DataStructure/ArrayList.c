#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

//������
ArrayList* createArrayList(int maxElementCnt)
{
	ArrayList* pReturn = NULL;
	int i = 0;

	if (maxElementCnt > 0)
	{
		pReturn = (ArrayList *)malloc(sizeof(ArrayList));

		if (pReturn != NULL)
		{
			pReturn->maxElementCnt = maxElementCnt;
			pReturn->currentElementCnt = 0;
			pReturn->pElement = NULL;
		}
		else //pReturn �� NULL�̶� ���� �޸� �Ҵ翡 ������ �����.
		{
			printf("ERROR, CHECK THE MEMORY, createArrayList");
			return NULL;
		}
	}
	else
	{
		printf("ERROR, MAX COUNT MUST > 0");
		return NULL;
	}

	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode)*maxElementCnt);
	if (pReturn->pElement == NULL)
	{
		printf("ERROR, CHECK THE MEMORY2, createArrayList");
		free(pReturn);
		return NULL;
	}

	memset(pReturn->pElement, 0, sizeof(ArrayListNode)*maxElementCnt); //0 ���� �ʱ�ȭ
	return pReturn;
}

//����Ʈ ����
void deleteArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		free(pList->pElement);
		free(pList);
	}
	else
	{
		printf("NO LIST TO DELETE");
	}
}

//���� á���� Ȯ��
int isArrayListFull(ArrayList* pList)
{
	int res = FALSE;

	if (pList != NULL)
		if (pList->currentElementCnt == pList->maxElementCnt)  res = TRUE;
	return res;
}

//���� �߰�
int addALElement(ArrayList* pList, int pos, ArrayListNode element)
{
	int res = FALSE;
	int i = 0;
	if (pList != NULL)
	{
		if (!isArrayListFull(pList))
		{
			if (pos >= 0 && pos <= pList->currentElementCnt)
			{
				for (i = pList->currentElementCnt - 1; i >= pos; i--)
					pList->pElement[i + 1] = pList->pElement[i];
				pList->pElement[pos] = element;
				pList->currentElementCnt += 1;
				res = TRUE;
			}
			else
				printf("ERROR, OUT OF RANGE");
		}
		else
			printf("ERROR, LIST IS FULL");
	}
	return res;
}

//���� ����
int removeALElement(ArrayList* pList, int pos)
{
	int res = FALSE;
	int i = 0;
	if (pList != NULL)
	{
		if (pos >= 0 && pos <= pList->currentElementCnt)
		{
			for (i = pos; i < pList->currentElementCnt - 1; i++) pList->pElement[i] = pList->pElement[i + 1];
			pList->currentElementCnt -= 1;
			res = TRUE;
		}
		else
			printf("ERROR, OUT OF RANGE");
	}
	return res;
}

//���� ��ȯ
ArrayListNode* getALElement(ArrayList* pList, int pos)
{
	ArrayListNode* res = NULL;
	if (pList != NULL)
	{
		if (pos >= 0 && pos <= pList->currentElementCnt)
			res = &(pList->pElement[pos]);
		else
			printf("ERROR, OUT OF RANGE");
	}
	return res;
}

//���� ���
void displayArrayList(ArrayList* pList)
{
	int i = 0;
	if (pList != NULL)
	{
		printf("MAX ELEMENT COUNT = %d \n", pList->maxElementCnt);
		printf("CURRENT ELEMENT COUNT = %d\n", pList->currentElementCnt);
		for (i; i < pList->currentElementCnt; i++)
			printf("[%d]: %d\n", i, getALElement(pList, i)->data);
	}
}

//����Ʈ ����
void clearArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		pList->currentElementCnt = 0;
		pList->pElement = NULL;
		printf("LIST CLEARED");
	}
}

//����Ʈ ���� ��ȯ
int getArrayListLength(ArrayList* pList)
{
	int res = 0;
	if (pList != NULL)
		res = pList->currentElementCnt;
	return res;
}