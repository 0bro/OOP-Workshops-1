
#include "Car.h"

using namespace std;
namespace sdds
{
    // c, Honda   , b, 145
    Car::Car(std::istream &is)
    {
        string temp;
        m_valid = true;
        getline(is, temp, ',');
        if (temp == "C" || temp == "c")
            m_tag = temp.at(0);
        else
        {
            m_tag = '0';
            m_valid = false;
        }

        getline(is, m_maker, ',');

        getline(is, temp, ',');
        if (temp == "N" || temp == "n" || temp == "U" || temp == "u" || temp == "B" || temp == "b")
            m_condition = temp.at(0);
        else
        {
            m_condition = '0';
            m_valid = false;
        }

        getline(is, temp);

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
    }

    double Car::topSpeed() const
    {
        return m_topSpeed;
    }
    void Car::display(std::ostream &os) const
    {
        // |     Toyota | new    | 157.00 |
        if (m_valid)
        {
            os << "|";
            os.width(11);
            os.fill(' ');
            os << m_maker << " | ";
            switch (m_condition.at(0))
            {
            case 'n':
            case 'N':
                os << "new    | ";
                break;

            case 'U':
            case 'u':
                os << "used   | ";
                break;

            case 'b':
            case 'B':
                os << "broken | ";
                break;
            }
            os << m_topSpeed;
        }
    }
    std::string Car::condition() const
    {
        return m_condition;
    }
} // namespace sdds