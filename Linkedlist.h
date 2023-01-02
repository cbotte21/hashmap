#pragma once
#define LINKEDLIST_H

template <typename T>
struct linkedlist {
	linkedlist<T>* next;
	T value;
};

template <typename T>
class Linkedlist {
	linkedlist<T>* head;
    T find_r(linkedlist<T>* curr, T candide, bool& status);
    void print_trailing_nodes_inclusive(linkedlist<T>* curr, bool indentFlag);
	public:
        void insert(T data);
		T find(T candide, bool& status);
		int remove(T data);
		void print(bool indentFlag);
};
