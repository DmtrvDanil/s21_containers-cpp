namespace s21 {

    //  >>>>>>>>>>>>>> Access <<<<<<<<<<<<<<<<<<<<<<
    template<class value_type>
    typename abstract<value_type>::reference abstract<value_type>::at(size_type pos) {
        if (pos > this->m_size_) throw std::out_of_range("Out of range");
        return this->arr_[pos];
    }

    template<class value_type>
    typename abstract<value_type>::reference abstract<value_type>::operator[](size_type pos) {
        return this->arr_[pos];
    }

    template<class value_type>
    typename abstract<value_type>::const_reference abstract<value_type>::front() {
        if (this->empty()) {
            throw std::out_of_range("In origin vector here segmentation fault");
        }
        return this->at(0);
    }

    template<class value_type>
    typename abstract<value_type>::const_reference abstract<value_type>::back() {
        if (this->empty()) {
            throw std::out_of_range("In origin vector here segmentation fault");
        }
        return this->at(this->m_size_-1);
    }

    template<class value_type>
    typename abstract<value_type>::iterator_2 abstract<value_type>::data() {
        return this->begin();
    }

    //   >>>>>>>>>>>> Iterators <<<<<<<<<<<<<<<<<<<<
    template<class value_type>
    typename abstract<value_type>::iterator_2 abstract<value_type>::begin_4() {
        iterator_2 temp(this->arr_);
        return temp;
    }

    template<class value_type>
    typename abstract<value_type>::iterator_2 abstract<value_type>::end_4() {
        iterator_2 temp(this->arr_ + this->m_size_);
        return temp;
    }
    //  >>>>>>>>>>> Capacity <<<<<<<<<<<<<<<
    template <class value_type>
    bool abstract<value_type>::empty() {
        return this->arr_ == nullptr;
    }

    template<class value_type>
    typename abstract<value_type>::size_type abstract<value_type>::size() {
        return this->m_size_;
    }

    template<class value_type>
    typename abstract<value_type>::size_type abstract<value_type>::max_size() {
        double sys = 0.0;

        #if __WORDSIZE == 64
            sys = 64.0;
        #else
            sys = 32.0;
        #endif
//    return static_cast<size_type>(std::pow(2.0, sys)) / static_cast<value_type>(sizeof(value_type)) ;
        return static_cast<size_type>(std::pow(2.0, sys) / static_cast<value_type>(sizeof(value_type))) / 2 - 1;  // fixed with chaer
    }




}  //  namespace s21