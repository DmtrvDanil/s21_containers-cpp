#include "s21_containers.h"
#include "s21_containersplus.h"
//#include "vec_array/array/s21_array.h"
#include <vector>
#include <array>
//#include "vector.h"

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
//    s21::Vector<int> b{1,2,3,4};
////    s21::Vector<int>::VectorIterator i = b.begin();
//    std::vector<int> a{1,2,3,4,5};
//    std::vector<int>::iterator j = a.begin();
//    a.reserve(7);
//
//    std::cout << "BEFORE " << a.capacity() << " " << a.size() << std::endl;
//    std::cout << *a.insert(j, 235) << "origin here" << std::endl;
//    std::cout << "AFTER " << a.capacity() << " " << a.size() << std::endl;
//
//    for (auto l = 0 ; l < a.size(); l++) {
//        std::cout << a.at(l);
//    }
//    std::cout << std::endl;
//    s21::Vector<int> b{1,2,3,4};
////    b.reserve(7);
//    s21::Vector<int>::iterator i = b.begin();
//    std::cout << "BEFORE " << b.capacity() << " " << b.size() << std::endl;
//    std::cout << *b.insert(i, 100) <<  "::::::" << std::endl;
//    std::cout << "AFTER " << "Capacity: " << b.capacity() << " "  "Size: "<< b.size() << std::endl;
//    b.output_vector();
//    s21::Vector<int> b{23,2,3,4};
//    s21::Vector<int>::iterator_1 i = b.begin_1();
//    std::cout << "Where is ziro " << *b.test_insert(i, 100) << std::endl;
//    b.output_vector();
//
//    s21::Vector<int> e{23,4,3,4,6};
//    s21::Vector<int>::iterator k = b.begin();
//    std::cout << *e.insert(k, 234) << std::endl;
//    e.output_vector();

//    std::vector<int> b{1,2,3,4};
//    std::vector<int>::const_iterator  e = b.begin();
//    std::vector<int>::iterator l = b.begin();
//    *(l+2) = 95;
//    *(e + 2) = 34;
//    std::cout << *(j+2) << std::endl;
//    std::cout << *(l+2) << std::endl;
//    s21::Vector<int> a{1,2,3,4};
//    s21::Vector<int>::const_iterator i = a.begin();
//    s21::Vector<int>::iterator j = a.end_1();
//    s21::Vector<int>::iterator_1 l = a.end_1();
//    s21::Vector<int>::const_iterator_1 m = a.end_1();
//    *(m + 2) = 93;
//    *(l + 2) = 95;
//    std::cout << *(l + 1) << std::endl;
//    std::cout << *(m + 1) << std::endl;


//    *(i+ 2)  = 95;
//    *j++ = 90;

//    std::cout << *(i + 2) << std::endl;
//    std::cout << *(j + 2) << std::endl;
//    std::array<int, 5> ai;
//    for (int i = 0; i < ai.size(); i++)
//        std::cout << ai.at(i);
//    std::array<int, 3> a{1,2,3,4,5,6};

//    std::array<int, 3> c{1,2,3};
//    std::array<int, 3> v {8,7,6};
//    c.swap(v);
//    for (int i = 0; i < c.size(); i++) {
//        std::cout << c.at(i);
//    }
//
//    std::cout << std::endl;
//
//    for (int i = 0; i < v.size(); i++) {
//        std::cout << v.at(i);
//    }
//
//    std::cout << std::endl;
//    s21::array<int, 4> b;
//    s21::array<int, 4> a {8,7,6};
//    b.swap(a);
//    for (int i =0; i < b.size(); i++) {
//        std::cout << b.at(i);
//    }
//    std::cout << std::endl;
//
//    for (int i = 0; i < a.size(); i++) {
//        std::cout << a.at(i);
//    }

// move vector
//    std::vector<int> *a = new std::vector<int>{1,2,3,4,5};
//    std::vector<int> b = std::move(*a);
//    for (int i = 0; i < a->size(); i++) {
//        std::cout << a->at(i);
//    }
//    delete a;
//    std::cout << std::endl;
//    for (int i = 0; i < b.size(); i++) {
//        std::cout << b.at(i);
//    }
//    std::cout << std::endl;
//
//    s21::Vector<int> *l = new s21::Vector<int>{1,2,3,4,5};
//    std::cout << l->size() << " <> " << l->capacity() << std::endl;
//    s21::Vector<int> k;
//    k = *l;
//    for (int i = 0; i < l->size(); i++) {
//        std::cout << l->at(i);
//    }
//
//    delete l;
//    std::cout << k.size() << " <> " << k.capacity() << std::endl;
//    std::cout << std::endl;
//    for (int i = 0; i < k.size(); i++) {
//        std::cout << k.at(i);
//    }

//    s21::Vector<int> a{1,2,3,4};
//    s21::Vector<int>::const_iterator j = a.begin() + 2;
////    *j = 2;
//    std::cout << *j << std::endl;
//    --j;
//    std::cout << *j << std::endl;
//    a.erase(a.begin());
//    std::cout << a.size() << " " << a.capacity() << std::endl;
////    for (int i = 0; i < a.size(); i++) {
////        std::cout << a.at(i);
////    }

    s21::array<int, 5> a;
    s21::array<int, 5>::iterator d;
    std::array<int,3>::iterator sl;
    return 0;
}
