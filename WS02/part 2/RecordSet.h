// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: October 4 2020

#ifndef RECORDSET_H_SDDS
#define RECORDSET_H_SDDS
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ratio>
#include <thread>

namespace sdds
{

    class RecordSet
    {
        std::string *m_records;
        size_t m_recordSize;

    public:
        // Constructor
        RecordSet();
        // 1 arg Constructor
        RecordSet(const std::string fileName);
        // Copy Constructor
        RecordSet(RecordSet &src);
        // Assignment Constructor
        RecordSet &operator=(RecordSet &src);
        // Move constructor
        RecordSet(RecordSet&& src);
        // Move assignment 
        RecordSet& operator=(RecordSet&& src);
        // Destructor
        ~RecordSet();
        // Returns Size Variable
        size_t size() const;
        // Returns Name of Record
        std::string getRecord(size_t index) const;
    };

}; // namespace sdds

#endif