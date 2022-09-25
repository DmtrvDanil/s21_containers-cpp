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
    using iterator = typename  set<value_type, value_compare>::Iterator;
    using const_iteratpr = typename set<value_type, value_compare>::ConstIterator;
    std::pair<iterator, bool> insert(const value_type& value){
        return  c.insert(value);
    }
    iterator begin() {
        return c.begin();
    }
    iterator end() {
        return c.end();
    }
};

} // namespace s21

#endif