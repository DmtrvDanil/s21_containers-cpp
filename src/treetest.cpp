#include "s21_rbtree.h"
#include <set>
#include "s21_set.h"

int main(void) {
    s21::set<int> first_set;
    first_set.insert(4);
    first_set.insert(45);
    first_set.insert(2);
    s21::set<int>::iterator i = first_set.begin();
    std::cout << *first_set.end() << std::endl;
    for (; i != first_set.end(); ++i) {
        std::cin.ignore();
        std::cout << *i << " ";
    }
    return 0;
}
