// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: October 4 2020

#include "TimedEvents.h"

using namespace std;

namespace sdds
{

    // Constructor
    TimedEvents::TimedEvents()
    {
        // Set the number of records as 0
        m_numOfRecords = 0;
    }
    // Starts timer for event
    void TimedEvents::startClock()
    {
        // Set the start time as current time
        m_startTime = std::chrono::steady_clock::now();
    }
    // Stops timer for event
    void TimedEvents::stopClock()
    {
        // Set the end time as current time
        m_endTime = std::chrono::steady_clock::now();
    }
    // a modifier that receives the address of a C-style null terminated string and holds it
    void TimedEvents::recordEvent(const string &eventName)
    {
        // Aslong as as the amount of records isn't the same as the limit
        if (m_numOfRecords != MAX_RECORDS)
        {
            // Assign the data to records
            records[m_numOfRecords].m_eventName.assign(eventName);
            records[m_numOfRecords].m_unitsOfTime.assign("nanoseconds");
            records[m_numOfRecords].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
            m_numOfRecords++;
        }
    }
    // Outputs The event
    std::ostream &operator<<(std::ostream &out, const TimedEvents &src)
    {
        // Header
        out << "--------------------------" << endl
            << "Execution Times:" << endl
            << "--------------------------" << endl;
            // For the amount of records
        for (int i = 0; i < src.m_numOfRecords; i++)
        {
            // Formatting and outputting data
            out.width(20);
            out.fill(' ');
            out << left << src.records[i].m_eventName;

            out.width(12);
            out.fill(' ');
            out << right << src.records[i].m_duration.count();

            out << " " << src.records[i].m_unitsOfTime << endl;
        }
        out << "--------------------------"<< endl;
        return out;
    }

} // namespace sdds
