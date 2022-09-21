#include "s21_rbtree.h"
#include <set>
#include "s21_set.h"

int main(void) {
    std::set<int> first_set({1,2,3,4}), second_set({5,6,7,8});
    second_set.merge(first_set);
    std::cout << first_set.size() << std::endl;
    std::cout << second_set.size() << std::endl;
    /* s21::set<int> second_set; */
    /* second_set = std::move(first_set); */
    /* for (auto &i : second_set) */
    /*     std::cout << i; */
    return 0;
}
