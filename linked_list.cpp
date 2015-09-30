#include <iostream>
#include <stdexcept>

template <class T>
LinkedList<T>::Node::Node()
{
	next = NULL;
}

template <class T>
LinkedList<T>::LinkedList()
{
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->next = NULL;

	len = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
{
	_copy(other);
}

template<class T>
LinkedList<T> & LinkedList<T>::operator =(const LinkedList<T> &other)
{
	if (this != &other)
	{
		_clear();
		_copy(other);
	}

	return *this;
}

template <class T>
void LinkedList<T>::_clear()
{
	Node *p = head;
	Node *t = head->next;

	while (t != tail)
	{
		p = t;
		t = t->next;
		delete p;
	}

	delete head;
	delete tail;
}

template <class T>
void LinkedList<T>::_copy(const LinkedList<T> &other)
{
	head = new Node();
	tail = new Node();

	Node *otherTemp = other.head->next;
	Node *thisTemp = head;
	for (int i = 0; i < other.len; i++)
	{
		thisTemp->next = new Node();
		thisTemp->next.data = otherTemp->data;
		thisTemp = thisTemp->next;
		otherTemp = otherTemp->next;
	}

	thisTemp->next = tail;
	tail->next = NULL;

	len = other.len;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	_clear();
}

template <class T>
void LinkedList<T>::printAll() const
{
	Node *temp = head->next;

	while (temp->next != tail && temp->next != NULL)
	{
		std::cout << temp->data << " > ";
		temp = temp->next;
	}

	if (temp->next == NULL)
		std::cout << "Nothing in List." << endl;
	else
		std::cout << temp->data << endl;

	if (len == 0)
	{
		std::cout << "Nothing to see here!\n";
	}
}

template <class T>
typename LinkedList<T>::Node * LinkedList<T>::find(int i)
{
	if (i > len)
	{
		std::cout << "Invalid argument for find, returning NULL. May cause program to crash.";
		return NULL;
	}

	Node *temp = head;
	for (int a = 0; a < i; a++)
	{
		temp = temp->next;
	}

	return temp;
}

template <class T>
void LinkedList<T>::insertAt(int i, const T &data)
{
	if (i > len+1)
	{
		std::cout << "Bad insertion. Not inserting.\n";
		return;
	}

	Node *search = find(i-1);
	Node *temp = search->next;

	search->next = new Node;
	search->next->data = data;
	search->next->next = temp;

	len++;
}

template <class T>
void LinkedList<T>::insertFront(const T &data)
{
	insertAt(1, data);
}

template <class T>
void LinkedList<T>::insertBack(const T &data)
{
	insertAt(len+1, data);
}

template <class T>
void LinkedList<T>::removeAt(int i)
{
	Node *temp = find(i-1);

	Node *del = temp->next;
	temp->next = temp->next->next;

	delete del;

	len--;
}

template <class T>
void LinkedList<T>::changeAt(int i, const T &data)
{
	Node *temp = find(i);
	temp->data = data;
}

template <class T>
void LinkedList<T>::printAt(int i) const
{
	Node *p = find(i);
	std::cout << p->data << endl;
}

template <class T>
T LinkedList<T>::operator [](const int i)
{
	if (i >= len || i < 0)
	{
		throw std::invalid_argument("Bad index.\n");
	}

	Node *p = find(i+1);
	return p->data;
}
