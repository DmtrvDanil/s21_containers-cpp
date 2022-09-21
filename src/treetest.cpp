#include "s21_rbtree.h"
#include <set>
#include <list>
#include "s21_set.h"

int main(void) {
    s21::set<int> first_set;
    std::set<int> second_set;
    std::cout << first_set.max_size() << std::endl;
    std::cout << second_set.max_size() << std::endl;
    /* s21::set<int> second_set; */
    /* second_set = std::move(first_set); */
    /* for (auto &i : second_set) */
    /*     std::cout << i; */
    return 0;
}
