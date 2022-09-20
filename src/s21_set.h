#ifndef SRC_S21_SET_H
#define SRC_S21_SET_H
#include <stdexcept>
#include <cmath>
#include <limits>
#include <vector>

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
        set();
        explicit set(std::initializer_list<value_type> const items);
        set(const set& s);
        set(set&& s);
        set<Key>& operator=(set&& s);
        ~set();


    private:
        Tree<Key>* set_node_;
        size_type m_size_;
        void clear(read_black_node& root);
        void init_set();
        read_black_node last_right() const;

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
    };



}  //  namespace s21

#include "s21_set.tpp"
#endif // SRC_S21_LIST_H