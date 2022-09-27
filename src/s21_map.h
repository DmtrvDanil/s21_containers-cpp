#ifndef  S21_MAP_H
#define  S21_MAP_H
# include "s21_set.h"

namespace s21 {

template <class Key, class Value, class Compare = std::less<Key>
        >
class map {


public:
    using key_type = Key;
    using mapped_type = Value;
    using value_type = std::pair<key_type, mapped_type>;
    map() : c() {}

    ~map() {}



    class value_compare {
        bool operator()( const value_type& lhs, const value_type& rhs ) {
            return comp(lhs.first, rhs.first);
        }
    private:
        value_compare() : comp(Compare()) {}
        Compare comp;
    };

private:
    set<value_type, value_compare> c;
public:
    class ConstIterator : public set<value_type, value_compare>::ConstIterator {
    public:
        using set_iterator = typename set<value_type, value_compare>::ConstIterator;
        ConstIterator(const set_iterator& other) : set_iterator(other) {}

        value_type* operator->() { return &(this->data_->data_); }

    };
    class Iterator : public ConstIterator {
    public:
        using set_iterator = typename ConstIterator::set_iterator;
        Iterator(const set_iterator& other) : ConstIterator(other) {}

    };
    using const_iterator = ConstIterator;
    using iterator = Iterator;


public:
//    using iterator = typename  set<value_type, value_compare>::Iterator;
//    using const_iteratpr = typename set<value_type, value_compare>::ConstIterator;
    std::pair<iterator, bool> insert(const value_type& value){
        auto pair_set =  c.insert(value);
        iterator iter(pair_set.first);
        return  std::make_pair(iter, pair_set.second);
    }
    iterator begin() {
        iterator iter(c.begin());
        return iter;
    }
    iterator end() {
        return c.end();
    }
};

} // namespace s21

#endif