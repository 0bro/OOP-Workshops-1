#include "Restaurant.h"
using namespace std;
namespace sdds
{
    Restaurant::Restaurant(Reservation *reservation[], size_t cnt)
    {

        m_reservation = nullptr;
        m_reservation = new Reservation[cnt];

        for (int i = 0; i < cnt; i++)
            m_reservation[i] = *reservation[i];
        m_cnt = cnt;
    }
    Restaurant::~Restaurant()
    {
        // delete [] m_reservation;
        // m_reservation = nullptr;
    }
    size_t Restaurant::size() const
    {
        return m_cnt;
    }
    void Restaurant::display() const
    {
        for (int i = 0; i < size(); i++)
            std::cout << m_reservation[i];
    }

    std::ostream &operator<<(std::ostream &os, Restaurant &restaurant)
    {
        os << "--------------------------" << endl
           << "Fancy Restaurant" << endl
           << "--------------------------" << endl;

        if (restaurant.size() == 0)
        {
            os << "The object is empty!" << endl;
        }
        else
        {
            restaurant.display();
        }
        os << "--------------------------" << endl;
        return os;
    }
}; // namespace sdds