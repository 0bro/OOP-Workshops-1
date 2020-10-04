#include "TimedEvents.h"

using namespace std;

namespace sdds
{

    // Constructor
    TimedEvents::TimedEvents()
    {
        m_numOfRecords = 0;
    }
    // Starts timer for event
    void TimedEvents::startClock()
    {
        m_startTime = std::chrono::steady_clock::now();
    }
    // Stops timer for event
    void TimedEvents::stopClock()
    {
        m_endTime = std::chrono::steady_clock::now();
    }
    // a modifier that receives the address of a C-style null terminated string and holds it
    void TimedEvents::recordEvent(const string &eventName)
    {
        if (m_numOfRecords != MAX_RECORDS)
        {
            records[m_numOfRecords].m_eventName.assign(eventName);
            records[m_numOfRecords].m_unitsOfTime.assign("nanoseconds");
            records[m_numOfRecords].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
            m_numOfRecords++;
        }
    }
    // Outputs The event
    std::ostream &operator<<(std::ostream &out, const TimedEvents &src)
    {
        out << "--------------------------" << endl
            << "Execution Times:" << endl
            << "--------------------------" << endl;
        for (int i = 0; i < src.m_numOfRecords; i++)
        {
            out.width(20);
            out.fill(' ');
            out << left << src.records[i].m_eventName;

            out.width(12);
            out.fill(' ');
            out << right << src.records[i].m_duration.count();

            out << " " << src.records[i].m_unitsOfTime << endl;
        }
        out << "--------------------------";
        return out;
    }

} // namespace sdds
