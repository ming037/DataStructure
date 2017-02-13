#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "LinkedList.h"
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
	

	system("pause");
}