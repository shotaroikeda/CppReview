#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
class LinkedList
{
public:
        LinkedList();
        //////////////////////////////////////////////////
        // Big 3 - Must create all if one is available: //
        // 1. Copy Constructor			        //
        // 2. Destructor			        //
        // 3. Copy assignment operator		        //
        //////////////////////////////////////////////////
        LinkedList(const LinkedList<T> &other);
        ~LinkedList();
        LinkedList<T> & operator = (const LinkedList<T> &other);

        //////////////////////////////////////////////////////////
        // Functions - do things on this list from client side. //
        //////////////////////////////////////////////////////////

	// insert functions
        void insertAt(int i, const T &data);
	void insertFront(const T &data);
	void insertBack(const T &data);
        void removeAt(int i);
        void changeAt(int i, const T &data);
        void printAll() const; // promise that printAll will not change member vars
        void printAt(int i) const; // promise that printAt will not change member vars

        T operator [] (const int i);

private:
        class Node
        {
        public:
                Node *next;
                T data;

                Node();
        };

        // Sentienel Nodes to make life easier
        Node *head;
        Node *tail;

        int len;

        void _copy(const LinkedList &other);
        void _clear();

        Node *find(int i);
};

#include "linked_list.cpp"
#endif
