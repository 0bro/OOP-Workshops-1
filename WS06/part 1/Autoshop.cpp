#include "Autoshop.h"
using namespace std;

namespace sdds
{
    Autoshop &Autoshop::operator+=(Vehicle *theVehicle)
    {
        m_vehicles.push_back(theVehicle);
    }
    void Autoshop::display(std::ostream &out) const
    {
        out << "--------------------------------" << endl
            << "| Cars in the autoshop ! |" << endl
            << "--------------------------------" << endl;
            for (int i = 0; i < m_vehicles.size();i++)
            {
                m_vehicles[i]->display(out);
            }
    }
} // namespace sdds