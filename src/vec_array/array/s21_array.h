#ifndef SRC_VEC_ARRAY_S21_ARRAY_H
#define SRC_VEC_ARRAY_S21_ARRAY_H
#include "../s21_abstract.h"

namespace s21 {
    template<class T, size_t n>
    class array : public abstract<T> {
    private:
        using pointer = typename abstract<T>::pointer;
        using value_type = typename abstract<T>::value_type;
        using reference = typename abstract<T>::reference;
        using const_reference = typename abstract<T>::const_reference;
        using size_type = typename abstract<T>::size_type;
        using iterator_2 = typename abstract<T>::VectorIterator_1;
        using const_iterator_2 = typename abstract<T>::VectorConstIterator;
    public:
        array();
    };




} // namespace

#endif  // SRC_VEC_ARRAY_S21_ARRAY_H
#include "s21_array.cpp"