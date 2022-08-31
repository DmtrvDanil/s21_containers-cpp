#ifndef SRC_S21_ABSTRACT_H_
#define SRC_S21_ABSTRACT_H_
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace s21 {
    template <class T> class abstract {
    protected:
        abstract() {}
        T *arr_;
        size_t m_size_;
    public:
        using pointer = T*;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;

        class VectorConstIterator {
        public:
//            using pointer = T*;
//            using value_type = T;
//            using reference = T&;
//            using const_reference = const T&;

        public:
            VectorConstIterator() : data_(nullptr) {}
            VectorConstIterator(pointer pt) : data_(pt) {}
            ~VectorConstIterator() {}
            VectorConstIterator& operator++() {
                this->data_++;
                return *this;
            }
            VectorConstIterator operator++(int) {
                VectorConstIterator temp(*this);
                this->data_++;
                return temp;
            }
            const_reference operator*() {return *this->data_;}
            VectorConstIterator operator+(const size_t value) {
                VectorConstIterator it_const(this->data_ + value);
                return it_const;
            };

        protected:
            pointer data_;

        };

        class VectorIterator_1 : public VectorConstIterator {
        public:
            VectorIterator_1() : VectorConstIterator() {}
            VectorIterator_1(pointer pt) : VectorConstIterator(pt) {}
            ~VectorIterator_1() {}
            reference operator*() {return *this->data_;}
            VectorIterator_1& operator=(const value_type val) {
                *this->data_ = val;
                return *this->data_;
            };
            VectorIterator_1 operator+(const size_t value) {
                VectorIterator_1 it(this->data_ + value);
                return it;
            };

        };
        using iterator_2 = VectorIterator_1;
        using const_iterator_2 = VectorConstIterator;
        iterator_2 begin_4() {
            iterator_2 temp(this->arr_);
            return temp;
        }

        iterator_2 end_4() {
            iterator_2 temp(this->arr_ + this->m_size_);
            return temp;
        }


    };


}  // namespace


#endif // SRC_S21_ABSTRACT_H_
