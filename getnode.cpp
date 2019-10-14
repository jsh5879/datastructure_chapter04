
//getnode, retnode
#include <iostream>
using namespace std;

template<class T> class CircularChain; //forward declaration

template<class T>
class ChainNode {
	friend class CircularChain<T>;
public:
	ChainNode(T element = 0)
	{
		data = element;
		link = 0;
	}
private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class CircularChain {
public:
	CircularChain() { last = 0; };
	~CircularChain();
	void Delete(void);
	void Add(const T& element); //add a new node after last
	void InsertFront(const T& e);
	ChainNode<T>* GetNode();
	void RetNode(ChainNode<T>& x);
	//void Merge(CircularChain<T>& b);
private:
	static ChainNode<T>* av;
	ChainNode<T>* last; //point to the last node
};

template <class T>
CircularChain<T>::~CircularChain() {}

template <class T>
void CircularChain<T>::Delete(void) //delete the last element after last
{
	ChainNode<T>* next;
	next = last->link;
	if (!last) //non-empty list
	{
		ChainNode<T>* temp = last;
		last = next;
		delete temp;
	}
	cout << "Empty List: Not deleted" << endl;
}

template <class T>
void CircularChain<T>::Add(const T& element) //add a new node after last
{
	ChainNode<T>* newnode = new ChainNode<T>(element);
	if (!last) //insert into empty list
	{
		last = newnode;
		return;
	}
	//insert a new node after last
	newnode->link = last;
	last = newnode;
}

template <class T>
void CircularChain<T>::InsertFront(const T& e)
{ //insert the element e at the 'front' of the circular list *this
  // last points to the last node in the list
	ChainNode<T>* newNode = new ChainNode<T>(e);
	if (last) { //nonempty list
		newNode->link = last->link;
		last->link = newNode;
	}
	else {//empty list
		last = newNode;
		newNode->link = newNode;
	}

}

template <class T>
ChainNode<T>* CircularChain<T>::GetNode()
{ //provide a node for use
	ChainNode<T>* x;
	if (av) { x = av, av = av->link; }
	else x = new ChainNode<t>;
	return x;
}
template <class T>
void CircularChain<T>::RetNode(ChainNode<T>& x)
{ //free the node pointed to by x
	x->link = av;
	av = x;
	x = 0;
}
/*
template <class T>
void Merge(CircularChain<T>& b)
{// a.Merge(b) produces list contains the merged result
 // coding한다.
}
*/
template <class T>
ChainNode<T> CircularChain<T>::av = 0;

int main(void) {

	char select;
	ChainNode<int> nd;
	CircularChain<int> a, b;
	int value;
	do {
		cout << endl << "Select command:1: Add to list a,2: Add to list b, 3: Delete, 4:InsertFront, 5: PrintAll, 6: Merge, q: quit";
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
			a.Delete();
			break;
		case '4':
			cin >> value;
			a.InsertFront(value);
			break;
		case '5': //print all elements by using iterator class
			/*
			for (;;) // coding 추가
				;
			break;
			/*
			/*
		case '6':
			a.Merge(b);
			break;
			*/
		case 'q':
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
	} while (select != 'q');
	system("pause");
	return 0;
}
//head node가 있는 circular list로 수정한다.
