#ifndef RECORDSET_H_SDDS
#define RECORDSET_H_SDDS
#include <string>
#include <iostream>
#include <fstream>

namespace sdds
{

    class RecordSet
    {
        std::string *m_records;
        int m_recordSize;

    public:
        // Constructor
        RecordSet();
        // 1 arg Constructor
        RecordSet(const std::string fileName);
        // Copy Constructor
        RecordSet(RecordSet &src);
        // Assignment Constructor
        RecordSet &operator=(RecordSet &src);
        // Destructor
        ~RecordSet();
        // Returns Size Variable
        size_t size() const;
        // Returns Name of Record
        std::string getRecord(size_t index) const;
    };

}; // namespace sdds

#endif