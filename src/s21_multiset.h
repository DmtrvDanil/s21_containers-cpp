#ifndef S21_MULTISET_H
#define S21_MULTISET_H
#include "s21_set.h"
namespace s21 {
    template<typename Key>
    class multiset : public set<Key> {
        public:
            using key_type = typename set<Key>::key_type;
            using value_type = typename set<Key>::value_type;
            using reference = typename set<Key>::reference;
            using const_reference = typename set<Key>::const_reference;
            using size_type = typename set<Key>::size_type;
            using Allocator = typename set<Key>::Allocator;
            Allocator allocator;
            using iterator = typename set<Key>::iterator;
            using const_iterator = typename set<Key>::const_iterator;

            multiset();
//            explicit multiset(std::initializer_list<value_type> const& items);
//            multiset(const multiset& s);
//            multiset(multiset&& s);
            ~multiset();
//            multiset<key_type>& operator=(multiset&& s);
//            multiset<key_type>& operator=(const multiset& s);
//
//            iterator begin();
//            iterator end();
//
//            bool empty();
//            /* size_type size(); */
//            size_type max_size();
//
//            void clear();
            std::pair<iterator, bool> insert(const value_type& value);
//            void erase(iterator pos);
//            void swap(multiset& other);
//            void merge(multiset& other);
//
//            iterator find(const key_type& key);
//            bool contains(const key_type& key);
//
//            size_type count(const key_type& key);
//            std::pair<iterator, iterator> equal_range(const key_type& key);
//            iterator lower_bound(const key_type& key);
//            iterator upper_bound(const key_type& key);
//
//            template<class... Args>
//            std::vector<std::pair<iterator, bool>> emplace(Args&&... args);

           

    } ;


}  // namespace s21

#include "s21_multiset.tpp"
#endif //  S21_MULTISET_H
