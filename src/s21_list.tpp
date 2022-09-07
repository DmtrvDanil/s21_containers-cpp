#include "s21_list.h"

namespace s21{
    template<class value_type>
    list<value_type>::list() {
        this->InitList();
//        std::cout << "Before segmentation fault";
//        this->Connect();
//        std::cout << "Before segmentation fault";
//        this->head_ = nullptr;
//        this->tail_ = nullptr;
//        std::cout << "Before segmentation fault";
//        this->m_size_ = 0;
//        std::cout << "Before segmentation fault";
    }

    template<class value_type>
    list<value_type>::~list() {
        this->clear();
//        delete this->two_with_;
//        this->tail_->prev_->next_ = nullptr;
//        for (node* point = this->head_; point != nullptr; point = point->next_) {
//            delete point;
//        }
    }
    template<class value_type>
    void list<value_type>::InitList() {
//    this->two_with_ = new node();
    this->two_with_ = &this->two_with_1;
    this->two_with_->next_ = this->two_with_;
    this->two_with_->prev_ = this->two_with_;
    this->m_size_ = 0;
    }

    template<class value_type>
    bool list<value_type>::empty() {
//        std::cout << "Before segmentation fault";
//        return this->head_->next_ == this->tail_ ? true : false;
        return this->two_with_->next_ == nullptr;
    }
    template<class value_type>
    void list<value_type>::Connect() {
        this->tail_ = new node;
        this->head_ = this->tail_;
        this->head_->next_ = this->head_->prev_ = this->head_;
        this->tail_->next_ = this->tail_->prev_ = this->tail_;
    }

    template<class value_type>
    void list<value_type>::clear() {
        while (this->m_size_) {
            this->pop_back();
        }
//        delete this->two_with_;
    }

    template<class value_type>
    void list<value_type>::push_back(const_reference value) {
        node* tmp = new node(value);
        if (!tmp)
            throw std::bad_alloc();
        tmp->next_ = this->two_with_;
        tmp->prev_ = this->two_with_->prev_;
        this->two_with_->prev_->next_ = tmp;
        this->two_with_->prev_ = tmp;
        this->m_size_++;
    }

    template<class value_type>
    void list<value_type>::push_front(const_reference value) {
        node* tmp = new node(value);
        if (!tmp)
            throw std::bad_alloc();
        tmp->prev_ = this->two_with_;
        tmp->next_ = this->two_with_->next_;
        this->two_with_->next_->prev_ = tmp;
        this->two_with_->next_ = tmp;
        this->m_size_++;

    }

    template<class value_type>
    typename list<value_type>::size_type list<value_type>::size() {
        size_type size = 0U;
        node* temp = this->two_with_->next_;
        while(temp != two_with_) {
            size++;
            temp = temp->next_;
        }
        return size;
    }

//
//    template<class value_type>
//    void list<value_type>::push_back(const_reference value) {
//       node* tmp = new node;
//       tmp->value_ = value;
//       tmp->next_ = head_;
//       tmp->prev_ = nullptr;
//       (!this->empty()) ? this->head_->prev_ = tmp : this->tail_ = tmp;
//        this->head_ = tmp;
//        this->m_size_++;
//    }

    template<class value_type>
    void list<value_type>::pop_back() {
        if (this->empty())
            throw std::invalid_argument("the list is empty");
        node* tmp;
        tmp = this->two_with_->prev_;
        this->two_with_->prev_ = this->two_with_->prev_->prev_;
        this->two_with_->prev_->next_ = this->two_with_;
        delete tmp;
        this->m_size_--;

    }




//    template <typename T>
//    void list<T>::push_back(const_reference value) {
//        node* new_node = new node;
//        new_node->value_ = value;
//        this->_push_node(new_node, this->tail_->prev_, this->_tail);
//    }
//
//    template <typename T>
//    void list<T>::push_front(const_reference value) {
//        node* new_node = new node;
//        new_node->value_ = value;
//        this->_push_node(new_node, this->head_, this->head_->next_);
//    }
//
//    template <typename T>
//    void list<T>::_push_node(node* node_to_push, node* left_node, node* right_node) {
//        node_to_push->next_ = right_node;
//        node_to_push->prev_ = left_node;
//        left_node->next_ = node_to_push;
//        right_node->prev_ = node_to_push;
//    }

}  // namespace s21