#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds
{

    class Car : public Vehicle
    {
        bool m_valid;
        char m_tag;
        std::string m_maker;
        std::string m_condition;
        double m_topSpeed;

    public:
        Car(std::istream &is);
        double topSpeed() const;
        void display(std::ostream &) const;
        std::string condition() const;
    };

} // namespace sdds

#endif