#define HASHMAP_SIZE 100
#include <string>
#include "Hashmap.h"

int hash(std::string data) {
	int total = 0;
	for (char& c : data) {
		total += c;
	}
	return total % HASHMAP_SIZE;
}

int main() {
	Hashmap<std::string> hashMap(&hash);

}
