#include "Hashmap.h"

#include <iostream>

bool Hashmap::validHash(int i) //Verify user defined hash function
	return val < columns.size;

template <typename T>
bool Hashmap::store(T data) {
	int val = hash(data);
	if (!validHash(val))
		return false;

	columns.at(hash(data)).insert(data); //Insert into linkedlist
	return true;
	
}

template <typename T>
T Hashmap::get(T candide, bool& status) {
	int val = hash(candide);
	if (validHash(val)) {
		Linkedlist linkedlist = columns.at(val);
		return Linkedlist.find(candide, status);
	}
	status = false;
	return nullptr;
}

template <typename T>
int Hashmap::remove(T data) {
	int val = hash(data);
	return validHash(val) ? columns.at(val).remove(data) : false;
}

template <typename T>
void Hashmap::print() {
	for (int i = 0; i < columns.size(); i++) {
		std::cout << "Hashmap[" << i << "]\n";
		columns.at(i).print(true);
	}
}
