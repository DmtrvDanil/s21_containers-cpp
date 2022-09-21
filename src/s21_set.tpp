#include "s21_set.h"
namespace s21{
    template<class key_type>
    set<key_type>::set() {
        this->init_set();
    }

    template<class key_type>
    set<key_type>::set(std::initializer_list<value_type> const& items) {
//        this->set_node_ = new Tree<key_type>();
//        Tree<key_type>* tmp = this->set_node_;
//        this->m_size_ = std::count_if(items.begin(), items.end(),
//                                 [tmp](key_type i) { return tmp->insert(i, WITHOUT_DUPLICATE, 0); });

        this->init_set();
        for (auto i = items.begin(); i != items.end(); ++i) {
           this->insert(*i);
        }
    }

    template<class key_type>
    set<key_type>::set(const set<key_type> &s) {
        *this = s;
    }

    template<class key_type>
    set<key_type>::set(set<key_type> &&s) {
        this->init_set();
        if (this != &s) {
            *this = s;
//            this->swap(s);
        }
    }

    template<class key_type>
    set<key_type>& set<key_type>::operator=(const set<key_type> &s) {
        this->init_set();
        read_black_node tmp = s.set_node_->get_root();
        this->copy_set(tmp);
        this->m_size_ = s.m_size_;
        return *this;
    }

    template<class key_type>
    void set<key_type>::copy_set(read_black_node &root) {
        if (root != nullptr) {
            copy_set(root->left_);
            key_type value = root->data_.first;
            this->insert(value);
            copy_set(root->right_);
        }
    }

    template<class key_type>
    set<key_type>& set<key_type>::operator=(set<key_type> &&s) {
        if (this != &s) {
            this->clear();
            this->swap(s);
        }
        return *this;
    }

    template<class key_type>
    set<key_type>::~set() {
        this->clear();
//        if (this->set_node_ != nullptr) {
//            read_black_node root = this->set_node_->get_root();
//            if (root) {
//                this->destr(root);
//            }
//            delete this->set_node_;
//        }
    }

    template<class key_type>
    bool set<key_type>::empty() {
        return (this->m_size_ == 0 )? true : false;
    }

    template<class key_type>
    typename set<key_type>::size_type set<key_type>::size() {
//        size_type count = 0;
//        while(this->set_node_->get_root()) {
//
//        }
        return this->m_size_;
    }

    template<class key_type>
    typename set<key_type>::size_type set<key_type>::max_size() {
        return allocator.max_size();

    }

    template<class key_type>
    void set<key_type>::clear() {
        if (this->set_node_ != nullptr) {
            read_black_node root = this->set_node_->get_root();
            if (root) {
                this->destr(root);
            }
            delete this->set_node_;
        }
        this->set_node_ = nullptr;

    }

    template<class key_type>
    void set<key_type>::swap(set<key_type>& other) {
        std::swap(this->set_node_, other.set_node_);
        std::swap(this->m_size_, other.m_size_);
    }

    template<class key_type>
    void set<key_type>::merge(set<key_type> &other) {
        iterator iter = other.begin();
        while (iter != other.end()) {
            this->insert(*iter);
            other.erase(iter);
            iter++;
        }
    }

    template<class key_type>
    bool set<key_type>::contains(const key_type &key) {
        return  this->set_node_->search(key) != nullptr;
    }

    template<class key_type>
    typename set<key_type>::iterator set<key_type>::begin() {
        read_black_node tmp = this->set_node_->get_root();
        if (tmp) {
            while (tmp->left_) {
                tmp = tmp->left_;
            }
        } else {
            tmp = this->set_node_->get_nil();
        }
        return iterator(tmp, this->set_node_->get_nil(), last_right());
    }

    template<class key_type>
    typename set<key_type>::iterator set<key_type>::end() {
        read_black_node nil = this->set_node_->get_nil();
        return iterator(nil, nil, last_right());
    }

    template<class key_type>
    std::pair<typename set<key_type>::iterator, bool> set<key_type>::insert(const value_type &value) {
        std::pair<iterator, bool> result;
        if (this->set_node_->insert(value, WITHOUT_DUPLICATE, 0)) {
            this->m_size_++;
            result = std::pair<iterator, bool>(find(value), true);

        } else {
            result = std::pair<iterator, bool>(find(value), false);
        }
        return result;
    }

    template<class key_type>
    void set<key_type>::erase(iterator pos) {
        this->set_node_->remove(*pos);
        this->m_size_--;
    }

    template<class key_type>
    typename set<key_type>::iterator set<key_type>::find(const key_type &key) {
        read_black_node tmp = this->set_node_->search(key);
        if (tmp == nullptr) {
            tmp = this->set_node_->get_nil();
        }
        iterator res(tmp, this->set_node_->get_nil(), last_right());
        return res;
    }

    template<class key_type>
    void set<key_type>::init_set() {
        this->set_node_ = new Tree<key_type>();
        this->m_size_ = 0;
    }

    template<class key_type>
    void set<key_type>::destr(read_black_node& root) {
        if (root != nullptr) {
            this->destr(root->left_);
            this->destr(root->right_);
            delete root;
            this->m_size_--;
        }
    }

    template<class key_type>
    typename set<key_type>::read_black_node set<key_type>::last_right() const {
        read_black_node tmp = this->set_node_->get_root();
        while (tmp && tmp->right_) {
            tmp = tmp->right_;
        }
        return tmp;
    }

    // ConstIterator
    template<class key_type>
    typename set<key_type>::read_black_node set<key_type>::ConstIterator::next_value() {
        if (this->node_have_right()) {
            this->data_ = this->data_->right_;
            while (this->data_->left_) {
                this->data_ = this->data_->left_;
            }
        } else if (this->node_have_father_left()) {
            this->data_ = this->data_->parent_;
        } else if (this->node_have_grand_father_n_father_left()) {
            this->data_ = this->data_->parent_->parent_;
        } else if (this->data_ == this->nil_) {
            this->data_ = this->last_;
        } else {
            this->data_ = this->nil_;
        }
        return this->data_;
    }

    template<class key_type>
    bool set<key_type>::ConstIterator::node_have_left() {
        return this->data_->left_;
    }

    template<class key_type>
    bool set<key_type>::ConstIterator::node_have_father_right() {
        return this->data_->parent_ && this->data_->parent_->right_ == this->data_;
    }

    template<class key_type>
    bool set<key_type>::ConstIterator::node_have_grand_father_n_father_right()  {
        return this->data_->parent_ && this->data_->parent_->left_ == this->data_ && this->data_->parent_->parent_ &&
                     this->data_->parent_ == this->data_->parent_->parent_->right_;
    }

    template<class key_type>
    bool set<key_type>::ConstIterator::node_have_right() {
        return this->data_->right_;
    }

    template<class key_type>
    bool set<key_type>::ConstIterator::node_have_father_left() {
        return this->data_->parent_ && this->data_->parent_->left_ == this->data_;
    }

    template<class key_type>
    bool set<key_type>::ConstIterator::node_have_grand_father_n_father_left()  {
        return this->data_->parent_ && this->data_->parent_->right_ == this->data_ && this->data_->parent_->parent_ &&
               this->data_->parent_ == this->data_->parent_->parent_->left_;
    }

    template<class key_type>
    typename set<key_type>::read_black_node set<key_type>::ConstIterator::prev_value() {
        if (this->node_have_left()) {
            this->data_ = this->data_->left_;
            while (this->data_->right_) {
                this->data_ = this->data_->right_;
            }
        } else if (this->node_have_father_right()) {
            this->data_ = this->data_->parent_;
        } else if (this->node_have_grand_father_n_father_right()) {
            this->data_ = this->data_->parent_->parent_;
        }  else if (this->data_ == this->nil_) {
            this->data_ = this->last_;
        } else {
            this->data_ = this->nil_;
        }
        return this->data_;

    }

    template<class key_type>
    typename set<key_type>::ConstIterator& set<key_type>::ConstIterator::operator++() {
        this->data_ = this->next_value();
        return *this;
    }

    template<class key_type>
    typename set<key_type>::ConstIterator& set<key_type>::ConstIterator::operator--() {
        this->data_ = this->prev_value();
        return *this;
    }
    template<class key_type>
    typename set<key_type>::ConstIterator set<key_type>::ConstIterator::operator--(int) {
        auto iter = *this;
        --(*this);
        return iter;

    }


    template<class key_type>
    typename set<key_type>::ConstIterator set<key_type>::ConstIterator::operator++(int) {
        auto iter = *this;
        ++(*this);
        return iter;

    }

    template<class key_type>
    template<class... Args>
    std::vector<std::pair<typename set<key_type>::iterator, bool>> set<key_type>::emplace(Args &&...args) {
        std::vector<std::pair<iterator, bool>> result;
        std::vector<typename set<key_type>::value_type> argsVector = {args...};
        for (auto& i : argsVector) {
            result.push_back(insert(i));
        }
        return result;
    }



} //  namespace s21