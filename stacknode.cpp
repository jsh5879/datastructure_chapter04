#include <iostream>
#include "stacknode.h"
using namespace std;
int main(void) {

	char select;
	StackNode<int> sn;
	Stack<int> a;
	
	QueueNode<int> qn;
	Queue<int> q;
	
	int value, result;

	cout << endl << "Select command:A: Add to Stack, D: Delete from Stack, P: PrintAll";
	cin >> select;
	while (select != 'Q')
	{
		switch (select)
		{
		case 'A':
			cout << "Add a new value: ";
			cin >> value;
			a.Add(value);
			break;
		case 'D':
			result = *a.Delete(value);
			break;
		case 'P': //print all elements 
			for (;;) // coding 추가
				;
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
	}
	system("pause");
	return 0;
}
//queuenode도 생성하도록 코드 수정
