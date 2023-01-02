#include "Hashmap.h"

#include <iostream>

template <typename T>
bool Hashmap<T>::store(T data) {
	int val = hash(data);
	if (!validHash(val))
		return false;
	columns.at(val).insert(data); //Insert into linkedlist
	return true;
	
}

template <typename T>
T Hashmap<T>::get(T candide, bool& status) {
	int val = hash(candide);
	if (validHash(val)) {
		Linkedlist linkedlist = columns.at(val);
		return linkedlist.find(candide, status);
	}
	status = false;
	return nullptr;
}

template <typename T>
int Hashmap<T>::remove(T data) {
	int val = hash(data);
	return validHash(val) && columns.at(val).remove(data);
}

template <typename T>
void Hashmap<T>::print() {
	for (int i = 0; i < columns.size(); i++) {
		std::cout << "Hashmap[" << i << "]\n";
		columns.at(i).print(true);
	}
}

template<typename T>
int Hashmap<T>::hash(T) {
    return 0;
}

template class Hashmap<std::string>;