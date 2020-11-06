#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include "Car.h"
#include "Vehicle.h"
#include <vector>

namespace sdds
{

    class Autoshop : public Vehicle
    {
        std::vector<Vehicle *> m_vehicles;

    public:
        Autoshop &operator+=(Vehicle *theVehicle);
        void display(std::ostream &out) const;
    };

} // namespace sdds

#endif