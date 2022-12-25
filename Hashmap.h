#pragma once
#define HASHMAP_H

#include <vector>
#include <string>
#include "Linkedlist.h"

//TODO: add constructor

template <typename T>
class Hashmap {
	std::vector<Linkedlist<T>> columns;
	bool validHash(int i);
	public:
		Hashmap(int* hash(T payload); //Must provide hashing function
		extern bool store(T data);
		extern T get(T candide, bool& status);
		extern int remove(T data);
		extern void print();
		int* hash(T payload);
}
