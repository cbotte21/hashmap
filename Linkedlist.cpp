#include "Linkedlist.h"
#include <iostream>

template<typename T>
void Linkedlist<T>::insert(T data) {
	auto* nnode = new linkedlist<T> { nullptr, data };
	if (head == nullptr) {
        head = nnode;
        return;
    }
	linkedlist<T>* curr = head;
	for (; curr->next; curr = curr->next);
	curr->next = nnode;
}

template<typename T>
T Linkedlist<T>::find_r(linkedlist<T>* curr, T candide, bool& status) { //Recursive approach
	if (curr->value == candide) {
		status = true;
		return curr->value;
	}
	return find_r(curr->next, candide, status);
}

template<typename T>
T Linkedlist<T>::find(T candide, bool& status) {
	status = false; //Should be an optimization over being in recursive funcion
	return find_r(head, candide, status);
}

template<typename T>
int Linkedlist<T>::remove(T data) { //Loop approach
	if (head->value == data)
		head = head->next;

	for(linkedlist<T>* node = head; node->next != nullptr; node = node->next)
		if (node->next->value == data) { //TODO: Do you need to free nodes?
			node->next = node->next->next;
			return true;
		}
	return false;
}

template <typename T>
void Linkedlist<T>::print_trailing_nodes_inclusive(linkedlist<T>* curr, bool indentFlag) {
	if (curr != nullptr) {
		if (indentFlag)
			std::cout << "    ";
		std::cout << curr->value << std::endl;
		return print_trailing_nodes_inclusive(curr->next, indentFlag);
	}
}

/*
 * params:
 *	bool indentFlag: adds 4 spaces before value
 *
 */
template <typename T>
void Linkedlist<T>::print(bool indentFlag) {
	print_trailing_nodes_inclusive(head, indentFlag);
}

template class Linkedlist<std::string>;