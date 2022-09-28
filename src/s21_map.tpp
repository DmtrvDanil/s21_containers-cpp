#include "s21_map.h"
namespace s21 {
    template<class key_type, class mapped_type, class Compare>
    typename map<key_type, mapped_type, Compare>::mapped_type &map<key_type, mapped_type, Compare>::at(
            const key_type &key) {
        iterator tmp = this->begin();
        if (tmp.get_data() == tmp.get_nil()) {
            throw std::out_of_range("Camone man");
        }
        for (; tmp != this->end(); ++tmp) {
                if (tmp->first == key)
                    return tmp->second;
        }


        return tmp->second;

    }

    template<class key_type, class mapped_type, class Compare>
    typename map<key_type, mapped_type, Compare>::mapped_type& map<key_type, mapped_type, Compare>::operator[](
            const key_type &key) {
        iterator tmp = this->begin();
        for (; tmp != end(); ++tmp)
            if (tmp->first == key)
                return tmp->second;
        return tmp->second;
    }

    template<class key_type, class mapped_type, class Compare>
    void map<key_type, mapped_type, Compare>::merge(map& other) {
        iterator iter = other.begin();
        while (iter != other.end()) {
            if(this->insert(*iter).second) {
                other.erase(iter);
            }
            iter++;
        }
//        other.clear();
    }


}  // namespace s21