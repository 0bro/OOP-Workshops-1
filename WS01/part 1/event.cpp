// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: September 27 2020
//

#include "event.h"

using namespace std;
// Global variable tracks timer between modules
unsigned int g_sysClock = 0;

namespace sdds
{
    // Constructor
    Event::Event()
    {
        m_eventDesc = nullptr;
    }
    // Destructor
    Event::~Event()
    {
        delete[] m_eventDesc;
        m_eventDesc = nullptr;
    }
    // Copy Constructor
    Event::Event(Event &src)
    {
        m_eventDesc = nullptr;
        *this = src;
    }
    // Assigment Operator
    Event &Event::operator=(Event &src)
    {
        // If source is valid
        if (src.m_eventDesc != nullptr && this != &src)
        {
            // Set data
            m_eventDesc = new char[strlen(src.m_eventDesc) + 1];
            strcpy(m_eventDesc, src.m_eventDesc);
            m_Time = src.m_Time;
        }
        // Return this
        return *this;
    }

    // Display Event
    void Event::display() const
    {
        // Static Local to Function Variable that tracks Rows
        static int l_counter = 0;

        // Formating
        cout.width(3);
        cout.fill(' ');
        cout << ++l_counter << ". ";

        // Check if event is valid
        if (m_eventDesc == nullptr)
        {
            // If not valid display
            cout << "[ No Event ]" << endl;
        }
        else
        {
            // Calculate times
            int seconds = m_Time % 60;
            int hours = m_Time / 60;
            int minutes = hours % 60;
            hours = hours / 60;

            // Formatting
            cout.width(2);
            cout.fill('0');
            cout << hours << ":";

            cout.width(2);
            cout.fill('0');
            cout << minutes << ":";

            cout.width(2);
            cout.fill('0');
            cout << seconds;

            // Event
            cout << " -> " << m_eventDesc << endl;
        }
    }

    // Set Event Data
    void Event::setDescription(char desc[])
    {
        // Delete previous Data
        delete[] m_eventDesc;
        m_eventDesc = nullptr;
        // If parameter is valid
        if (desc != nullptr && desc[0] != '\0')
        {
            // Set data
            m_eventDesc = new char[strlen(desc) + 1];
            strcpy(m_eventDesc, desc);
            m_Time = g_sysClock;
        }
    }

} // namespace sdds
