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

        struct ListNode {
        public:
            ListNode() : value_(0U), next_(0U), prev_(0U) {}
            ~ListNode() {};
            value_type value_;
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
        bool empty();
        void say() {std::cout << "Hello World!"; }
        void output_list() {
            std::cout << "This is your list: " << std::endl;
            for (node* point = this->head_; point != nullptr; point = point->next_)
                std::cout << point->value_;
            std::cout << std::endl;
        }
        void push_back(const_reference value);
        void push_front(const_reference value);
        void _push_node(node* node_to_push, node* left_node, node* right_node);
        using iterator = refernce;

    private:
        void clear();
        void Connect();

    };

}  //  namespace s21

#include "s21_list.tpp"
#endif // SRC_S21_LIST_H
