#include "s21_rbtree.h"
#include <set>
#include "s21_set.h"

int main(void) {
    s21::set<int> first_set{1};
    std::cout << first_set.size() << std::endl;
    s21::set<int> second_set = std::move(first_set);
    std::cout << second_set.size() << std::endl;
    std::cout << first_set.size() << std::endl;
    return 0;
}
