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

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::insert_fix(read_black_node &root, read_black_node &node) {
        read_black_node parent = node->parent_;
        bool flag = true;
        while (node != this->root_ && parent->color_ == READ) {
            read_black_node grand_parent = parent->parent_;
            if (parent == grand_parent->left_) {
                this->fix_parent_left(root, parent, grand_parent, node, flag);
            } else {
                this->fix_parent_right(root, parent, grand_parent, node, flag);
            }
        }
        this->root_->color_ = BLACK;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::fix_parent_right(read_black_node &root, read_black_node &parent,
                                                       read_black_node &grand_parent, read_black_node &node,
                                                       bool flag) {
        read_black_node uncle = grand_parent->left;
        if (uncle != nullptr && uncle->color == true) {
            parent->color = false;
            uncle->color = false;
            grand_parent->color = true;
            node = grand_parent;
            parent = node->parent;
        } else {
            if (parent->left == node) {
                right_rotate(root, parent);
                std::swap(node, parent);
            }
            parent->color = false;
            grand_parent->color = true;
            left_rotate(root, grand_parent);
            flag = false;
        }
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::fix_parent_left(read_black_node &root, read_black_node &parent,
                                                      read_black_node &grand_parent, read_black_node &node, bool flag) {
        read_black_node uncle = grand_parent->right;
        if (uncle != nullptr && uncle->color == true) {
            parent->color = false;
            uncle->color = false;
            grand_parent->color = true;
            node = grand_parent;
            parent = node->parent;
        } else {
            if (parent->right == node) {
                left_rotate(root, parent);
                std::swap(node, parent);
            }
            parent->color = false;
            grand_parent->color = true;
            right_rotate(root, grand_parent);
            flag = false;
        }
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::search_in_root(read_black_node &root, key_type key) {
        read_black_node result = root;
        if (root == nullptr || root->data_.first == key) {
            return result;
        }
        if (root->data_.first > key) {
            return this->search_in_root(root->left_, key);
        }
        else {
            return this->search_in_root(root->right_, key);
        }
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::left_rotate(read_black_node &root, read_black_node &x) {
        read_black_node y = x->right_;
        x->right_ = y->left_;
        if (y->left_ != nullptr) {
            y->left_->parent_ = x;
        }
        y->parent_ = x->parent_;
        if (x->parent_ == nullptr) {
            root = y;
        }
        else {
            if (x == x->parent_->left_) {
                x->parent_->left_ = y;
            } else {
                x->parent_->right_ = y;
            }
        }
        y->left_ = x;
        x->parent_ = y;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::right_rotate(read_black_node &root, read_black_node &y) {
        read_black_node x = y->left_;
        y->left_ = x->right_;
        if (x->right_ != nullptr) {
            x->right_->parent_ = y;
        }
        x->parent_ = y->parent_;
        if (y->parent_ == nullptr) {
            if (y == y->parent_->right_) {
                y->parent_->right_ = x;
            } else {
                y->parent_->left_ = x;
            }
        }
        x->right_ = y;
        y->right_ = x;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::print_tree(read_black_node node) {
        if (node != nullptr){
            print_tree(node->left_);
            std::cout << root_->data_.first << " ";
            print_tree(node->right_);
        }
    }

} // namespace s21
