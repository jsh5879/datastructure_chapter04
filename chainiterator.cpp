/* chainiterator.cpp - iterator class를 사용하는 실습 */
/*
 - template 사용시에 chain.h, chain.cpp => 바인딩 처리가 안됨 - visual studio2019의 문제
 - template 사용시에 하나의 file로 처리
*/
//invert, concatenate

#include <iostream>
using namespace std;

template<class T> class Chain; //forward declaration
template<class T> class ChainIterator;

template<class T> class ChainNode {
	friend class Chain<T>;
	friend class ChainIterator<T>;
public:
	ChainNode(T element);
private:
	T data;
	ChainNode<T>* link;
};

template<class T> class Chain {
	friend class ChainIterator<T>;
public:
	Chain() { first = 0; };
	void Delete(void); //delete the first element after first
	int Length();
	void Add(const T& element); //add a new node after first
	void Invert();
	void Concatenate(Chain<T> b);
private:
	ChainNode<T>* first;
};

template<class T>
class ChainIterator {
public:
	ChainIterator(const Chain<T>& l) :list(l), current(l.first) {};
	//dereferencing operators
	T& operator *() const { return current->data; }
	T* operator->()const { return &current->data; }
	//increment
	ChainIterator<T>& operator ++(); //preincrement
	ChainIterator<T> operator ++(int); //post increment
	bool NotNull(); //check the current element in list is non-null
	bool NextNotNull();//check the next element in list is non-null

	T* First(); //return a pointer to the first element of list
	T* Next(); {//return a pointer to the next element of list
private:
	const Chain<T>& list; //refers to an existing list
	ChainNode<T>* current; //points to a node in list
};
template<class T> ChainNode<T>::ChainNode(T element = 0)
{
	data = element;
	link = 0;
}
void template<class T> Chain<T>::Delete(void) //delete the first element after first
{
	ChainNode<T>* current, * next;
	next = first->link;
	if (!first) //non-empty list
	{
		ChainNode<T>* temp = first;
		first = next;
		delete temp;
	}
	cout << "Empty List: Not deleted" << endl;
}
void template<class T> Chain<T>:Add(const T& element) //add a new node after first
{
	ChainNode<T>* newnode = new ChainNode<T>(element);
	if (!first) //insert into empty list
	{
		first = newnode;
		return;
	}
	//insert a new node after first
	newnode->link = first;
	first = newnode;
}
void template<class T> Chain<T>::Invert() {
	ChainNode<T>* p = first, * q = 0; //q trails p
	while (p) {
		ChainNode<T>* r = q; q = p; //r trails q
		p = p->link; //p moves to next node
		q->link = r; //link q to preceding node
	}
	first = q;
}
void template<class T> Chain<T>::Concatenate(Chain<T> b) {
	ChainNode<T>* p;
	if (!first) { first = b.first; return; }
	if (b.first) {
		for (p = first; p->link; p = p->link)
			;//no body
		p->link = b.first;
	}
}
ChainIterator<T>& template<class T>  ChainIterator<T>::  operator ++() //preincrement
{
	current = current->link;
	return *this;
}
ChainIterator<T> template<class T>  ChainIterator<T>:: operator ++(int) //post increment
{
	ChainIterator<T> old = *this;
	current = current->link;
	return old;
}
bool template<class T>  ChainIterator<T>::NotNull() { //check the current element in list is non-null
	if (current) return 1;
	else return 0;
}

bool template<class T>  ChainIterator<T>::NextNotNull() { //check the next element in list is non-null
	if (current && current->link) return 1;
	else return 0;
}
T* template<class T>  ChainIterator<T>::First() { //return a pointer to the first element of list
	if (list.first) return &list.first->data;
	else return 0;
}
T* template<class T>  ChainIterator<T>::Next() {//return a pointer to the next element of list
	if (current) {
		current = current->link;
		return &current->data;
	}
	else return 0;
}

/* template function */
template <class T>
int Show(const Chain<T>& l) {
	ChainIterator<T> li(l); //li is associated with list l
	if (!li.NotNull()) return 0; //empty list, return 0
	T retvalue = *li.First();//get first element
	cout << retvalue << "-> ";
	while (li.NextNotNull()) //make sure that next element exists
	{
		retvalue = *li.Next();
		cout << retvalue << "-> ";
	}
	return retvalue;
}
template <class T>
int sum(const Chain<T>& l) {
	ChainIterator<T> li(l); //li is associated with list l
	if (!li.NotNull()) return 0; //empty list, return 0
	T retvalue = *li.First();//get first element
	while (li.NextNotNull()) //make sure that next element exists
		retvalue += *li.Next();
	return retvalue;
}


template <class T>
int max(const Chain<T>& l) {
	// 학생들이 코딩한다
}

int main(void) {

	char select;
	ChainNode<int> nd;
	Chain<int> a, b;
	ChainIterator<int> cit(a);
	int value;
	do
	{
		cout << endl << "Select command:1: Add_a,2: Add_b, 3: printall, 4: Invert, 5: Concatenate, 6: Delete, 7: Sum, 8:Length, q: Quit" << endl;
		cin >> select;
		switch (select)
		{
		case '1':
			cout << "Add a new value: ";
			cin >> value;
			a.Add(value);
			break;
		case '2':
			cout << "Add a new value: ";
			cin >> value;
			b.Add(value);
			break;
		case '3':
			Show(a);
			Show(b);
			break;
		case '4':
			a.Invert();
			break;
		case '5':
			a.Concatenate(b);
			break;

		case '6':
			a.Delete();
			break;
		case '7':
			sum(a);
			break;
		case '8': //counting the number of nodes by using iterator class
			//
		case 'q':
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
	} while (select != 'Q');
	system("pause");
	return 0;
}
