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
    s21::map<int, int> m1({{1, 3}, {4, 2}});
    std::map<int, int> m2({{1, 3}, {4, 2}});
    std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert({1, 2});
    std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert({1, 2});
    /* std::cout << (*(it1.first)).second << std::endl; */
    std::cout << (*(it2.first)).second << std::endl;
    std::cout << it1.second << std::endl;
    std::cout << it2.second << std::endl;

    return 0;
}
