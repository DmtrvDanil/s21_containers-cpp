#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_

#include <iostream>
#include <stdexcept>
#include <cmath>

namespace s21 {
template <class T> class Vector {
    private:
        size_t m_size_;
        size_t m_capacity_;
        T *arr_;
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using iterator_1 = T*;

        
        // using const_iterator = const T *;
        using size_type = size_t;
    private:
        void reserve_more_capacity(size_type size, bool shrink);
    public:
    class VectorConstIterator;
    using const_iterator = VectorConstIterator;
    class VectorIterator;
    using iterator = VectorIterator;
    using iterator_ = T*;
        Vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr) {}
        explicit Vector(size_type n) : m_size_(n), m_capacity_(n), arr_(n ? new T[n] : nullptr) {}
        Vector(std::initializer_list<value_type> const &items);
        Vector(const Vector &v) : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_) {};
        Vector(Vector &&v);
        ~Vector() { clear_all();}
        void Allocate_Memory();

        // Vector& operator=(vector &&v);
        reference operator[](size_type i);
        Vector operator=(Vector &&v);
        size_type size();
        size_type max_size();
        size_type capacity();

        void push_back(value_type v);
        void pop_back();
        void swap(Vector& other);
        void reserve(size_type size);
        void shrink_to_fit();

        reference at(size_type i);
        const_reference front();
        const_reference back();
        iterator data();

        void clear();
        iterator insert(iterator pos, const_reference value);
        void erase(iterator pos);


        void clear_all();

        bool empty();
        void output_vector();
        void bring_to_zero();
        iterator begin();
        iterator end();
        iterator_1 begin_1() noexcept { return iterator_1(&this->arr_[0]); }
//        friend std::ostream& operator<<(std::ostream& os, const iterator& iter);


 };

    template <class T>
    class Vector<T>::VectorIterator {
    protected:
        pointer data_;

    public:
        VectorIterator() : data_(nullptr) {}
        VectorIterator(pointer pt);
        ~VectorIterator() {}
        VectorIterator& operator++();
        VectorIterator& operator+(const size_t value);
        VectorIterator& operator-(const size_t value);
        bool operator>(const size_t value);
        VectorIterator operator++(int);
        VectorIterator& operator--();
        VectorIterator operator--(int);
        bool operator==(iterator& other);
        bool operator!=(const iterator& other);
        value_type operator*();
//        friend std::ostream& operator<<(std::ostream& os, iterator iter);
    private:
        iterator& operator=(const iterator &other);
        iterator& operator+=(const iterator &other);
    };

    template <class T>
    class Vector<T>::VectorConstIterator : public Vector<T>::VectorIterator {
    public:
        VectorConstIterator() : VectorIterator() {}
        VectorConstIterator(pointer pt) : VectorIterator(pt) {}
        ~VectorConstIterator() {};
    };

//    template<class valuer>
//    std::ostream& Vector<value_type>::iterator::operator<<(std::ostream& os, iterator iter) {
//        os << iter.data_;
//        return os;
//    }



 }  // namespace s21

#include "vector.cpp"

#endif  //  SRC_VECTOR_H_
