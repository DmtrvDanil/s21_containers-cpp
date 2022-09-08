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
    list<value_type>::list(size_type n) {
        if (n >= max_size())
            throw std::out_of_range("Limit of the container is exceeded");
        this->InitList();
        for (; n > 0; --n) {
            push_back(this->two_with_->value_);
        }

    }

    template<class value_type>
    list<value_type>::list(std::initializer_list<value_type> const &items) {
        this->InitList();
        for (auto &i : items) {
            this->push_back(i);
        }
    }

    template<class value_type>
    list<value_type>::list(const list &l) {
        *this = l;
    }

    template<class value_type>
    list<value_type>::list(list &&l) {
        if (this == &l) {
            throw std::invalid_argument("Error move!");
        }
        this->InitList();
        this->SwapList(std::move(l));
    }

    template<class value_type>
    list<value_type>::~list() {
        this->clear();
        delete this->two_with_;
//        this->tail_->prev_->next_ = nullptr;
//        for (node* point = this->head_; point != nullptr; point = point->next_) {
//            delete point;
//        }
    }

    template<class value_type>
    list<value_type>& list<value_type>::operator=(list &&other) {
        if (this == &other) {
            throw std::invalid_argument("Error move!");
        }
        this->SwapList(std::move(other));
        return *this;
    }

    template<class value_type>
    list<value_type>& list<value_type>::operator=(const list &other) {
        this->InitList();
        if (this != &other) {
//            for (auto iter = l.begin(); iter != l.end(); ++iter) {
//                this->push_back(*iter);
//            }
            node *tmp = other.two_with_->next_;
            if (!tmp) {
                throw std::bad_alloc();}
            for (size_type i = 0; i < other.m_size_; i++)  {
                push_back(tmp->value_);
                tmp = tmp->next_;
            }
        }
        return *this;

    }
    template<class value_type>
    typename list<value_type>::const_reference list<value_type>::front() {
        return this->two_with_->next_->value_;
    }

    template<class value_type>
    typename list<value_type>::const_reference list<value_type>::back() {
        return this->two_with_->prev_->value_;
    }

    template<class value_type>
    typename list<value_type>::iterator list<value_type>::begin() const {
        return iterator(this->two_with_->next_);
    }

    template<class value_type>
    typename list<value_type>::iterator list<value_type>::end() const {
        return iterator(this->two_with_);
    }
    template<class value_type>
    void list<value_type>::InitList() {
    this->two_with_ = new node();
//    this->two_with_ = &this->two_with_1;
    if (!this->two_with_) {
        throw std::bad_alloc();
    }
    this->two_with_->next_ = this->two_with_;
    this->two_with_->prev_ = this->two_with_;
    this->m_size_ = 0;
    }

    template<class value_type>
    bool list<value_type>::empty() const noexcept {
//        std::cout << "Before segmentation fault";
//        return this->head_->next_ == this->tail_ ? true : false;
        return this->two_with_->next_ == nullptr;
    }

    template<class value_type>
    size_t list<value_type>::max_size() const noexcept{
        size_type max_size =
                (std::numeric_limits<size_type>::max() / sizeof(node) / 2);
        return max_size;
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
        if (size() >= max_size())
            throw std::out_of_range("Limit of the container is exceeded");
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
        if (size() >= max_size())
            throw std::out_of_range("Limit of the container is exceeded");
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
    typename list<value_type>::size_type list<value_type>::size()const noexcept {
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

    template<class value_type>
    void list<value_type>::pop_front() {
        if (this->empty()) {
            throw std::invalid_argument("the list is empty");
        }
        node *tmp;
        tmp = this->two_with_->next_;
        this->two_with_->next_ = this->two_with_->next_->next_;
        this->two_with_->next_->prev_ = this->two_with_;
        delete tmp;
        this->m_size_--;
    }
    template<class value_type>
    typename list<value_type>::iterator list<value_type>::insert(iterator pos, const_reference value) {



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

    template<class value_type>
    void list<value_type>::SwapList(list &&l) {
        std::swap(this->two_with_, l.two_with_);
        std::swap(this->m_size_, l.m_size_);
    }

}  // namespace s21