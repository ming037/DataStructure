#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "LinkedList.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
int main()
{
	//testcase for ArrayList
	/*
	ArrayList *pArrayList = NULL;
	pArrayList = createArrayList(6);
	
	if (pArrayList != NULL)
	{
		ArrayListNode node;
		for (int i = 0; i < 5; i++)
		{
			node.data = i;
			addALElement(pArrayList, i, node);
		}
		displayArrayList(pArrayList);
		removeALElement(pLinkedList, 3);
		displayArrayList(pArrayList);
	}
	*/

	//testcase for LinkedList
	/*
	LinkedList *pLinkedList = NULL;
	pLinkedList = createLinkedList();
	if (pLinkedList != NULL)
	{
		ListNode node;
		for (int i = 0; i < 5; i++)
		{
			node.data = i;
			addLLElement(pLinkedList, i, node);
		}
		displayLinkedList(pLinkedList);
		removeLLElement(pLinkedList, 3);
		displayLinkedList(pLinkedList);
	}
	*/

	/*
	//testcase for ArrayStack
	ArrayStack *pArrayStack = NULL;
	pArrayStack = createArrayStack(5);
	if (pArrayStack != NULL)
	{
		ArrayStackNode node;
		for (int i = 0; i < 5; i++)
		{
			node.data = i+65;
			push(pArrayStack, node);
		}
		displayArrayStack(pArrayStack);
		pop(pArrayStack);
		displayArrayStack(pArrayStack);
	}
	*/
	ArrayQueue *pArrayQueue = NULL;
	pArrayQueue = createArrayQueue(5);
	if (pArrayQueue != NULL)
	{
		ArrayQueueNode node;
		for (int i = 0; i < 5; i++)
		{
			node.data = i + 65;
			enqueueAQ(pArrayQueue, node);
		}
		displayArrayQueue(pArrayQueue);
		dequeueAQ(pArrayQueue);
		displayArrayQueue(pArrayQueue);
	}
	system("pause");
}