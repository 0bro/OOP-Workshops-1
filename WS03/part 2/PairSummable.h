#ifndef PAIRSUMMABLE_H_SDDS
#define PAIRSUMMABLE_H_SDDS

#include <iostream>
#include "Pair.h"

namespace sdds
{
    template <typename K, typename V>
    class PairSummable : public Pair<K, V>
    {
        static V m_initial;
        static size_t minWidth;

    public:
        PairSummable() : Pair<K, V>(){};
        PairSummable(const K &key, const V &value = m_initial) : Pair<K, V>(key, value)
        {
            if (minWidth < size(key))
                minWidth = size(key);
        }
        PairSummable &operator+=(const PairSummable &src)
        {
            if (this != &src)
            {
                if (this->key() == src.key())
                {
                    *this = PairSummable(this->key(), m_initial + src.m_initial);
                }
            }
            return *this;
        }
        void display(std::ostream os) const
        {
            // allign then
            display(os, this);
        }
    };
    template <>
    class PairSummable<std::string, std::string> : public Pair<std::string, std::string>
    {
        static std::string m_initial;
        static size_t minWidth;

    public:
        PairSummable() : Pair<std::string, std::string>() {}
        PairSummable(const std::string &key, const std::string &value = "") : Pair<std::string, std::string>(key, value)
        {
            if (minWidth < key.size())
                minWidth = key.size();
        }
        PairSummable &operator+=(const PairSummable &src)
        {
            if (this != &src)
            {
                if (this->key() == src.key())
                {
                    *this = PairSummable(this->key(), m_initial + ", " + src.m_initial);
                }
            }
            return *this;
        }
        void display(std::ostream os) const
        {
            // allign then
            os << std::endl;
        }
    };
    template <>
    class PairSummable<std::string, int> : public Pair<std::string, int>
    {
        static int m_initial;
        static size_t minWidth;

    public:
        PairSummable() : Pair<std::string, int>() {}
        PairSummable(const std::string &key, const int &value = 0) : Pair<std::string, int>(key, value)
        {
            if (minWidth < key.size())
                minWidth = key.size();
        }
        PairSummable &operator+=(const PairSummable &src)
        {
            if (this != &src)
            {
                if (this->key() == src.key())
                {
                    *this = PairSummable(this->key(), m_initial + src.m_initial);
                }
            }
            return *this;
        }
        void display(std::ostream os) const
        {
            // allign then
            os << std::endl;
        }
    };
} // namespace sdds

#endif