#include "s21_containers.h"
#include "s21_containersplus.h"
//#include "vec_array/array/s21_array.h"
#include "s21_list.h"
#include <vector>
#include <stack>
#include <array>
#include <list>
int main(void){
    std::list<int> a{1,2,3};
    for (auto o : a){
        std::cout << o;
    }

    return 0;
}
