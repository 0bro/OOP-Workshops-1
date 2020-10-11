// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: October 4 2020

#include "RecordSet.h"

using namespace std;

namespace sdds
{
    // Constructor
    RecordSet::RecordSet()
    {
        m_records = nullptr;
        m_recordSize = 0;
    }
    // 1 arg Constructor
    RecordSet::RecordSet(const std::string fileName)
    {
        ifstream file(fileName);
        int count = 0;
        string word;
        // Step 1: Counting amount of words.
        // While file is valid
        while (file)
        {
            // Get a word with the delimeter of a space
            getline(file, word, ' ');
            // If the word is not empty then add to count
            if (word[0] != ' ' && file)
            {
                // increment count
                count++;
            }
        }
        // Resets to the start of the file
        file.clear();
        file.seekg(0);

        // Allocates Space for strings
        m_records = new string[count];
        m_recordSize = count;

        // Re-read and load words into Records
        for (size_t i = 0; i < m_recordSize; i++)
        {
            // Get a word with the delimeter of a space
            getline(file, word, ' ');
            // Assign to Record
            m_records[i].assign(word);
        }
    }
    // Copy Constructor
    RecordSet::RecordSet(RecordSet &src)
    {
        // Set to safe state
        m_records = nullptr;
        m_recordSize = 0;
        // Use copy assignment operator
        *this = src;
    }
    // Assignment Constructor
    RecordSet &RecordSet::operator=(RecordSet &src)
    {
        if (this != &src)
        {
            // Delete current instance
            delete[] m_records;
            // Assign to src Size
            m_recordSize = src.m_recordSize;
            // Dyanmically allocate string array
            m_records = new string[m_recordSize];
            // Using recordSize to assign records to this object from SRC object
            for (size_t i = 0; i < m_recordSize; i++)
                m_records[i].assign(src.m_records[i]);
        }
        return *this;
    }
    // Move constructor
    RecordSet::RecordSet(RecordSet &&src)
    {
        // Set to safe state
        m_records = nullptr;
        m_recordSize = 0;
        // Use move assignment operator
        *this = std::move(src);
    }
    // Move assignment
    RecordSet &RecordSet::operator=(RecordSet &&src)
    {
        if (this != &src)
        {
            // Delete current instance
            delete[] m_records;
            // Assign to src Size
            m_recordSize = src.m_recordSize;
            // Dyanmically allocate string array
            m_records = src.m_records;
            src.m_records = nullptr;
            src.m_recordSize = 0;
        }
        return *this;
    }

    // Destructor
    RecordSet::~RecordSet()
    {
        // Deallocate dynamically set records
        delete[] m_records;
        m_records = nullptr;
    }
    // Returns Size Variable
    size_t RecordSet::size() const
    {
        return m_recordSize;
    }
    // Returns Name of Record
    std::string RecordSet::getRecord(size_t index) const
    {
        // Safe state
        string output = "";
        // If Index is within range
        if (index < m_recordSize)
        {
            // Assign to output
            output.assign(m_records[index]);
        }
        return output;
    }
} // namespace sdds
