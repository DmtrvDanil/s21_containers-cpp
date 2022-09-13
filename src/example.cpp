#include "s21_containers.h"
//#include "s21_containersplus.h"
//#include "vec_array/array/s21_array.h"
//#include "s21_list.h"
#include <vector>
//#include <stack>
//#include <array>
#include <list>
#include <string>
int main(void){

    s21::list<int> a(3);
    std::list<int> b(3);
    for (auto &i : b)
        std::cout << i; 
    a.output_list();

//    s21::list<int> a;
//    std::cout << a.empty() << std::endl;
//
//
//    std::cout << *d.end() << std::endl;
//std::list<char>  l;
//std::cout << *a.end() << std::endl;
//std::cout << a.size();

//std::list<double> a(1);
//std::cout << *a.end() << std::endl;
//std::cout << a.size();
//a.output_list();

//std::cout << "sdfs"; //    std::cout << *a.end();
//    a.push_back(1);
//    std::cout << "HEAD = " << a.front() << "\nTAIL = " << a.back() << std::endl;
//    a.push_back(2);
//    a.push_back(3);
//    a.push_front(4);
//    std::cout << "HEAD = " << a.front() << "\nTAIL = " << a.back() << std::endl;
//    s21::list<int>::iterator i = a.end();
//    ++i;
//    ++i;
//    ++i;
//    ++i;
//    std::cout << "END = " << *i << std::endl;
//
//    s21::list<int> s;
////    std::cout << "HEAD = " << s.front() << "\nTAIL = " << s.back() << std::endl;
//    s.push_back(8);
//    s.push_back(7);
//    s.push_front(2);
//    s.push_front(1);
//    std::cout << "HEAD = " << s.front() << "\nTAIL = " << s.back() << std::endl;

//    s.output_list();

//    s.say();
//    std::cout << s.empty()  ;
    return 0;
}
