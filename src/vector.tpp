//#include "vector.h"
#include <cstring>
namespace s21 {

    template<class value_type>
    Vector<value_type>::Vector() {
        this->bring_to_zero();
    }

    template<class value_type>
    Vector<value_type>::Vector(size_type n) {
        if (n > this->max_size()) {
            throw std::length_error("cannot create s21::vector larger than max_size()");
        }
        this->m_size_ = n;
        this->m_capacity_ = n;
        this->arr_ = n ? new value_type[n] : nullptr;
    }

    template<class value_type>
    Vector<value_type>::Vector(std::initializer_list<value_type> const &items) {
        this->bring_to_zero();
        this->arr_ = new value_type[items.size()]{};
        size_type i = 0;
        for (auto it = items.begin(); it != items.end(); it++) {
            this->arr_[i] = *it;
            i++;
        }
        this->m_size_ = items.size();
        this->m_capacity_ = items.size();
//        if (items.size() == 0) {
//            throw std::invalid_argument("Bad size of initializer list");
//        } else {
//            m_capacity_ = items.size();
//            memory();
//            for (auto element : items) {
//                this->arr_[this->m_size_++] = element;
//            }
//        }
    }

    template<class value_type>
    Vector<value_type>::Vector(const Vector &v) {
        this->bring_to_zero();
        *this = v;
    }


    template<class value_type>
    Vector<value_type>::Vector(Vector &&v) {
        this->bring_to_zero();
        if (this->arr_ != v.arr_) {
//            this->arr_ = v.arr_;
//            this->m_size_ = v.m_size_;
//            this->m_capacity_ = v.m_capacity_;
            *this = std::move(v);
            v.arr_ = nullptr;
            v.m_size_ = 0;
            v.m_capacity_ = 0;

        }
    }

    template<class value_type>
    Vector<value_type>&  Vector<value_type>::operator=(const Vector &v) {
        if (this->arr_ != v.arr_) {
            if (this->arr_ != nullptr) {
                delete [] this->arr_;
            }
            if (this->m_capacity_ < v.m_size_) {
                this->m_capacity_ = v.m_capacity_;
            }

            this->m_size_ = v.m_size_;
            this->arr_ = new value_type[this->m_capacity_]{};
            for (size_type i = 0; i < this->m_size_; ++i)
                this->arr_[i] = v.arr_[i];
        }
        return *this;
    }



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
    Vector<value_type>&  Vector<value_type>::operator=(Vector &&v) {
        if (this != &v) {
            this->clear_all();
            this->arr_ = v.arr_;
            this->m_capacity_ = v.m_capacity_;
            this->m_size_ = v.m_size_;
    //        *this = std::move(v);
            v.m_size_ = 0;
            v.m_capacity_ = 0;
            v.arr_ = nullptr;
        }
        return *this;
    }


    template <class value_type>
    void Vector<value_type>::swap(Vector &other) {
        if (this->arr_ != other.arr_) {
            std::swap(this->m_size_, other.m_size_);
            std::swap(this->m_capacity_, other.m_capacity_);
            std::swap(this->arr_, other.arr_);
            }
    }



    template <typename value_type>
    void Vector<value_type>::clear_all() {
        if (this->arr_ != nullptr) {
            delete[] this->arr_;
        }
        this->arr_ = nullptr;
        this->m_size_ = this->m_capacity_ = 0;
    }




    template<class value_type>
    void Vector<value_type>::output_vector() {
        if (this->empty()) {
            throw std::length_error("Your vector is empty!");
        }
        std::cout << "This is your vector!!" << std::endl;
        for (int i = 0; i < this->size(); i++) {
            std::cout << this->arr_[i];
        }
        std::cout << std::endl;
    }

    template<class value_type>
    void Vector<value_type>::bring_to_zero() {
        this->arr_ = nullptr;
        this->m_size_ = this->m_capacity_ = 0;
    }



    template<class value_type>
    void Vector<value_type>::pop_back() {
        if (this->empty())
            throw  std::runtime_error("Vector is empty!!");
        this->arr_[this->m_size_--] = 0;
    }

    template <typename T>
    void Vector<T>::push_back(value_type v) {
        if (this->m_size_ >= this->m_capacity_) {
            reserve_more_capacity(this->m_size_ * 2, false);
        }
        this->arr_[this->m_size_++] = v;
    }


    template<class value_type>
    void Vector<value_type>::memory() {
        if (!(this->arr_ = new value_type[this->m_capacity_ + 1]()))
            throw std::invalid_argument("Bad alloc");
    }

template<class value_type>
void Vector<value_type>::reserve_more_capacity(size_type size, bool flag) {
    // if (size > m_capacity_) {
    if (flag) {
        this->m_size_ = size;
    }
    value_type *buff = new value_type[size];

    for (size_t i = 0; i < this->m_size_; ++i)
    buff[i] = std::move(this->arr_[i]);

    delete[] this->arr_;
    this->arr_ = buff;
    this->m_capacity_ = size;

    // }
}
// >>>>>>>>> Vector Element access <<<<<<<<<<<


//template <class value_type>
//typename Vector<value_type>::reference Vector<value_type>::at(size_type i) {
//    if (i > this->m_size_) throw std::out_of_range("Out of range");
//    return this->arr_[i];
//}

//template <typename value_type>
//typename Vector<value_type>::reference Vector<value_type>::operator[](size_type i) {
//
//    return this->arr_[i];
//}

//template<class value_type>
//typename Vector<value_type>::const_reference Vector<value_type>::front() {
//    if (this->empty()) {
//        throw std::out_of_range("In origin vector here segmentation fault");
//    }
//        return this->arr_[0];
//}

//template<class value_type>
//typename Vector<value_type>::const_reference Vector<value_type>::back() {
//    if (this->empty()) {
//        throw std::out_of_range("In origin vector here segmentation fault");
//    }
//    return this->arr_[this->m_size_ - 1];
//}
//
//template<class value_type>
//typename Vector<value_type>::iterator Vector<value_type>::data()  {
//    return this->begin();
//}

//    const_reference back();

    /* >>>>>>>>>>>>  ITERATOR <<<<<<<<<<<<<<*/

//template <class value_type>
//typename Vector<value_type>::VectorIterator&
//Vector<value_type>::iterator::operator++() {
//    this->data_++;
//    return *this;
//}
//
//template<class value_type>
//typename Vector<value_type>::VectorIterator&
//Vector<value_type>::iterator::operator+(const size_t value) {
//    this->data_ = this->data_ + value;
//    return *this;
//}
//
//template<class value_type>
//typename Vector<value_type>::VectorIterator&
//Vector<value_type>::iterator::operator-(const size_t value) {
//    this->data_ = this->data_ - value;
//    return *this;
//}
//
//template<class value_type>
//bool
//Vector<value_type>::iterator::operator>(const size_t value) {
//    return *this->data_ > value ;
//
//}
//
//template <class value_type>
//typename Vector<value_type>::VectorIterator
//Vector<value_type>::iterator::operator++(int) {
//    iterator temp(*this);
//    this->data_++;
//    return temp;
//}
//
//
//
//template <class value_type>
//typename Vector<value_type>::VectorIterator &
//Vector<value_type>::iterator::operator--() {
//    this->data_--;
//    return *this;
//}
//
//template <class value_type>
//typename Vector<value_type>::VectorIterator
//Vector<value_type>::iterator::operator--(int) {
//    iterator temp(*this);
//    this->data_--;
//    return temp;
//}
//
//template <class value_type>
//bool Vector<value_type>::iterator::operator==(iterator &other) {
//    return (this->data_ == other.data_);
//}
//
////template <class value_type>
////bool Vector<value_type>::iterator::operator!=(const iterator &other) {
////    return this->data_ != other.data_;
////}
//
//template <class value_type>
//Vector<value_type>::iterator::VectorIterator(pointer pt) {
//    this->data_ = pt;
//}

//template<class value_type>
//Vector<value_type>::const_iterator::VectorConstIterator(const iterator &other) {
//    this->data_ = other.data_;
//}


//template<class value_type>
//VectorConstIterator<value_type>::VectorConstIterator() {
//    this->data_ = nullptr;
//}
//
//template<class value_type>
//VectorConstIterator<value_type>::VectorConstIterator() {
//    this->data_ = pt.data_;
//}

//  >>>>>>>>>>>>>>>>>>>>> begin end <<<<<<<<<<<<<<<<

//template <class value_type>
//typename Vector<value_type>::iterator Vector<value_type>::begin() {
//    if (this->empty())
//        throw std::invalid_argument("Vector is empty!");
//    iterator temp(this->arr_);
//    return temp;
//}
//
//template <class value_type>
//typename Vector<value_type>::iterator Vector<value_type>::end() {
//    if (this->empty())
//        throw std::invalid_argument("Vector is empty!");
//    size_type ind = this->m_size_ > 0 ? this->m_size_ : 0;
//    iterator temp(this->arr_ + ind);
//    return temp;
//}




//template <class value_type>
//typename Vector<value_type>::reference Vector<value_type>::const_iterator::operator*() {
//    if (this->data_ == nullptr)
//        throw std::invalid_argument("Bad <*> parameters!");
//    return *this->data_;
//}

//template <class value_type>
//typename Vector<value_type>::value_type Vector<value_type>::iterator::operator*() {
//    if (this->data_ == nullptr)
//        throw std::invalid_argument("Bad <*> parameters!");
//    return *data_;
//}

//template<class value_type>
//typename Vector<value_type>::iterator&  Vector<value_type>::iterator::operator=(const iterator &other) {
//    this->data_ = other.data_;
//    return *this;
//}
//
//template<class value_type>
//typename Vector<value_type>::iterator& Vector<value_type>::iterator::operator+=(const iterator &other) {
//    this->data_ += other.data_;
//    return *this;
//}


//  >>>>>>>>>>>> Capacity <<<<<<<<<<<<<<<<<<


//template <typename value_type>
//bool Vector<value_type>::empty() {
//    return this->arr_ == nullptr;
//}

//

//template<class value_type>
//typename Vector<value_type>::size_type Vector<value_type>::max_size() {
//    double sys = 0.0;
//
//#if __WORDSIZE == 64
//    sys = 64.0;
//#else
//    sys = 32.0;
//#endif
////    return static_cast<size_type>(std::pow(2.0, sys)) / static_cast<value_type>(sizeof(value_type)) ;
//    return static_cast<size_type>(std::pow(2.0, sys) / static_cast<value_type>(sizeof(value_type))) / 2 - 1;  // fixed with chaer
//
//}

template<class value_type>
void Vector<value_type>::reserve(size_type size) {
    // if (size >= m_capacity_)
    //     throw std::invalid_argument("Error");
    if (size < 0) {
        throw std::length_error("Error size");
    }
    if (size <= this->m_capacity_) {
        return;
    }
//    if (size > this->m_capacity_ )
    reserve_more_capacity(size, false);
//    reserve_more_capacity(size, false);
}

template<class value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() {
    return this->m_capacity_;
}

template<class value_type>
void Vector<value_type>::shrink_to_fit() {
    reserve_more_capacity(this->m_size_, true);
}

// >>>>>>>> Modifiers <<<<<<<<

template<typename value_type>
void Vector<value_type>::clear() {
    if (this->arr_ != nullptr) {
        delete[] this->arr_;
    }
    this->arr_ = nullptr;
    this->m_size_ = 0;
}

template<class value_type>
typename Vector<value_type>::iterator
Vector<value_type>::insert(iterator pos, const_reference value) {
    size_type position = &(*pos) - this->arr_;
    if (this->m_size_ + 1 >= this->m_capacity_) {
        this->reserve_more_capacity(this->m_capacity_ * 2, false);
    }
    value_type buff = this->arr_[position];
    this->m_size_++;
    this->arr_[position] = value;
    for (size_type i = position + 1; i < this->m_size_; ++i) {
        value_type buff_2 = this->arr_[i];
        this->arr_[i] = buff;
        buff = buff_2;
    }


//    auto temp = this->begin();
//    temp += pos;

    return this->arr_ + position;
}

template<class value_type>
void Vector<value_type>::erase(iterator pos) {
//    size_type position = *pos - *this->arr_;
//    Vector<value_type> new_vec(this->m_size_ - 1);
//    std::cout << new_vec.capacity() << " " << new_vec.size() << std::endl;
//        for (size_type i = 0, j = 0; i < this->m_size_; ++i, ++j) {
//        if (j != position) {
//            new_vec.arr_[i] = this->arr_[j];
//        } else {
//            ++j;
//            new_vec.arr_[i] = this->arr_[j];
//        }
//    }
//    new_vec.output_vector();
//    this->clear_all();
//    this->swap(new_vec);
    value_type *buff = new value_type[this->m_size_ - 1];
    for (size_type i = 0, t = 0; i < this->m_size_; i++)
        if ((this->begin() + i) != pos) buff[t++] = this->arr_[i];
    delete[] this->arr_;
    this->arr_ = buff;
    this->m_size_--;

}

//template<class value_type>
//typename Vector<value_type>::iterator_1
//Vector<value_type>::test_insert(iterator_1 pos, const_reference value) {
//    size_type position = pos - arr_;
////    std::cout << position << std::endl;
//
//    if (this->m_size_ + 1 >= this->m_capacity_) {
//        this->reserve_more_capacity(this->m_capacity_ * 2, false);
//    }
//    value_type buff = this->arr_[position];
//    this->m_size_++;
//    this->arr_[position] = value;
//    for (size_type i = position + 1; i < m_size_; ++i) {
//        value_type buff_2 = this->arr_[i];
//        this->arr_[i] = buff;
//        buff = buff_2;
//    }
////    auto temp = pos - begin_1();
//
////    auto t = begin_1();
////    pos = pos + t;
//    pos = this->arr_ + position;
//    return pos;
//}

    template<typename value_type>
    template<typename ... Args>
    typename Vector<value_type>::iterator
    Vector<value_type>::emplace(const_iterator pos, Args &&...args) {
        iterator it(pos);
        this->insert(it, value_type(std::forward<Args>(args)...));
        return pos;
    }

    template<typename value_type>
    template<typename ... Args>
    void Vector<value_type>::emplace_back(Args &&...args) {
        this->push_back(value_type(std::forward<Args>(args)...));
    }

}  // namespace s21
