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

//            ~ListNode() {};
            value_type value_;
            ListNode* next_;
            ListNode* prev_;
            ListNode() : value_(), next_(nullptr), prev_(nullptr) {}
            explicit ListNode(const const_reference value) : value_(value), next_(nullptr), prev_(nullptr) {}
        };

    public:
        using node = ListNode;

    private:
        node two_with_1;
        size_type m_size_;
        node* two_with_;
        node* head_;
        node* tail_;
    public:
        list();
        list(std::initializer_list<value_type> const &items);
        list(const list &l);
        list(list &&l);
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
        void pop_back();
        void push_front(const_reference value);
        void _push_node(node* node_to_push, node* left_node, node* right_node);
        class ListIterator {
        private:
            node* data_;
        public:
            ListIterator() {
                this->data_ = nullptr;
            }
            ListIterator(node* value){
                this->data_ = value;
            }

            T& operator++() {
                this->data_ = this->data_->next_;
                return this->data_->value_;
            }
            T& operator*() {
                return this->data_->value_;

            }
        };

    public:
        using iterator = ListIterator;
        iterator begin() {
            return iterator(this->two_with->next_);
        }
        iterator end() {
            return iterator(this->two_with_);
        }
        const_reference front() {
            return this->two_with_->next_->value_;
        }
        const_reference back() {
            return this->two_with_->prev_->value_;
        }
        size_type  size();

    private:
        void clear();
        void Connect();
        void InitList();

    };

}  //  namespace s21

#include "s21_list.tpp"
#endif // SRC_S21_LIST_H
