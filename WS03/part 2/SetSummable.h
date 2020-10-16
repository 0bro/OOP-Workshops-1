#ifndef SETSUMMABLE_H_SDDS
#define SETSUMMABLE_H_SDDS

#include <iostream>
#include "Set.h"
#include "PairSummable.h"
#include <typeinfo>

namespace sdds
{
    template <typename T, int N>
    class SetSummable : public Set<T, N>
    {
    public:
        T accumulate(const std::string &filter) const
        {
            T temp(filter);

            // for (int i = 0; i < this->size(); i++)
            // {
            // temp += this[0];
            // std::cout << typeid(this[0]).name();
            // }
            return temp;
        }
    };

} // namespace sdds

#endif

// <typename T, size_t N, typename K, typename V>
// class SetSummable : public Set<T, N>
// {
// public:
//     V accumulate(const K &key)
//     {
//         T get;
//         V temp = get.getInitialValue();
//         for (size_t i = 0; i < Set<T, N>::size(); i++)
//         {
//             temp = ((Set<T, N> &)*this)[i].sum(key, temp);
//         }
//         return temp;
//     }
// }