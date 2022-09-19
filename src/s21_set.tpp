#include "s21_set.h"
namespace s21{
    template<class key_type>
    set<key_type>::set() {
        this->init_set();
        this->set_node_->print_tree(this->set_node_);
    }

    template<class key_type>
    set<key_type>::~set() {
        if (this->set_node_ != nullptr) {
            read_black_node root = this->set_node_->get_root();
            if (root) {
                this->clear(root);
            }
            delete this->set_node_;
        }
    }

    template<class key_type>
    void set<key_type>::init_set() {
        this->set_node_ = new Tree<key_type>();
        this->m_size_ = 0;
    }

    template<class key_type>
    void set<key_type>::clear(read_black_node& root) {
        if (root != nullptr) {
            this->clear(root->right_);
            this->clear(root->left_);
            delete root;
            this->m_size_--;
        }
    }



} //  namespace s21