#ifndef SDDS_CONFIRMSENDER_H
#define SDDS_CONFIRMSENDER_H

#include "Reservation.h"
#include "Restaurant.h"

namespace sdds
{

    class ConfirmationSender
    {

        Reservation const ** m_reservation;
        size_t m_count;

    public:
        ConfirmationSender();
        ~ConfirmationSender();
        size_t size() const;
        void display() const;
        ConfirmationSender &operator+=(const Reservation &res);
        ConfirmationSender &operator-=(const Reservation &res);
        friend std::ostream &operator<<(std::ostream &os, ConfirmationSender &confSend);
    };

} // namespace sdds

#endif