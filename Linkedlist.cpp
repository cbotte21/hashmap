#include "Linkedlist.h"
#include <iostream>

template<typename T>
void Linkedlist::insert(T data) {
	linkedlist* nnode = { nullptr, data }
	if (head == nullptr) 
		head = nnode;

	linkedlist* curr = head;
	for (; curr->next; curr = curr->next);
	curr->next = nnode;
}

T find_r(linkedlist* curr, T candide, bool& status) { //Recursive approach
	if (curr->value == candide) {
		*status = true;
		return curr->value;
	}
	return find_r(curr->next, candide, status);
}

template<typename T>
T Linkedlist::find(T candide, bool& status) {
	*status = false; //Should be an optimization over being in recursive funcion
	return find_r(head, status);
}

template<typename T>
int Linkedlist::remove(T data) { //Loop approach
	if (head->value == data)
		head = head->next;

	for(linkedlist* node = head; node->next != nullptr; node = node->next)
		if (node->next->value == data) { //TODO: Do you need to free nodes?
			node->next = node->next->next;
			return true;
		}
	return false;
}

void print_trailing_nodes_inclusive(linkedlist* curr, bool indentFlag) {
	if (curr) {
		if (indentFlag)
			std::cout << "    ";
		std::cout << curr->value << std::endl;
		return print_trailing_nodes_inclusive(curr->next, indentFlag);
	}
}

/*params:
 *	bool indentFlag: adds 4 spaces before value
 */
void Linkedlist::print(bool indentFlag) {
	print_trailing_nodes_inclusive(head, indentFlag);
}
