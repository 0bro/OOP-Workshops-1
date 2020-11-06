#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Vehicle.h"

namespace sdds
{

    class Utilities : public Vehicle
    {
    public:
        Vehicle *createInstance(std::istream &in);
        // Vehicle(createInstance(std::istream &in));
    };

} // namespace sdds

#endif