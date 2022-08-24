#include "vector.h"

namespace s21 {

// template<class value_type>
// void Vector<value_type>::shrink_to_fit() {
//     if (!this->arr_)
//         throw std::runtime_error("Your vector is empty!!");
//     for (size_type i = 0 ; i < this->m_size_; i++) {
//         if (this->arr_[i] == 0) {
//             del [] this->arr_[i];
//         }

//     }
// }

template<class value_type>
void Vector<value_type>::shrink_to_fit() {
    reserve_more_capacity(this->m_size_, true);
}

template<class value_type>
void Vector<value_type>::reserve(size_type size) {
    // if (size >= m_capacity_)
    //     throw std::invalid_argument("Error");
    if (size > this->m_capacity_ )
        reserve_more_capacity(size, true);
    reserve_more_capacity(size, false);
}


template<class value_type>
Vector<value_type>  Vector<value_type>::operator=(Vector &&v) {
    if (this != &v) {
        this->clear();
        this->arr_ = v.arr_;
        this->m_capacity_ = v.m_capacity_;
        this->m_size_ = v.m_size_;
        v.m_size_ = 0;
        v.m_capacity_ = 0;
        v.arr_ = nullptr;
    }
    return *this;
}

template <class value_type>
void Vector<value_type>::swap(Vector &other) {
    if (this->arr_ != other.arr_) {
            Vector <value_type> temp(std::move(*this));
            *this = std::move(other);
            other = std::move(temp);
        }
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](size_type i) {

    return this->arr_[i];
    }

template <typename T>
void Vector<T>::clear() {
    if (!this->arr_) {
        delete[] this->arr_;
    }
    this->arr_ = nullptr;
    this->m_size_ = this->m_capacity_ = 0;
}

template <typename T>
bool Vector<T>::empty() {
    return this->arr_ == nullptr;
}
template<class value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() {
    return this->m_capacity_;
}

template<class value_type>
void Vector<value_type>::output_vector() {
    std::cout << "This is your vector!!" << std::endl;
    for (int i = 0; i < this->size(); i++) {
        std::cout << this->arr_[i];
    }
    std::cout << std::endl;
}





template<class value_type>
typename Vector<value_type>::size_type Vector<value_type>::max_size() {
    double sys = 0.0;
    #if __WORDSIZE == 64
    sys = 63.0;
    #else
    sys = 32.0;
    #endif
    return static_cast<size_type>(std::pow(2.0, sys)) / static_cast<value_type>(sizeof(value_type));
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::size() {
    return this->m_size_;
}


template<class value_type>
void Vector<value_type>::pop_back() {
    if (this->empty())
        throw  std::runtime_error("Vector is empty!!");
    this->arr_[m_size_--] = 0;
}

template <typename T>
void Vector<T>::push_back(T v)
{
    if (m_size_ == m_capacity_) {
        reserve_more_capacity(m_size_ * 2, true);
    }
    arr_[m_size_++] = v;
}


template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> const &items)
{
    this->arr_ = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++) {
        arr_[i] = *it;
        i++;
    }
    m_size_ = items.size();
    m_capacity_ = items.size();
};


template<class value_type>
void Vector<value_type>::reserve_more_capacity(size_t size, bool shrink) {
    // if (size > m_capacity_) {
        value_type *buff = new value_type[size];
        for (size_t i = 0; i < m_size_; ++i)
            buff[i] = std::move(arr_[i]);
        if (shrink == true) {
            delete[] arr_;
            arr_ = buff;
            m_capacity_ = size;
        }
    // }
}

    /* >>>>>>>>>>>>  ITERATOR <<<<<<<<<<<<<<*/

    template <class value_type>
    typename Vector<value_type>::VectorIterator &
    Vector<value_type>::iterator::operator++() {
        this->data_++;
        return *this;
    }

    template <class value_type>
    typename Vector<value_type>::VectorIterator
    Vector<value_type>::iterator::operator++(int) {
        iterator temp(*this);
        this->data_++;
        return temp;
    }

    template <class value_type>
    typename Vector<value_type>::VectorIterator &
    Vector<value_type>::iterator::operator--() {
        this->data_--;
        return *this;
    }

    template <class value_type>
    typename Vector<value_type>::VectorIterator
    Vector<value_type>::iterator::operator--(int) {
        iterator temp(*this);
        this->data_--;
        return temp;
    }

    template <class value_type>
    bool Vector<value_type>::iterator::operator==(iterator &other) {
        return (this->data_ == other.data_);
    }

    template <class value_type>
    bool Vector<value_type>::iterator::operator!=(const iterator &other) {
        return this->data_ != other.data_;
    }

    template <class value_type>
    Vector<value_type>::iterator::VectorIterator(pointer pt) {
    this->data_ = pt;
}

template <class value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin() {
    iterator temp(arr_);
    return temp;
}

template <class value_type>
typename Vector<value_type>::iterator Vector<value_type>::end() {
    iterator temp(arr_ + m_size_);
    return temp;
}

template <class value_type>
value_type Vector<value_type>::iterator::operator*() {
    return *data_;
}

template <class value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type i) {
    if (i > this->m_size_) throw std::out_of_range("Out of range");
    return arr_[i];
}

template<class value_type>
typename Vector<value_type>::iterator&  Vector<value_type>::iterator::operator=(const iterator &other) {
    this->data_ = other.data_;
    return *this;
}


}  // namespace s21

//int main(void) {
//    // std::vector<int> a{1, 2 , 3};
//    // std::cout <<  a.capacity() << " This is a capacity for original vector" << std::endl;
//    // std::cout << a.size() << " This is a size of original vector" << std::endl;
//    // a.reserve(2);
//    // std::cout << a.capacity() << " This is a capacity after reserve " << std::endl;
//    // std::cout << a.size() << " This is a size after resetve " << std::endl;
//    // a.shrink_to_fit();
//    // std::cout << a.capacity() << " This is a capacity after shrink to fit" << std::endl;
//    // std::cout << a.size() << " This is a size after shrink to fit" << std::endl;
//    // a.push_back(5);
//    // std::cout << a.capacity() << " This is a capacity after push" << std::endl;
//    // std::cout << a.size() << " This is a size after push" << std::endl;
//    // std::cout << "#####################" << std::endl;
//    // Vector<int> b{1,2,3};
//    // std::cout << b.capacity() << " This is a capacity for my vector" << std::endl;
//    // std::cout << b.size() << " This is a size for my vector" << std::endl;
//    // b.reserve(2);
//    // std::cout << b.capacity() << " This is a capacity after reserve" << std::endl;
//    // std::cout << b.size() << " This is a size after reserve" << std::endl;
//    // b.shrink_to_fit();
//    // std::cout << b.capacity() << " This is a capacity after fit" << std::endl;
//    // std::cout << b.size() << " This is a size after fit" << std::endl;
//    // b.push_back(5);
//    // // b.output_vector();
//    // std::cout << b.capacity() << " This is a capacity after push" << std::endl;
//    // std::cout << b.size() << " This is a size after push" << std::endl;
//    Vector<int> a{1,2,3,4,5};
//    Vector<int>::VectorIterator i =   a.begin();
//    ++i;
//    Vector<int>::VectorIterator j = a.begin();
//    // std::cout <<  i == j;
//    if (i != j)
//        std::cout << '1';
//    std::cout << *i << std::endl;
//    for (auto i = a.begin(); i != a.end(); i++ ) {
//        std::cout << *i << " ";
//    }
//    for (auto &&i : a)
//        std::cout << i << " ";
//    // a.output_vector();
//
//
//
//
//    return 0;
//}