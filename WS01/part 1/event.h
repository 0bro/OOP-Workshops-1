// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: September 27 2020
//

#ifndef EVENT_H_SDDS
#define EVENT_H_SDDS

#include <iostream>
#include <cmath>
#include <cstring>

// Global variable tracks timer between modules
extern unsigned int g_sysClock;

namespace sdds
{

    class Event
    {
        // Dynamically set Description
        char *m_eventDesc;
        // Time the event occured
        unsigned int m_Time;

    public:
        // Constructor
        Event();
        // Desctructor
        ~Event();
        // Copy Constuctor
        Event(Event &src);
        // Assignment Operator
        Event &operator=(Event &src);
        // Display Event
        void display() const;
        // Set Event Data
        void setDescription(char desc[]);
    };

} // namespace sdds

#endif