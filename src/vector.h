#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_
#include "s21_abstract.h"
//#include <iostream>
//#include <stdexcept>
//#include <cmath>

namespace s21 {

    template <class T>
    class Vector : public abstract<T>{
    private:
//        size_t m_size_;
        size_t m_capacity_;
//        T *arr_;
    public:




//        class VectorConstIterator {
//        public:
////            using pointer = T*;
////            using value_type = T;
////            using reference = T&;
////            using const_reference = const T&;
//
//        public:
//            VectorConstIterator() : data_(nullptr) {}
//            VectorConstIterator(pointer pt) : data_(pt) {}
//            ~VectorConstIterator() {}
//            VectorConstIterator& operator++() {
//                this->data_++;
//                return *this;
//            }
//            VectorConstIterator operator++(int) {
//                VectorConstIterator temp(*this);
//                this->data_++;
//                return temp;
//            }
//            const_reference operator*() {return *this->data_;}
//            VectorConstIterator operator+(const size_t value) {
//                VectorConstIterator it_const(this->data_ + value);
//                return it_const;
//            };
//
//        protected:
//            pointer data_;
//
//        };
//
//        class VectorIterator_1 : public VectorConstIterator {
//        public:
//            VectorIterator_1() : VectorConstIterator() {}
//            VectorIterator_1(pointer pt) : VectorConstIterator(pt) {}
//            ~VectorIterator_1() {}
//            reference operator*() {return *this->data_;}
//            VectorIterator_1& operator=(const value_type val) {
//                *this->data_ = val;
//                return *this->data_;
//            };
//            VectorIterator_1 operator+(const size_t value) {
//                VectorIterator_1 it(this->data_ + value);
//                return it;
//            };
//
//        };
        using pointer = typename abstract<T>::pointer;
        using value_type = typename abstract<T>::value_type;
        using reference = typename abstract<T>::reference;
        using const_reference = typename abstract<T>::const_reference;
        using iterator_2 = typename abstract<T>::VectorIterator_1;
        using const_iterator_2 = typename abstract<T>::VectorConstIterator;

//        iterator_2 begin_4() {
//            iterator_2 temp(this->arr_);
//            return temp;
//        }
//
//        iterator_2 end_4() {
//            iterator_2 temp(this->arr_ + this->m_size_);
//            return temp;
//        }
        // using const_iterator = const T *;
        using size_type = size_t;
    private:
        void reserve_more_capacity(size_type size, bool shrink);
    public:

//    class VectorConstIterator;
//    using const_iterator = VectorConstIterator;

    class VectorIterator;
    using iterator = VectorIterator;

    using iterator_ = T*;
        Vector() {
            this->arr_ = nullptr;
            this->m_capacity_ = 0;
            this->m_size_ = 0;
        }
//        Vector() : this->m_size_(0U), this->m_capacity_(0U), this->arr_(nullptr) {}
//        explicit Vector(size_type n) : m_size_(n), m_capacity_(n), arr_(n ? new T[n] : nullptr) {}
        explicit Vector(size_type n) {
        this->m_size_ = n;
        this->m_capacity_ = n;
        this->arr_ = n ? new T[n] : nullptr; }
        Vector(std::initializer_list<value_type> const &items);
//        Vector(const Vector &v) : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_) {};
        Vector(const Vector &v)  {
            this->m_size_ = v.m_size_;
            this->m_capacity_ = v.m_capacity_;
            this->arr_ = v.arr_;
        };
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
//        iterator_1 test_insert(iterator_1 pos, const_reference value);

        void erase(iterator_2 pos);
        void clear_all();

        bool empty();
        void output_vector();
        void bring_to_zero();
        iterator begin();
        iterator end();

//
//        iterator_1 begin_1() noexcept { return this->arr_ ;};
//        iterator_1 end_1() noexcept { return  this->arr_ +  this->m_size_;};
//        const_iterator_1 begin_1() noexcept { return const_iterator_1(&this->arr_ );};
//        const_iterator_1 end_1() noexcept { return  const_iterator_1(&this->arr_ +  this->m_size_);};

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

//        friend Vector::const_iterator;
        iterator& operator=(const iterator &other);
        iterator& operator+=(const iterator &other);
    };

//    template <class T>
//    class Vector<T>::VectorConstIterator : public Vector<T>::VectorIterator {
//    public:
//
//        VectorConstIterator();
//        VectorConstIterator(pointer pt);
//        VectorConstIterator(const iterator &other);
//        ~VectorConstIterator() {};
//        reference operator*();
//
//    };

//    template<class valuer>
//    std::ostream& Vector<value_type>::iterator::operator<<(std::ostream& os, iterator iter) {
//        os << iter.data_;
//        return os;
//    }



 }  // namespace s21

#include "vector.cpp"

#endif  //  SRC_VECTOR_H_
