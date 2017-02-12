#include <iostream>
#include <stdlib.h>
#include "ArrayList.h"
using namespace std;

int main()
{
	try
	{
		//test cases
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

	system("pause");
}