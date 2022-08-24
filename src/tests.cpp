#include "s21_containers.h"
#include <gtest/gtest.h>
#include "vector"

namespace  s21 {
// >>>>>>> VECTOR <<<<<<<<

// ITERATORS TEST
    TEST(Test, for_range) {
        std::vector<int> a(1,2,3);
        std::vector<int> result_origin();
        Vector<int> b(1,2,3);
        Vector<int> my_result();
        for (auto &&i : a) {
            my_result += i;
        }


}

}  // namespace 21

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}