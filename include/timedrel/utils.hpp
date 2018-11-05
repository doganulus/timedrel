#ifndef TIMEDREL_UTILS_HPP
#define TIMEDREL_UTILS_HPP 1

#include <iostream>

#include "bound.hpp"
#include "zone.hpp"
#include "zone_set.hpp"

namespace timedrel {

template <typename T>
inline std::ostream& operator<< (std::ostream &os, const bound<T>& b) {
    os << b.value << (b.sign ? '|' : ':');
    return os;
}

template <typename T>
inline std::ostream& operator<< (std::ostream &os, const zone<T>& z) {

    os << z.get_bmin() <<' '<< z.get_bmax() <<' '<<
          z.get_emin() <<' '<< z.get_emax() <<' '<<
          z.get_dmin() <<' '<< z.get_dmax();

    return os;
}

template<typename T, typename Container>
inline std::ostream& operator<<(
    std::ostream &os, 
    const zone_set<T, Container>& zs){

    for(const auto &z : zs.container){
        os << z << std::endl;
    }
    return os;
}

} //namespace timedrel

#endif
