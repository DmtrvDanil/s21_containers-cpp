#include "s21_rbtree.h"
#include <set>
#include "s21_set.h"

int main(void) {
    s21::set<int> first_set{1};
    std::cout << first_set.size() << std::endl;
    first_set.clear();
    std::cout << first_set.size() << std::endl;
    return 0;
}
