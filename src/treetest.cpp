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
    s21::map<int, int> a{{1,2}};
    s21::map<int, int> b;
    a.swap(b);
    std::cout << b.size() << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << b.empty() << std::endl;
    std::cout << a.empty() << std::endl;
    std::map<int, int> c{{1,2}};
    std::map<int, int> d;
    c.swap(d);
    std::cout << d.size() << std::endl; 
    std::cout << c.size() << std::endl;
    std::cout << d.empty() << std::endl;
    std::cout << c.empty() << std::endl;

    return 0;
}
