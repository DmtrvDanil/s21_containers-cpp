#include "s21_containers.h"
#include "s21_containersplus.h"
#include <gtest/gtest.h>
#include "vector"

//namespace  s21 {
// >>>>>>> VECTOR <<<<<<<<
class Test_vector {
    public:
        s21::Vector<int> empty_Vector;
        s21::Vector<int> five_Vector{1,2,3,4,5};
        s21::Vector<int> four_Vector{1,2,3,4};
        s21::Vector<char> char_Vector;
        s21::Vector<float> float_Vector;
        s21::Vector<double> double_Vector;
//        s21::Vector<int>::iterator_1 it_Vector = five_Vector.begin_1();
//        std::vector<int> init_origin(3);
        std::vector<int> origin_five_vector{1,2,3,4,5};
        std::vector<int> origin_four_vector{1,2,3,4};
        std::vector<int> origin_int;
        std::vector<char> origin_char;
        std::vector<float> origin_float;
        std::vector<double> origin_double;
        std::vector<int>::iterator it_origin = origin_five_vector.begin();

};

    TEST(Vector, constructor_default) {
        Test_vector logger;
        EXPECT_EQ(logger.empty_Vector.size(), logger.origin_int.size());
        EXPECT_EQ(logger.empty_Vector.capacity(), logger.origin_int.capacity());
        EXPECT_EQ(logger.empty_Vector.empty(), logger.origin_int.empty());
    }

    TEST(Vector, constructor_init) {
        s21::Vector<int> s21_vector(3);
        std::vector<int> std_vector(3);
        ASSERT_EQ(s21_vector.size(), std_vector.size());
        ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
        ASSERT_EQ(s21_vector.empty(), std_vector.empty());
    }

    TEST(Vector, constructor_initializer_lit) {
        Test_vector logger;
        EXPECT_EQ(logger.five_Vector[0], logger.origin_five_vector[0]);
        EXPECT_EQ(logger.five_Vector[4], logger.origin_five_vector[4]);
        EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
        EXPECT_EQ(logger.five_Vector.empty(), logger.origin_five_vector.empty());
    }

    TEST(Vector, constructor_copy) {
        Test_vector logger;
        s21::Vector<int> s21_copy(logger.five_Vector);
        std::vector<int> std_copy(logger.origin_five_vector);
        EXPECT_EQ(s21_copy[0], std_copy[0]);
        EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
        EXPECT_EQ(s21_copy.size(), std_copy.size());
        EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
        EXPECT_EQ(s21_copy.empty(), std_copy.empty());
    }

    TEST(Vector, constructor_move) {
        Test_vector logger;
        s21::Vector<int> s21_copy(std::move(logger.five_Vector));
        std::vector<int> std_copy(std::move(logger.origin_five_vector));
        EXPECT_EQ(s21_copy[0], std_copy[0]);
        EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
        EXPECT_EQ(s21_copy.size(), std_copy.size());
        EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
        EXPECT_EQ(s21_copy.empty(), std_copy.empty());
    }


TEST(vector_assignment_suit, copy_assignment_lesser_buffer) {
s21::Vector<int> s21_vector{534789, 2479056, 987654, 110101024, 62348710, 1, 35674};
std::vector<int> std_vector{534789, 2479056, 987654, 110101024, 62348710, 1, 35674};
s21::Vector<int> s21_vector_copy{1, 2};
std::vector<int> std_vector_copy{1, 2};
s21_vector_copy = s21_vector;
std_vector_copy = std_vector;
ASSERT_EQ(s21_vector_copy[0], std_vector_copy[0]);
ASSERT_EQ(s21_vector_copy[1], std_vector_copy[1]);
ASSERT_EQ(s21_vector_copy[2], std_vector_copy[2]);
ASSERT_EQ(s21_vector_copy[3], std_vector_copy[3]);
ASSERT_EQ(s21_vector_copy[4], std_vector_copy[4]);
ASSERT_EQ(s21_vector_copy[5], std_vector_copy[5]);
ASSERT_EQ(s21_vector_copy[6], std_vector_copy[6]);
ASSERT_EQ(s21_vector_copy.size(), std_vector_copy.size());
ASSERT_EQ(s21_vector_copy.capacity(), std_vector_copy.capacity());
ASSERT_EQ(s21_vector_copy.empty(), std_vector_copy.empty());
}


//
//    TEST(Test, empty_testing) {
//        Test_vector logger;
//        EXPECT_FALSE(logger.five_Vector.empty());
//        EXPECT_TRUE(logger.empty_Vector.empty());
//    }
//
//    TEST(Test, size_testing) {
//        Test_vector logger;
//        EXPECT_EQ(logger.empty_Vector.size(), 0);
//        EXPECT_EQ(logger.five_Vector.size(), 5);
//
//    }
//
//    TEST(Test, max_size_testing) {
//        Test_vector logger;
//        EXPECT_EQ(logger.empty_Vector.max_size(), logger.origin_int.max_size());
////        EXPECT_EQ(logger.char_Vector.max_size(), logger.origin_char.max_size());
//        EXPECT_EQ(logger.float_Vector.max_size(), logger.origin_float.max_size());
//        EXPECT_EQ(logger.double_Vector.max_size(), logger.origin_double.max_size());
//    }
//
//    TEST(Test, reserve_testing) {
//        Test_vector logger;
//        logger.five_Vector.reserve(2);
//        logger.origin_five_vector.reserve(2);
//        std::cout << logger.five_Vector.capacity() << std::endl;
//        std::cout << logger.origin_five_vector.capacity() << std::endl;
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//        logger.five_Vector.reserve(1000);
//        logger.origin_five_vector.reserve(1000);
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//        logger.five_Vector.reserve(0);
//        logger.origin_five_vector.reserve(0);
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
////        EXPECT_ANY_THROW(logger.five_Vector.reserve(-1));  // google leaks
//    }
//
//    TEST(Test, capacity_testing) {
//        Test_vector logger;
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//        logger.five_Vector.push_back(3);
//        logger.origin_five_vector.push_back(4);
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//        logger.five_Vector.pop_back();
//        logger.origin_five_vector.pop_back();
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//    }
//
//    TEST(Test, shrink_to_fit_testing) {
//        Test_vector logger;
//        logger.five_Vector.reserve(3);
//        logger.origin_five_vector.reserve(3);
//        logger.five_Vector.shrink_to_fit();
//        logger.origin_five_vector.shrink_to_fit();
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//        EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
//        logger.five_Vector.reserve(100);
//        logger.origin_five_vector.reserve(100);
//        logger.five_Vector.shrink_to_fit();
//        logger.origin_five_vector.shrink_to_fit();
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//        EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
//        logger.five_Vector.reserve(0);
//        logger.origin_five_vector.reserve(0);
//        logger.five_Vector.shrink_to_fit();
//        logger.origin_five_vector.shrink_to_fit();
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//        EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
//    }
//
//    TEST(Test, clear_testing) {
//        Test_vector logger;
//        logger.five_Vector.clear();
//        logger.origin_five_vector.clear();
//        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
//        EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
//    }
//


    // STOP

    //    TEST(Test, insert_testing_1) {
    //        Test_vector logger;
    //        logger.five_Vector.insert(logger.it_Vector, 300);
    //        logger.origin_five_vector.insert(logger.it_origin, 300);
    //        EXPECT_EQ(logger.five_Vector.capacity(), logger.origin_five_vector.capacity());
    //        EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
    //
    //    }
    //
    //    TEST(Test, insert_testing_2) {
    //        Test_vector logger;
    //        logger.five_Vector.reserve(7);
    //        logger.origin_five_vector.reserve(7);
    //        s21::Vector<int>::iterator i = logger.five_Vector.begin();
    //        std::vector<int>::iterator j = logger.origin_five_vector.begin();
    //        logger.five_Vector.insert(i,235);
    //        logger.origin_five_vector.insert(j, 235);
    //    }
    //
    //    TEST(Test, insert_testing_3) {
    //        Test_vector logger;
    //        s21::Vector<int>::iterator my_it = logger.five_Vector.insert(logger.it_Vector, 95);
    //        std::vector<int>::iterator origin_it = logger.origin_five_vector.insert(logger.it_origin, 95);
    //        EXPECT_EQ(*my_it, *origin_it);
    //    }


//
//    TEST(Test, empty_testing) {
//        std::vector<int> a(1,2,3);
//        std::vector<int> result_origin();
//        Vector<int> b(1,2,3);
//        Vector<int> my_result();
//        for (auto &&i : a) {
//            my_result += i;
//        }


// >>>>>>>>>>> ARRAY <<<<<<<<<<<<<<<<
    class Test_array {
    public:
      s21::array<int, 4> a;

    };

//}  // namespace 21

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

