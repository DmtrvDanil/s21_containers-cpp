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
    s21::map<int, int> m1({{1, 2}, {3, 4}, {4, 5}});
    s21::map<int, int> m2({{5, 6}, {7, 7}});
    m1.merge(m2);

    std::map<int, int> m3({{1, 2}, {3, 4}, {4, 5}});
    std::map<int, int> m4({{5, 6}, {7, 7}});
    m3.merge(m4);
    
    std::cout << "M1 size: " <<  m1.size() << " " << "M1 empty: " << m1.empty() << std::endl;
    std::cout << "M2 size: " << m2.size() << " " << "M2 empty: " << m2.empty() << std::endl;
    std::cout << "M3 size: " << m3.size() << " " << "M3 empty: " << m3.empty() << std::endl;
    std::cout << "M4 size: " << m4.size() << " " << "M4 empty: " << m4.empty() << std::endl;


    return 0;
}
