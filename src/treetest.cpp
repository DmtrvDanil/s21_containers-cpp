#include <set>
#include <iostream>
#include "s21_map.h"
#include <map>
void o(s21::set<int> t) {
    for (auto &i : t)
        std::cout << i;
    std::cout << std::endl;
}


int main(void) {
    s21::map<int, int> a;
    a.insert(std::make_pair(1,2));
    s21::map<int,int>::iterator i = a.begin();
    std::cout << i->second << std::endl;

    return 0;
}
