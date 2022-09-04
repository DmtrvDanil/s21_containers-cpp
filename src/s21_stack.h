#ifndef SRC_S21_STACK_H
#define SRC_S21_STACK_H
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "vector.h"

namespace s21 {
    template<class T,class Container = s21::Vector<T> >
        class stack {
        public:
            using pointer = typename Container::pointer;
            using const_pointer = typename Container::const_pointer;
            using value_type = typename Container::value_type;
            using reference = typename Container::reference;
            using const_reference = typename Container::const_reference;
            using size_type = typename Container::size_type;
        protected:
            Container c;
        public:
            stack() : c() {}
            stack(std::initializer_list<value_type> const &items) : c(items) {}
            stack(const stack &s) : c(s) {}
            stack(stack &&s) : c(s) {}
            ~stack() {}
            stack &operator=(stack &&s) {
                this->c  = std::move(s.c);
            }
            const_reference top() {
                return c.back();
            }
            bool empty() {
                return c.empty();
            }
            size_type size() {
                return c.size();
            }
            void push(const_reference value) {
                this->c.push_back(value);
            }
            void pop() {
                this->c.pop_back();
            }
            void swap(stack& other) {
                this->c.swap(other.c);
            }

        };


} //  namespace s21

#include "s21_stack.tpp"
#endif  // SRC_S21_STACK_H