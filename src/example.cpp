#include <map>
#include "s21_containers.h"

int main(void) {
    s21::map<int, int> a{{1,2}, {2,2}};
    s21::map<int, int>::const_iterator i = a.begin();

    return 0;
}
