#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_

#include <iostream>
#include <stdexcept>

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
        
        // using const_iterator = const T *;
        using size_type = size_t;
    private:
        void reserve_more_capacity(size_type size);
    public:
    class VectorConstIterator;
    using const_iterator = VectorConstIterator;
    class VectorIterator;
    using iterator = VectorIterator;
        Vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr) {}
        explicit Vector(size_type n) : m_size_(n), m_capacity_(n), arr_(n ? new T[n] : nullptr) {}
        Vector(std::initializer_list<value_type> const &items);
        Vector(const Vector &v) : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_) {};
        Vector(Vector &&v) : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_) {
            v.arr_ = nullptr;
            v.m_size_ = 0;
            v.m_capacity_ = 0;
        }
        ~Vector() { clear();}
        

        // Vector& operator=(vector &&v);
        reference operator[](size_type i);
        Vector operator=(Vector &&v);
        size_type size();
        reference at(size_type i);
        void push_back(value_type v);
        void pop_back();
        void swap(Vector& other);

        void clear();
        bool empty();
        void output_vector();
        iterator begin();
        iterator end();

 };

template <class T>
class Vector<T>::VectorIterator {
            protected:
                pointer data_;
                size_type position_;
                size_type size_of_vector_;
            public:
                VectorIterator() : position_(0U), size_of_vector_(0U), data_(nullptr) {}
                VectorIterator(const iterator& other) : position_(other.position_), size_of_vector_(other.size_of_vector_), data_(other.data_) {}
                VectorIterator(const Vector &vec, size_type position);
                ~VectorIterator() {}
                VectorIterator& operator++();
                VectorIterator operator++(int);
                VectorIterator& operator--();
                VectorIterator operator--(int);
                bool operator==(iterator& other);
                bool operator!=(iterator& other);
                // value_type operator*();


                // operator VectorIterator() const { return VectorIterator(data_); }
            private:
                iterator& operator=(const const_iterator& other);
                reference operator*();
        };

template <class T>
class Vector<T>::VectorConstIterator : public Vector<T>::VectorIterator {
    public:
    // VectorConstIterator();
    // VectorConstIterator();
    // VectorConstIterator();

};






 }  // namespace s21


#endif  //  SRC_VECTOR_H_
