#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>
namespace sdds
{
    const size_t ID_MAX = 8;
    class Reservation
    {
        std::string m_reserveID;
        std::string m_reserveName;
        std::string m_email;
        size_t m_partySize;
        size_t m_day;
        size_t m_hour;

    public:
        Reservation();
        Reservation(const std::string &res);
        friend std::ostream &operator<<(std::ostream &os, Reservation &out);
    };

} // namespace sdds

#endif