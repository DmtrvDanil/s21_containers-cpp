#include "s21_multiset.h"
namespace s21{
    
    template<class key_type>
    multiset<key_type>::multiset() : set<key_type>() {}

    template<class key_type>
    multiset<key_type>::~multiset<key_type>() {}

    template<class key_type>
    std::pair<typename multiset<key_type>::iterator, bool> multiset<key_type>::insert(const value_type &value) {
        std::pair<iterator, bool> result;
        if (this->set_node_->insert(value, WITH_DUPLICATE, 0)) {
            result = std::pair<iterator, bool>(this->find(value), true);
        } else {
            result = std::pair<iterator, bool>(this->find(value), false);
        }
        return result;
    }

}  //  namespace s21
