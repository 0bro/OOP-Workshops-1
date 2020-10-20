
#include "ConfirmationSender.h"
using namespace std;

namespace sdds
{
    ConfirmationSender::ConfirmationSender()
    {
        m_reservation = nullptr;
        m_count = 0;
    }

    ConfirmationSender::~ConfirmationSender()
    {
        delete[] m_reservation;
    }
    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &res)
    {
        bool PresentFlag = false;

        if (m_count == 0)
        {
            m_reservation = new const Reservation *[1];
            m_reservation[0] = &res;
            m_count++;
        }
        else
        {
            for (size_t i = 0; i < m_count; i++)
            {
                if (m_reservation[i] == &res)
                    PresentFlag = true;
            }

            if (!PresentFlag)
            {
                Reservation resTemp[m_count + 1];
                for (int i = 0; i < m_count; i++)
                    resTemp[i] = *m_reservation[i];

                delete[] m_reservation;
                m_reservation = new const Reservation *[++m_count];

                for (int i = 0; i < m_count; i++)
                    m_reservation[i] = &resTemp[i];
            }
        }

        return *this;
    }
    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res)
    {
        bool presentFlag = false;
        size_t indx = 0;

        for (size_t i = 0; i < m_count; i++)
        {
            if (m_reservation[i] == &res)
            {
                presentFlag = true;
                indx = i;
            }
        }

        if (presentFlag)
        {
            Reservation resTemp[m_count];

            m_reservation[indx] = m_reservation[m_count - 1];

            for (int i = 0; i < m_count; i++)
                resTemp[i] = *m_reservation[i];

            delete[] m_reservation;
            m_reservation = new const Reservation *[--m_count];

            for (int i = 0; i < m_count; i++)
                m_reservation[i] = &resTemp[i];
        }

        return *this;
    }
    size_t ConfirmationSender::size() const
    {
        return m_count;
    }
    void ConfirmationSender::display() const
    {
        for (int i = 0; i < m_count; i++)
            std::cout << &m_reservation[i];
    }
    std::ostream &
    operator<<(std::ostream &os, ConfirmationSender &confSend)
    {
        os << "--------------------------" << endl
           << "Confirmations to Send" << endl
           << "--------------------------" << endl;

        if (confSend.size() == 0)
        {
            os << "The object is empty!" << endl;
        }
        else
        {

            confSend.display();
        }
        os << "--------------------------" << endl;
        return os;
    }

} // namespace sdds
