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
    public:
        using key_type = Key;
        using mapped_type = Value;
        using value_type = std::pair<key_type, mapped_type>;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = size_t;
        using read_black_node = ReadBlackTree<key_type, mapped_type>*;
    private:
        ReadBlackTree<Key, Value>* root_;
        ReadBlackTree<Key, Value>* nil_;


        void search_in_root(read_black_node& root, key_type key);
        void left_rotate(read_black_node& root, read_black_node& x);
        void right_rotate(read_black_node& root, read_black_node& y);

        void init(Key key, Value value);
        void insert_node(read_black_node& root, read_black_node new_tree);
        void insert_fix(read_black_node& root, read_black_node& node);
        void fix_parent_right(read_black_node& root, read_black_node& parent, read_black_node& grand_parent, read_black_node& node, bool flag);
        void fix_parent_left(read_black_node& root, read_black_node& parent, read_black_node& grand_parent, read_black_node& node, bool flag);



    public:
        Tree();
        Tree(const Tree& other);
        ~Tree();
        void print_tree(read_black_node node);
        
        
};
}//  namespace s21

#include "s21_rbtree.tpp"
#endif // SRC_S21_RBTREE_H
