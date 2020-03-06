#ifndef CSV_READER_H
#define CSV_READER_H

#include <vector>
#include <string>

/*
 * A class to read data from a csv file.
 */
class CsvReader
{
    std::string fileName;
    std::string delimeter;

public:
    CsvReader(std::string filename, std::string delm = ",");
    std::vector<std::vector<std::string>> getData();
};

#endif