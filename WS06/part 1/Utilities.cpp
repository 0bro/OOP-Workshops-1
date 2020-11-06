#include "Utilities.h"
using namespace std;

namespace sdds
{
    Utilities::Vehicle *createInstance(std::istream &in)
    {
        string temp;
        m_valid = true;
        Car m_car = 
        getline(in, temp, ',');
        if (temp == "C" || temp == "c")
            
            
            m_tag = temp.at(0);
        else
        {
            m_tag = '0';
            m_valid = false;
        }

        getline(in, m_maker, ',');

        getline(in, temp, ',');
        if (temp == "N" || temp == "n" || temp == "U" || temp == "u" || temp == "B" || temp == "b")
            m_condition = temp.at(0);
        else
        {
            m_condition = '0';
            m_valid = false;
        }

        getline(in, temp);

        bool isNumber = true;
        for (int i = 0; i < temp.length(); i++)
        {

            if (!isdigit(temp.at(i)) && temp.at(i) != ' ' && temp.at(i) != '.')
                isNumber = false;
        }
        if (isNumber)
            m_topSpeed = stod(temp);
        else
        {
            m_topSpeed = 0;
            m_valid = false;
        }
        return nullptr;
    }
} // namespace sdds