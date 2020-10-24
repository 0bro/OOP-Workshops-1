
#include "Car.h"

using namespace std;
namespace sdds
{
    Car::Car(std::istream &is)
    {
    }

    double topSpeed() 
    {
        return topSpeed;
    }
    void display(std::ostream &os)
    {
    }
    std::string Car::condition() const
    {
        return m_condition;
    }
} // namespace sdds