#ifndef  S21_MAP_H
#define  S21_MAP_H
# include "s21_set.h"

namespace s21 {

template <class Key, class Value, class Compare>
class map {
public:
    using key_type = Key;
    using mapped_type = Value;
    using value_type = std::pair<key_type, mapped_type>;


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
};

} // namespace s21

#endif