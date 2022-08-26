#include "s21_containers.h"
#include <vector>

int main(void){
//    std::vector<int> a{1,2,3};
//    s21::Vector<int> b{1,2,3};
//    b.reserve(7);
//    std::cout << b.capacity() << std::endl;
//    a.reserve(7);
//    std::cout << a.capacity() ;
//    a.reserve(6);
//    b.output_vector();
//    b.reserve(100);
//    std::cout << b.capacity() << std::endl;
//    a.reserve(100);
//    std::cout << a.capacity() << std::endl;
//     for (auto i = 0; i < a.size(); i++) {
//        std::cout << a.at(i);
//     }
//
//     std::vector<int> a{1, 2 , 3};
//     std::cout <<  a.capacity() << " This is a capacity for original vector" << std::endl;
//     std::cout << a.size() << " This is a size of original vector" << std::endl;
//     a.reserve(3);
//     for (auto i = 0; i < a.size(); i++) {
//         std::cout << a.at(i);
//     }
//     std::cout << std::endl;
//     std::cout << a.capacity() << " This is a capacity after reserve " << std::endl;
//     std::cout << a.size() << " This is a size after resetve " << std::endl;
//     a.shrink_to_fit();
//     std::cout << a.capacity() << " This is a capacity after shrink to fit" << std::endl;
//     std::cout << a.size() << " This is a size after shrink to fit" << std::endl;
//     a.push_back(5);
//     std::cout << a.capacity() << " This is a capacity after push" << std::endl;
//     std::cout << a.size() << " This is a size after push" << std::endl;
//     std::cout << "#####################" << std::endl;
//     s21::Vector<int> b{1,2,3};
//     std::cout << b.capacity() << " This is a capacity for my vector" << std::endl;
//     std::cout << b.size() << " This is a size for my vector" << std::endl;
//     b.reserve(3);
//     std::cout << b.capacity() << " This is a capacity after reserve" << std::endl;
//     std::cout << b.size() << " This is a size after reserve" << std::endl;
//     b.shrink_to_fit();
//     std::cout << b.capacity() << " This is a capacity after fit" << std::endl;
//     std::cout << b.size() << " This is a size after fit" << std::endl;
//     b.push_back(5);
//     // b.output_vector();
//     std::cout << b.capacity() << " This is a capacity after push" << std::endl;
//     std::cout << b.size() << " This is a size after push" << std::endl;

    s21::Vector<int> a{1,2,3};
    std::vector<int> b{1,2,3};
    std::cout << b.capacity() << " " << b.size() << std::endl;
    a.clear();
    b.clear();
//    for (auto i = 0; i < a.size(); i++) {
//        std::cout << b.at(i);
//    }
    std::cout << a.capacity() << " " << a.size() << std::endl;
    std::cout << b.capacity() << " " << b.size() << std::endl;
    return 0;
}