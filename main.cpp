#define HASHMAP_SIZE 100
#include <string>
#include "Hashmap.h"

class StrMap : public Hashmap<std::string> {
    int hash(std::string data) {
        int total = 0;
        for (char& c : data) {
            total += c;
        }
        return total % HASHMAP_SIZE;
    }

public:
    StrMap(int i) : Hashmap(i) {}
};

int main() {
    StrMap hashMap(HASHMAP_SIZE);

    hashMap.store("Cody");
    hashMap.store("Sarah");
    hashMap.store("Carlos");
    hashMap.store("Sean");
    hashMap.store("Chris");
    hashMap.store("Cole");

    hashMap.print();
}
