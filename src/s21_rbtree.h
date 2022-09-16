#ifndef SRC_S21_RBTREE_H
#define SRC_S21_RBTREE_H
#include <iostream>
#include <string>
#include <utility>

namespace s21 {
    enum NodeColor { BLACK, READ };

    template <class Key, class Value>
        struct ReadBlackTree {
        public:
            std::pair<Key, Value> data_;
            NodeColor color_;
            ReadBlackTree<Key, Value> *left_;
            ReadBlackTree<Key, Value> *right_;
            ReadBlackTree<Key, Value> *parent_;
            ReadBlackTree() : data_(), color_(BLACK), left_(nullptr), right_(nullptr), parent_(nullptr) {}

        };
    template<class Key, class Value>
    class Tree {
    private:
        ReadBlackTree<Key, Value>* root_;
        ReadBlackTree<Key, Value>* nil_;
        void insert_node(ReadBlackTree<Key, Value>& root, ReadBlackTree<Key, Value> new_tree);
        void init(Key key, Value value);
    public:
        Tree();
        Tree(const Tree& other);
        ~Tree();
        
        
};
}//  namespace s21

#include "s21_rbtree.tpp"
#endif // SRC_S21_RBTREE_H
