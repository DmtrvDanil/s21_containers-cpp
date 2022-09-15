#ifndef SRC_S21_SET_H
#define SRC_S21_SET_H
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
namespace s21{
    template<class Key>
    class set {
    public:
        using key_type = Key;
        using value_type = Key;
        using reference = Key&;
        using const_reference = const Key&;
        using size_type = size_t;
    private:
        struct TreeNode {
        public:
//            ~ListNode() {};
            value_type data_;
            TreeNode* left_;
            TreeNode* right_;
            TreeNode() : data_(), left_(nullptr), right_(nullptr) {}
            explicit TreeNode(const const_reference value) : data_(value), left_(nullptr), right_(nullptr) {}
        };
            set();
            ~set();

    };



}  //  namespace s21

#include "s21_list.tpp"
#endif // SRC_S21_LIST_H