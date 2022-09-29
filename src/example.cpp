#include <map>
#include <set>
#include "s21_containers.h"

int main(void) {
    s21::multiset<int> a{1,2};
    s21::multiset<int>::iterator i = a.begin();
    std::cout << *i << std::endl;
    a.clear();
    std::cout << *i << std::endl;
    

    return 0;
}
