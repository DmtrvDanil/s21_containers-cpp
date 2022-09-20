#include "s21_rbtree.h"
#include <set>
#include "s21_set.h"

int main(void) {
    s21::set<int> first_set;
    first_set.insert(25);
    first_set.insert(5);
    first_set.insert(50);
    first_set.insert(4);
    first_set.insert(26);
    first_set.insert(24);
    s21::set<int>::iterator i = first_set.end();
    for (; i != first_set.begin(); i--) {
        std::cout << "Elements: " << *i << std::endl;
    } 
    std::cout << *i;
    return 0;
}
