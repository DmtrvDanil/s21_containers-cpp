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



    // >>>>>>>>>>>>> Const Iterator <<<<<<<<<<<<<<<<<<<<<<<<
    template<class value_type>
    abstract<value_type>::VectorConstIterator::VectorConstIterator() {
        this->data_ = nullptr;
    }

    template<class value_type>
    abstract<value_type>::VectorConstIterator::VectorConstIterator(pointer pt) {
        this->data_ = pt;
    }

    template<class value_type>
    typename abstract<value_type>::const_reference  abstract<value_type>::VectorConstIterator::operator*() {
    if (this->data_ == nullptr)
        throw std::invalid_argument("Bad <*> parameters!");
        return *this->data_;
    }

    template<class value_type>
    bool abstract<value_type>::VectorConstIterator::operator!=(const VectorConstIterator &other) const {
        return this->data_ != other.data_;
    }

    template<class value_type>
    bool abstract<value_type>::VectorConstIterator::operator==(const VectorConstIterator &other) const {
        return this->data_ == other.data_;
    }


    template<class value_type>
    typename abstract<value_type>::VectorConstIterator  abstract<value_type>::VectorConstIterator::operator+(const size_t value) {
        VectorConstIterator it_const(this->data_ + value);
        return it_const;
    }

    template<class value_type>
    typename abstract<value_type>::VectorConstIterator&  abstract<value_type>::VectorConstIterator::operator++() {
        this->data_++;
        return *this;
    }

    template<class value_type>
    typename abstract<value_type>::VectorConstIterator  abstract<value_type>::VectorConstIterator::operator++(int) {
        VectorConstIterator temp(*this);
        this->data_++;
        return temp;
    }

    template<class value_type>
    typename abstract<value_type>::VectorConstIterator&  abstract<value_type>::VectorConstIterator::operator--() {
        this->data_--;
        return *this;
    }

    template<class value_type>
    typename abstract<value_type>::VectorConstIterator  abstract<value_type>::VectorConstIterator::operator--(int) {
        VectorConstIterator temp(*this);
        this->data_--;
        return temp;
    }

    // >>>>>>>>>>>>> Iterator  <<<<<<<<<<<<<<<<<<<<<<<<
    template<class value_type>
    abstract<value_type>::VectorIterator::VectorIterator() :
        VectorConstIterator() {}

    template<class value_type>  //see this function need some fixed
    abstract<value_type>::VectorIterator::VectorIterator(pointer pt) :
        VectorConstIterator(pt) {}

    template<class value_type>
    typename abstract<value_type>::reference  abstract<value_type>::VectorIterator::operator*() {
        if (this->data_ == nullptr)
            throw std::invalid_argument("Bad <*> parameters!");
        return *this->data_;
    }

    template<class value_type>
    typename abstract<value_type>::VectorIterator&  abstract<value_type>::VectorIterator::operator=(const value_type val) {
        *this->data_ = val;
        return *this->data_;
    }

    template<class value_type>
    typename abstract<value_type>::VectorIterator  abstract<value_type>::VectorIterator::operator+(const size_t value) {
        VectorIterator it(this->data_ + value);
        return it;
    }

    template<class value_type>
    typename abstract<value_type>::VectorIterator  abstract<value_type>::VectorIterator::operator-(const size_t value) {
        VectorIterator it(this->data_ - value);
        return it;
    }

    template<class value_type>
    typename abstract<value_type>::VectorIterator  abstract<value_type>::VectorIterator::operator-(const VectorIterator &value) {
        return this->data_ - value;
    }
//    VectorIterator operator-(const VectorIterator &value);



    template<class value_type>
    typename abstract<value_type>::iterator abstract<value_type>::data()  {
        return this->begin();
    }


    //   >>>>>>>>>>>> Iterator begin end <<<<<<<<<<<<<<<<<<<<
    template<class value_type>
    typename abstract<value_type>::iterator abstract<value_type>::begin() {
        iterator temp(this->arr_);
        return temp;
    }

    template<class value_type>
    typename abstract<value_type>::iterator abstract<value_type>::end() {
        iterator temp(this->arr_ + this->m_size_);
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