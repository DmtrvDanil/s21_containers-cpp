#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_

#include <iostream>
 
 namespace s21 {


// template <class T> class VectorConstIterator {
//     protected:
//         T 

// };


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
        using iterator = VectorIterator;
        // using const_iterator = const T *;
        using size_type = size_t;
    private:
        void reserve_more_capacity(size_type size);
    public:
        Vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr) {}
        explicit Vector(size_type n) : m_size_(n), m_capacity_(n), arr_(n ? new T[n] : nullptr) {}
        Vector(std::initializer_list<value_type> const &items);
        Vector(const Vector &v) : m_size_(v.m_size), m_capacity_(v.m_capacity), arr_(v.arr) {};
        Vector(Vector &&v) : m_size_(v.m_size), m_capacity_(v.m_capacity), arr_(v.arr) {
            v.arr = nullptr;
            v.m_size = 0;
        }
        ~Vector() { clear();}
        iterator begin() { return iterator(&this->arr_[0]); };


        // Vector& operator=(vector &&v);
        reference operator[](size_type i);
        size_type size();
        void push_back(value_type v);
        void output_vector();
        void clear();
        bool empty();
    public:
        class VectorIterator {
            private:
                pointer data_;
            public:
                VectorIterator() : data_(nullptr) {}
                explicit VectorIterator(pointer *other) : data_(other) {}
                VectorIterator(const VectorIterator &other) : data_(other.data_) {}
                ~VectorIterator() {}
                reference operator++() {
                    return this->data_++

                }


        }

 };

 }  // namespace s21


#endif  //  SRC_VECTOR_H_
