#pragma once
#define HASHMAP_H

#include <vector>
#include <string>
#include "Linkedlist.h"

template <typename T>
class Hashmap {
    std::vector<Linkedlist<T>> columns;
	bool validHash(int i) {
        return i < columns.size();
    };
    virtual int hash(T);
	public:
        Hashmap(int size) {
            for (int i = 0; i < size; i++) {
                columns.push_back(Linkedlist<T>());
            }
        }
        bool store(T data);
		T get(T candide, bool& status);
		int remove(T data);
		void print();
};
