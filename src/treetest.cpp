#include "s21_rbtree.h"
#include <set>
#include "s21_set.h"

int main(void) {
    s21::set<int> first_set;
    std::cout << first_set.empty() << std::endl;
    first_set.insert(25);
    std::cout << first_set.empty();
    /* first_set.insert(5); */
    /* first_set.insert(50); */
    /* first_set.insert(4); */
    /* first_set.insert(26); */
    /* first_set.insert(24); */
    /* s21::set<int>::iterator i = first_set.begin(); */
    /* i++; */
    /* i++; */
    /* i++; */
    /* first_set.erase(i); */
    /* for (auto &j : first_set) { */
    /*     std::cout << "Elements: " << j << std::endl; */
    /* } */ 
    return 0;
}
