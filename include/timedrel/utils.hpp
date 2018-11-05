/* 
Copyright (c) 2016-Present by Dogan Ulus <doganulus@gmail.com>.

This file is part of the monitoring tool Montre.

The Montre is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>. 
*/

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
