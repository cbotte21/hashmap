#pragma once
#define LINKEDLIST_H

template <typename T>
struct linkedlist {
	linkedlist* next;
	T value;
}

template <typename T>
class Linkedlist {
	linkedlist* head;
	public:
		void insert(T data);
		T find(T candide, bool& status);
		int remove(T data);
		void print(bool indentFlag);
}
