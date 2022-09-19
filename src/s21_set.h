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
        bool insert(const value_type&);

    private:
        Tree<Key>* set_node_;
        size_type m_size_;
        void clear(read_black_node& root);
        void init_set();

    };



}  //  namespace s21

#include "s21_set.tpp"
#endif // SRC_S21_LIST_H