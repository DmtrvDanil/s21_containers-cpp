#include "vector.h"
#include <vector>
using namespace s21;

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
void Vector<value_type>::reserve(size_type size) {
    if (size <= m_capacity_)
        return;
    else
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

template <typename T>
void Vector<T>::output_vector() {
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
    if (m_size_ == m_capacity_)
    {
        reserve_more_capacity(m_size_ * 2, false);
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


template <class value_type>
void Vector<value_type>::reserve_more_capacity(size_t size, bool shrink)
{
    if (size > m_capacity_)
    {
        value_type *buff = new value_type[size];
        for (size_t i = 0; i < m_size_; ++i)
            buff[i] = std::move(arr_[i]);
        if (shrink == true) {
            delete[] arr_;
            arr_ = buff;
            m_capacity_ = size;
        }
    }
}



template <class value_type>
typename Vector<value_type>::VectorIterator &Vector<value_type>::iterator::operator++() {
    this->data_++;
    return *this;
}

template <class value_type>
typename Vector<value_type>::VectorIterator Vector<value_type>::iterator::operator++(int) {
    iterator temp(*this);
    temp.position_++;
    return temp;
}

template <class value_type>
typename Vector<value_type>::VectorIterator &Vector<value_type>::iterator::operator--() {
    this->data_--;
    return *this;
}

template <class value_type>
typename Vector<value_type>::VectorIterator Vector<value_type>::iterator::operator--(int) {
    iterator temp(*this);
    temp.position_--;
    return temp;
}
template <class value_type>
typename Vector<value_type>::VectorIterator &Vector<value_type>::iterator::operator=(const const_iterator& other) {
    this->data_ = other.data_;
    this->position_ = other.position_;
    this->size_of_vector_ = other.size_of_vector_;
    return *this;
}

template <class value_type>
bool  Vector<value_type>::iterator::operator==(iterator& other) {
    return (this->data_ == other.data_ && this->position_ == other.position_);
}

template <class value_type>
bool Vector<value_type>::iterator::operator!=(iterator& other) {
    return this->data_ != other.data_;
}

// template <class value_type>
// value_type Vector<value_type>::iterator::operator*() {
//     if (this->data_ == nullptr)
//         throw std::length_error("Iterator is Empty");
//     return (this->position_ > this->size_of_vector_) ? 0 : this->data_[this->position_];
// }

template<class value_type>
Vector<value_type>::iterator::VectorIterator(const Vector &vec, size_type position) {
    this->data_ = vec.arr_;
    this->size_of_vector_ = vec.m_size_ > 0 ? vec.m_size_ - 1 : 0;
    this->position_ = position;  
} 

template<class value_type>
typename Vector<value_type>::iterator Vector<value_type>:: begin() {
    if (this->empty())
        throw std::length_error("Your Vector is empty!");
    iterator temp(*this, 0);
    return temp;
}

template<class value_type>
typename Vector<value_type>::iterator Vector<value_type>:: end() {
    if (this->empty())
        throw std::length_error("Your Vector is empty!");
    size_type i = this->m_size_ > 0 ? this->m_size_ : 0;
    iterator temp(*this, i);
    return temp;
}


// template<class value_type>
// value_type Vector<value_type>::iterator::operator*() {
//         if (this->data_ == nullptr)
//             throw std::invalid_argument("Iterator is pointing to null!");
//         return (this->position_ > this->size_of_vector_) ? 0 : this->data_[this->position_];
//     }

template<class value_type>
typename Vector<value_type>::reference Vector<value_type>::iterator::operator*() {
        if (this->data_ == nullptr || this->position_ > this->size_of_vector_)
            throw std::invalid_argument("Bad parameters!");
        return this->data_[this->position_];
    }

template<class value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type i) {
    if (i > this->m_size_)
        throw std::out_of_range("Out of range");
    return arr_[i];
}


int main(void) {
    char y;
    std::cout << sizeof(&y)  << std::endl;
    Vector<int> j;
    Vector<double> i;
    Vector<char> k;
    std::cout << j.max_size();
    std::cout << std::endl;
    std::cout << i.max_size();
    std::cout << std::endl;
    std::cout << k.max_size();
    std::cout << std::endl;
    std::cout << "My Vector" << std::endl;


    std::vector<int> a;
    std::vector<double> b;
    std::vector<char> c;
    std::cout << a.max_size();
    std::cout << std::endl;
    std::cout << b.max_size();
    std::cout << std::endl;
    std::cout << c.max_size();

    // for (auto i : c)
    //     std::cout << i ;

  

    
    
 
    return 0;
}