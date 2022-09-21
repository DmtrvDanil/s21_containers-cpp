#ifndef SRC_S21_SET_H
#define SRC_S21_SET_H
#include <stdexcept>
#include <cmath>
#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>

#include "s21_rbtree.h"

namespace s21{
    template<class Key>
    class set {
    public:
        using key_type = Key;
        using value_type = Key;
        using reference = Key&;
        using const_reference = const Key&;
        using size_type = size_t;
        using read_black_node = ReadBlackTree<key_type>*;
        using Allocator = std::allocator<ReadBlackTree<key_type>>;
        Allocator allocator;
        set();
        explicit set(std::initializer_list<value_type>  const& items);
        set(const set& s);
        set(set&& s);
        set<key_type>& operator=(set&& s);
        set<key_type>& operator=(const set& s);
        ~set();

        bool empty();
        size_type size();
        size_type max_size();

        void clear();
        void swap(set &other);
        void merge(set& other);



    private:
        Tree<Key>* set_node_;
        size_type m_size_;
        void destr(read_black_node& root);
        void init_set();
        read_black_node last_right() const;
        void copy_set(read_black_node& root);

    public:
        class ConstIterator {
        protected:
            read_black_node data_;
            read_black_node nil_;
            read_black_node last_;
        public:
            ConstIterator() : data_(nullptr), nil_(nullptr), last_(nullptr) {}
            ConstIterator(read_black_node ptr, read_black_node nil, read_black_node last) : data_(ptr), nil_(nil), last_(last) {}
            ConstIterator(const ConstIterator& other) : data_(other.data_), nil_(other.nil_), last_(other.last_) {}
            ~ConstIterator() {}
            const_reference operator*() {return this->data_->value.first;}
            bool operator!=(const ConstIterator& other) { return this->data_ != other.data_;}
            bool operator ==(const ConstIterator& other) { return this->data_ == other.data_;}
            ConstIterator& operator++();
            ConstIterator operator++(int);
            ConstIterator& operator--();
            ConstIterator operator--(int);
            read_black_node get_nil() { return this->nil_;}
            read_black_node get_data() { return this->data_;}

        private:
            read_black_node next_value();
            read_black_node prev_value();

            //--
            bool node_have_left();
            bool node_have_father_right();
            bool node_have_grand_father_n_father_right();

            //++
            bool node_have_right();
            bool node_have_father_left();
            bool node_have_grand_father_n_father_left();



        };
        class Iterator : public ConstIterator {
        public:
            Iterator() : ConstIterator() {}
            Iterator(read_black_node ptr, read_black_node nil, read_black_node last) : ConstIterator(ptr, nil, last) {}
            Iterator(const Iterator& other) : ConstIterator(other) {}
            ~Iterator() {}
            reference operator*() {return this->data_->data_.first;}


        };

    public:
        using iterator = Iterator;
        using const_iterator = ConstIterator;
        iterator begin();
        iterator end();
        std::pair<iterator, bool> insert(const value_type&);
        iterator find(const Key& key);
        void erase(iterator pos);
    };



}  //  namespace s21

#include "s21_set.tpp"
#endif // SRC_S21_LIST_H