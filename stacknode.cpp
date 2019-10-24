//Stack node & Queue Node
#include <stdio.h>
#include <iostream>
using namespace std;
template <class T>
class Stack; //forward declaration

template <class T>
class StackNode {
	friend class Stack<T>;
private:
	T data;
	StackNode<T>* link;
	StackNode<T>(T d = 0, StackNode<T>* l = 0) : data(d), link(l) {};//constructor
};
/*
template <class T>
class QueueNode {
	friend class Queue<T>;
private:
	T data;
	QueueNode<T>* front;
	QueueNode<T>* rear;
	QueueNode<T>(T d = 0, QueueNode<T>*l = 0) : data(d), link(l) {};//constructor
};
*/
template <class T>
class Stack {
public:
	Stack() { top = 0; };//constructor
	void Add(const T);
	T* Delete(T&);
private:
	StackNode<T>* top;
	void StackEmpty();

};
/*
template <class T>
class Queue {
public:
	Queue() { front = rear = 0; };//constructor
	void Add(const T);
	T* Delete(T&);
private:
	QueueNode<T>* top;
	void QueueEmpty();

};
*/
template <class T>
void Stack<T>::Add(const int y) {
	top = new StackNode<T>(y, top);
}

template <class T>
T* Stack<T>::Delete(T& retvalue)
//delete the top node from stack and return a pointer to its data
{
	if (top == ) {
		StackEmpty(); return 0;
	} //retrun null pointer constant
	StackNode* x = top;
	retvalue = top->data; //get data field of top node
	top = x->link;//remove top node
	delete x;
	return &retvalue;//return pointer to data
}
/*
template <class T>
void Queue<T>::Add(const T y) {
	if (front == 0) front = rear = new QueueNode(y,0);//empty queue
	else rear = rear->link = new QueueNode(y,0); //attach node and update rear
}

template <class T>
T* Queue<T>::Delete(T& retvalue)
//delete the first node in queue and return a pointer to its data
{
	if (front == 0) {QueueEmpty(); return 0;}
	QueueNode *x = front;
	retvalue = front->data; //get data field of front node
	front = x->link;//remove front node
	delete x;
	return &retvalue;//return pointer to data
}
*/
int main(void) {

	char select;
	StatckNode<int> sn;
	Stack<int> a;
	/*
	QueueNode<int> qn;
	Queue<int> q;
	*/
	int value;

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
			a.Delete();
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
