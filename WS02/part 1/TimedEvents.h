#ifndef TIMED_EVENTS_H_SDDS
#define TIMED_EVENTS_H_SDDS

#include <iostream>
#include <string>

namespace sdds
{
    const int MAX_RECORDS = 7;
    class TimedEvents
    {
        int m_numOfRecords;
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;
        struct
        {
            std::string m_eventName;
            std::string m_unitsOfTime;
            std::chrono::steady_clock::duration m_duration;
        } records[MAX_RECORDS];

    public:
        // Constructor
        TimedEvents();
        // Starts timer for event
        void startClock();
        // Stops timer for event
        void stopClock();
        // a modifier that receives the address of a C-style null terminated string and holds it 
        void recordEvent(const std::string &eventName);
        // Outputs The event 
        friend std::ostream& operator<<(std::ostream&, const TimedEvents& src);

    };

}; // namespace sdds

#endif