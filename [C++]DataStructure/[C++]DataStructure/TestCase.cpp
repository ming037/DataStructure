#include <iostream>
#include <stdlib.h>
#include "ArrayList.h"
#include "LinkedList.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
using namespace std;

int main()
{
	//testcase for ArrayList
	/*
	try
	{
		ArrayList<int> a(6);
		for (int i = 0; i < 6; i++)
			a.addALElement(i, i + 1);

		a.displayArrayList();

		a.removeALElement(2);
		a.removeALElement(3);

		a.displayArrayList();

		a.clearArrayList();

		a.displayArrayList();
		a.removeALElement(1);
	}
	catch (char* e)
	{
		cout << e;
	}
	*/

	/*
	//testcase for LinkedList
	try
	{
		LinkedList<int> a;
		for (int i = 0; i < 6; i++)
			a.addLLElement(i, i + 1);
		
		a.displayLinkedList();

		a.removeLLElement(2);
		a.removeLLElement(3);

		a.displayLinkedList();

		a.clearLinkedList();

		a.displayLinkedList();
		a.removeLLElement(1);
	}
	catch (char* e)
	{
		cout << e;
	}
	*/

	/*
	//testcase for ArrayStack
	try
	{
		ArrayStack<int> a(3);
		for (int i = 0; i < 3; i++)
			a.push(i + 1);

		a.displayArrayStack();

		a.pop();
		a.pop();

		a.displayArrayStack();

		a.pop();
		a.displayArrayStack();
		a.pop();
		
	}
	catch (char* e)
	{
		cout << e;
	}
	*/

	//testcase for ArrayQueue
	try
	{
		ArrayQueue<int> a(3);
		for (int i = 0; i < 3; i++)
			a.enqueueAQ(i + 1);

		a.displayArrayQueue();

		a.dequeueAQ();
		a.dequeueAQ();

		a.displayArrayQueue();

		a.dequeueAQ();
		a.displayArrayQueue();
		a.dequeueAQ();

	}
	catch (char* e)
	{
		cout << e;
	}
	system("pause");
}