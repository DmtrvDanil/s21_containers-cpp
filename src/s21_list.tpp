#include "s21_list.h"

namespace s21{
    template<class value_type>
    list<value_type>::list() {
        this->head_ = nullptr;
        this->tail_ = nullptr;
        this->m_size_ = 0;
    }

    template<class value_type>
    list<value_type>::~list() {
        this->tail_->prev_->next_ = nullptr;
        for (node* point = this->head_; point != nullptr; point = point->next_) {
            delete point;
        }
    }



}  // namespace s21