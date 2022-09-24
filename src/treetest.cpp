#include <set>
#include <iostream>
#include "s21_multiset.h"
void o(s21::set<int> t) {
    for (auto &i : t)
        std::cout << i;
    std::cout << std::endl;
}

int main(void) {
    s21::set<int> a{1,56,3,2};

    std::set<int> b{1,56,3,2};
    std::cout << "This is set" << std::endl;
    for (auto &i : a)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << *a.find(56) << " Find:End  " << *a.end() << std::endl;
    std::cout << *b.find(56) << " Find:End " << *b.end() << std::endl;
    return 0;
}
