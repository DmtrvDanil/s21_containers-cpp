#ifndef SRC_S21_LIST_H
#define SRC_S21_LIST_H
#include <iostream>
#include <stdexcept>
#include <cmath>


namespace s21{
template<class T>
    class list {
        public:
            using value_type = T;
            using refernce = T&;
            using const_reference = const T&;
            using pointer = T*;
            using size_type = size_t;
    private:
        struct ListNode {
            value_type value;
            ListNode* next_;
            ListNode* prev_;
        };

    public:
        using node = ListNode;

    private:
        node* head_;
        node* tail_;
        size_type m_size_;
    public:
        list();
        ~list();

    private:
        void clear();
    };

}  //  namespace s21

#endif // SRC_S21_LIST_H
