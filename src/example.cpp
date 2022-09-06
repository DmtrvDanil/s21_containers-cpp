#include "s21_containers.h"
//#include "s21_containersplus.h"
//#include "vec_array/array/s21_array.h"
//#include "s21_list.h"
//#include <vector>
//#include <stack>
//#include <array>
#include <list>
int main(void){
    s21::list<int> a;

    a.push_back(1);
//    std::cout << "HEAD = " << a.front() << "\nTAIL = " << a.back() << std::endl;
    a.push_back(2);
    a.push_back(3);
    std::cout << "HEAD = " << a.front() << "\nTAIL = " << a.back() << std::endl;
    std::list<int>::iterator i = a.end();
    i++;
    i++;
    i++;
    i++;
    std::cout << "END = " << *i << std::endl;
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
