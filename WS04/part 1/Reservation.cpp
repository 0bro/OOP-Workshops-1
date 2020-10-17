#include "Reservation.h"
using namespace std;
namespace sdds
{

    Reservation::Reservation()
    {
        m_reserveName = "";
        m_email = "";
        m_partySize = 0;
        m_day = 0;
        m_hour = 0;
    }
    Reservation::Reservation(const string &res)
    {

        string str = res;
        str.erase(remove(str.begin(), str.end(), ' '), str.end());

        m_reserveID = str.substr(str.find("RES"), str.find(':'));
        str = str.substr(m_reserveID.length() + 1);

        m_reserveName = str.substr(0, str.find(','));
        str = str.substr(m_reserveName.length() + 1);

        m_email = str.substr(0, str.find(','));
        str = str.substr(m_email.length() + 1);

        m_partySize = stoi(str.substr(0, str.find(',')));
        std::cout << stoi(str.substr(0, str.find(','))) << endl;
        str = str.substr(to_string(m_partySize).length() + 1);

        m_day = stoi(str.substr(0, str.find(',')));
        str = str.substr(to_string(m_day).length() + 1);

        m_hour = stoi(str.substr(0, str.find(',')));
        str = str.substr(to_string(m_hour).length());
    }

    std::ostream &operator<<(std::ostream &os, Reservation out)
    {
        os.width(10);
        os.fill(' ');
        os << "Reservation " << out.m_reserveID << ":";

        os.width(10);
        os.fill(' ');
        // Instructions asked for a field of 10, but sample has an additional 2,
        // I added these two manually so that instructions are followed.
        os << out.m_reserveName << "  ";

        os << std::left;
        os.width(20);
        os.fill(' ');
        os << "<" + out.m_email + ">";
        os << std::right;
        // Instructions ask for a field of 20 but sample counts an extra 4,
        // so I added this manually so that Field would be correct,
        // and corrections are made based on sample.
        os << "    ";

        if (out.m_hour >= 6 && out.m_hour <= 9)
            os << "Breakfast ";
        else if (out.m_hour >= 11 && out.m_hour <= 14)
            os << "Lunch ";
        else if (out.m_hour >= 5 && out.m_hour <= 21)
            os << "Dinner ";
        else
            os << "Drinks ";

        os << "on day " << out.m_day
           << " @ " << out.m_hour
           << ":00 for " << out.m_partySize << " people.";

        os << endl;
        return os;
    }

} // namespace sdds
