#ifndef EVENT_H_SDDS
#define EVENT_H_SDDS

#include <iostream>
#include <cmath>
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