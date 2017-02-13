#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
int main()
{
	//testcase for ArrayList
	ArrayList *pList = NULL;
	ArrayListNode *pValue = NULL;

	pList = createArrayList(6);
	if (pList != NULL)
	{
		ArrayListNode node;
		for (int i = 0; i < 5; i++)
		{
			node.data = i;
			addALElement(pList, i, node);
		}
		displayArrayList(pList);
	}
	system("pause");
}