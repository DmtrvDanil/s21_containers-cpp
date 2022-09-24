#include "s21_multiset.h"
namespace s21{
    
    template<class Key>
    multiset<Key>::multiset()  : set<Key>() {}

    template<class key_type>
    multiset<key_type>::~multiset<key_type>() {}

    template<class key_type>
    std::pair<typename multiset<key_type>::iterator, bool> multiset<key_type>::insert(const value_type &value) {
        std::pair<iterator, bool> result;
        if (this->set_node_->insert(value, WITH_DUPLICATE, 0)) {
            this->m_size_++;
            result = std::pair<iterator, bool>(this->find(value), true);
        } else {
            result = std::pair<iterator, bool>(this->find(value), false);
        }
        return result;
    }

    template<class key_type>
    typename multiset<key_type>::iterator multiset<key_type>::lower_bound(const key_type &key) {
        auto result = this->begin();
        for (;result != this->end() && *result < key; result++);
        return result;
    }

    template<class key_type>
    typename multiset<key_type>::iterator multiset<key_type>::upper_bound(const key_type &key) {
        auto result = this->begin();
        for (; result != this->end() && *result <= key; result++);
        return  result;
    }

    template<class key_type>
    std::pair<typename multiset<key_type>::iterator, typename multiset<key_type>::iterator> multiset<key_type>::equal_range(
            const key_type &key) {
        return std::make_pair(this->lower_bound(key), this->upper_bound(key));
    }

}  //  namespace s21
