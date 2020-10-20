#ifndef SDDS_RESTURANT_H
#define SDDS_RESTURANT_H

#include "Reservation.h"

namespace sdds
{

    class Restaurant
    {
        Reservation *m_reservation;
        size_t m_cnt;

    public:
        Restaurant(Reservation *reservation[], size_t cnt);
        ~Restaurant();
        size_t size() const;
        void display() const;
        friend std::ostream &operator<<(std::ostream &os, Restaurant &resturant);
    };

} // namespace sdds

#endif