#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_
#include "vec_array/s21_abstract.h"

namespace s21 {
    template <class T>
    class Vector : public abstract<T> {

    public:
        using pointer = typename abstract<T>::pointer;
        using value_type = typename abstract<T>::value_type;
        using reference = typename abstract<T>::reference;
        using const_reference = typename abstract<T>::const_reference;
        using size_type = typename abstract<T>::size_type;
        using const_iterator = typename abstract<T>::VectorConstIterator;
        using iterator = typename abstract<T>::VectorIterator;
        Vector();
        explicit Vector(size_type n);
        Vector(std::initializer_list <value_type> const &items);
        Vector(const Vector &v);
        Vector(Vector &&v);
        ~Vector() { clear_all(); }
        void memory();
        Vector &operator=(const Vector &v);
        Vector &operator=(Vector &&v);
    private:
        void reserve_more_capacity(size_type size, bool shrink);
        size_t m_capacity_;

    public:
//        using iterator_ = T *;
        size_type capacity();
        void push_back(value_type v);
        void pop_back();
        void swap(Vector &other);
        void reserve(size_type size);
        void shrink_to_fit();
        void clear();
        iterator insert(iterator pos, const_reference value);
        iterator insert_2(iterator pos, const_reference value);
        void erase(iterator pos);
        void clear_all();
        void output_vector();
        void bring_to_zero();

        void test(iterator i);

//    template <class T>
//    class Vector<T>::VectorIterator {
//    protected:
//        pointer data_;
//
//    public:
//        VectorIterator() : data_(nullptr) {}
//        VectorIterator(pointer pt);
//        ~VectorIterator() {}
//        VectorIterator& operator++();
//        VectorIterator& operator+(const size_t value);
//        VectorIterator& operator-(const size_t value);
//        bool operator>(const size_t value);
//        VectorIterator operator++(int);
//        VectorIterator& operator--();
//        VectorIterator operator--(int);
//        bool operator==(iterator& other);
////        bool operator!=(const iterator& other);
//
//        value_type operator*();
//
//
////        friend std::ostream& operator<<(std::ostream& os, iterator iter);
//    private:
//
////        friend Vector::const_iterator;
//        iterator& operator=(const iterator &other);
//        iterator& operator+=(const iterator &other);
//    };

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

    };

 }  // namespace s21

#include "vector.tpp"

#endif  //  SRC_VECTOR_H_
