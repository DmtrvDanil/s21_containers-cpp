#include "s21_rbtree.h"

namespace s21{

    template<class Key, class Value>
    Tree<Key, Value>::Tree() {
        this->root_ = nullptr;
        this->nil_ = new ReadBlackTree<Key, Value>;
    }


    template<class Key, class Value>
    Tree<Key, Value>::~Tree() {
        delete this->nil_;
    }

    template<class Key, class Value>
    void Tree<Key, Value>::init(Key key, Value value) {
        ReadBlackTree<Key, Value>* tmp_tree = new ReadBlackTree<Key, Value>;
        tmp_tree->color_ = BLACK;
        tmp_tree->left_ = nullptr;
        tmp_tree->right_ = nullptr;
        tmp_tree->parent_ = nullptr;
        tmp_tree->data_.first = key;
        tmp_tree->data_.second = value;


    }

} // namespace s21
