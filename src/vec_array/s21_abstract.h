#ifndef SRC_S21_ABSTRACT_H_
#define SRC_S21_ABSTRACT_H_
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace s21 {
    template <class T>
    class abstract {
    protected:
        abstract() {}
        T *arr_;
        size_t m_size_;
    public:
        using pointer = T*;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;
        class VectorConstIterator {
        public:
            VectorConstIterator();
            VectorConstIterator(pointer pt);
            VectorConstIterator(const VectorConstIterator &other) : data_(other.data_) {}
            ~VectorConstIterator() {}
            VectorConstIterator& operator++();
            VectorConstIterator operator++(int);
            VectorConstIterator& operator--();
            VectorConstIterator operator--(int);
            const_reference operator*();
            VectorConstIterator operator+(const size_t value);
            bool operator!=(const VectorConstIterator &other) const;
            bool operator==(const VectorConstIterator &other) const;
        protected:
            pointer data_;

        };
        class VectorIterator : public VectorConstIterator {
        public:
            VectorIterator();
            VectorIterator(pointer pt);
            VectorIterator(const VectorIterator &other) : VectorConstIterator(other) {}
            VectorIterator(const VectorConstIterator &other) : VectorConstIterator(other)  {}
            ~VectorIterator() {}
            reference operator*() ;
            VectorIterator& operator=(const value_type val);
            VectorIterator operator+(const size_t value);
            VectorIterator operator-(const size_t value);
            VectorIterator operator-(const VectorIterator &value);
        };
        using iterator = VectorIterator;
        using const_iterator = VectorConstIterator;

        reference at(size_type pos);
        reference operator[](size_type pos);
        const_reference front();
        const_reference back();
        iterator data();

        iterator  begin();
        iterator  end();

        bool empty();
        size_type size();
       virtual size_type max_size();

    };

}  // namespace

#include "s21_abstract.cpp"
#endif // SRC_S21_ABSTRACT_H_
