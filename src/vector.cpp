#include "vector.h"
#include <vector>
using namespace s21;

template <typename T>
typename Vector<T>::reference Vector<T>::operator[](size_type i) {

    return this->arr_[i];
    }

template <typename T>
void Vector<T>::clear() {
    if (this->arr_ != nullptr) {
        delete[] this->arr_;
    }
    this->arr_ = nullptr;
    this->m_size_ = this->m_capacity_ = 0;
}

template <typename T>
bool Vector<T>::empty() {
    return this->arr_ == nullptr;
}

template <typename T>
void Vector<T>::output_vector() {
    std::cout << "This is your vector!!" << std::endl;
    for (int i = 0; i < this->size(); i++) {
        std::cout << this->arr_[i];
    }
    std::cout << std::endl;
}

template <typename T>
size_t Vector<T>::size()
{
    return m_size_;
}


template <typename T>
void Vector<T>::push_back(T v)
{
    if (m_size_ == m_capacity_)
    {
        reserve_more_capacity(m_size_ * 2);
    }
    arr_[m_size_++] = v;
}


template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> const &items)
{
    this->arr_ = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        arr_[i] = *it;
        i++;
    }
    m_size_ = items.size();
    m_capacity_ = items.size();
};


template <typename T>
void Vector<T>::reserve_more_capacity(size_t size)
{
    if (size > m_capacity_)
    {
        value_type *buff = new value_type[size];
        for (size_t i = 0; i < m_size_; ++i)
            buff[i] = std::move(arr_[i]);
        delete[] arr_;
        arr_ = buff;
        m_capacity_ = size;
    }
}


int main(void) {
    Vector<int> a = {1,2,3,4,5};
    
    a.output_vector();
    std::cout << a.empty();
    return 0;
}