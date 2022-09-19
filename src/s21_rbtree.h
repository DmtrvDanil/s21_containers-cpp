#ifndef SRC_S21_RBTREE_H
#define SRC_S21_RBTREE_H
#include <iostream>
#include <string>
#include <utility>

namespace s21 {
    enum NodeColor { BLACK, READ };
    enum Duplicate { WITH_DUPLICATE, WITHOUT_DUPLICATE };

    template <typename Key, typename Value = char>
        struct ReadBlackTree {
        public:
            std::pair<Key, Value> data_;
            NodeColor color_;
            ReadBlackTree<Key, Value> *left_;
            ReadBlackTree<Key, Value> *right_;
            ReadBlackTree<Key, Value> *parent_;
            ReadBlackTree() : data_(), color_(BLACK), left_(nullptr), right_(nullptr), parent_(nullptr) {}

        };
    template<class Key, class Value = char>
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


        read_black_node search_in_root(read_black_node& root, key_type key);
        void left_rotate(read_black_node& root, read_black_node& x);
        void right_rotate(read_black_node& root, read_black_node& y);

        void init(Key key, Value value);
        void insert_node(read_black_node& root, read_black_node new_tree);
        void insert_fix(read_black_node& root, read_black_node& node);
        void fix_parent_right(read_black_node& root, read_black_node& parent, read_black_node& grand_parent, read_black_node& node, bool flag);
        void fix_parent_left(read_black_node& root, read_black_node& parent, read_black_node& grand_parent, read_black_node& node, bool flag);

        void remove_node(read_black_node& root, read_black_node& node);
        void remove_node_with_one_child(read_black_node& node, read_black_node& child, read_black_node& father, NodeColor color);
        void find_right_replace(read_black_node& root, read_black_node& replace, read_black_node& node);
        void replace_with_new_node(read_black_node& father, read_black_node& replace, read_black_node& node, read_black_node child);
        void remove_fix(read_black_node& root, read_black_node& node, read_black_node& father);
        bool fix_right_brother(read_black_node& brother, read_black_node& node, read_black_node& father);
        bool fix_left_brother(read_black_node& brother, read_black_node& node, read_black_node father);

    public:
        Tree();
        Tree(const Tree& other);
        Tree& operator=(const Tree& other);
        ~Tree();
        bool insert(key_type key, Duplicate duplc, mapped_type value);
        void print_tree(read_black_node node);
        void remove(key_type key);
        read_black_node search(key_type key);
        read_black_node get_root() { return this->root_;}
        read_black_node get_nil() {return this->nil_;}
        
        
};
}//  namespace s21

#include "s21_rbtree.tpp"
#endif // SRC_S21_RBTREE_H
