#ifndef SRC_S21_LIST_H
#define SRC_S21_LIST_H
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>

namespace s21{
template<class T>
    class list {
        public:
            using value_type = T;
            using refernce = T&;
            using const_reference = const T&;
            using pointer = T*;
            using const_pointer = const T*;
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
//        node two_with_1;
        size_type m_size_;
        node* two_with_;
        node* head_;
        node* tail_;
    public:
        list();
        list(size_type n);
        list(std::initializer_list<value_type> const &items);
        list(const list &l);
        list(list &&l);
        ~list();
        list& operator=(const list& other);
        list& operator=(list&& other);
        bool empty() ;
        void say() {std::cout << "Hello World!"; }
        void output_list() {
            std::cout << "This is your list: " << std::endl;
            if (this->empty()) {
                throw std::invalid_argument("Stop");
            }
            for (node* point = this->two_with_->next_; point != this->two_with_; point = point->next_)
                std::cout << point->value_;
            std::cout << std::endl;
        }
        void push_back(const_reference value);
        void pop_back();
        void push_front(const_reference value);
        void pop_front();
        void _push_node(node* node_to_push, node* left_node, node* right_node);
        class ConstIterator {
        public:
            node* data_;
        public:
            ConstIterator() {
                this->data_ = nullptr;
            }
            ConstIterator(node* value) {
                this->data_ = value;
            }
            ConstIterator(const ConstIterator &other) : data_(other.data_) {}
            ~ConstIterator() {}
            ConstIterator& operator++();
            ConstIterator operator++(int);
            ConstIterator& operator--();
            ConstIterator operator--(int);
            const_reference operator*() const;
            ConstIterator operator+(const size_type value);  // see this
            ConstIterator operator-(const size_type value);  // see this
            bool operator!=(const ConstIterator &other) const;
            bool operator==(const ConstIterator &other) const;

        };
        class Iterator : public ConstIterator {
        public:
            Iterator();
            Iterator(node* value);
            Iterator(const Iterator &other);
            Iterator(const ConstIterator &other);
            ~Iterator() {}
            refernce operator*();
            Iterator operator+(const size_type value);
//            Iterator operator+(Iterator &other);
            Iterator operator-(const size_type value);
            Iterator& operator=(const Iterator other);
        };

    public:
        using iterator = Iterator;
        using const_iterator = ConstIterator;
        iterator begin() const;
//        {
//            return iterator(this->two_with_->next_);
//        }
        iterator end() const;
//        {
//            return iterator(this->two_with_);
//        }
        const_reference front();
//        {
//            return this->two_with_->next_->value_;
//        }
        const_reference back();
//        {
//            return this->two_with_->prev_->value_;
//        }
        size_type  size() const noexcept;
        size_t max_size() const noexcept;
        void clear();
        iterator insert(iterator pos, const_reference value);
        void erase(iterator pos);
        void Swap(list& other);
        void Merge(list& other);
        void Splice(const_iterator pos, list& other);
        void Reverse();
        void Unique();

        void Sort();
        template <typename... Args>
        iterator emplace(const_iterator pos, Args&&... args);
        template <typename... Args>
        void emplace_back(Args&&... args);
        template <typename... Args>
        void emplace_front(Args&&... args);
    private:
        bool is_cicle(node *N);
        void SwapList(list &l);

        void Connect();
        void InitList();

    };

}  //  namespace s21

#include "s21_list.tpp"
#endif // SRC_S21_LIST_H
