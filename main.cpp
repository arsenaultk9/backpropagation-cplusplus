#include <iostream>
#include <vector>
#include <string>

#include "CSVReader.h"

using namespace std;

int main()
{
    CsvReader reader("pima-indians-diabetes.data.csv");
    std::vector<std::vector<std::string>> dataList = reader.getData();

    // Print the content of row by row on screen
    for (std::vector<std::string> vec : dataList)
    {
        for (std::string data : vec)
        {
            std::cout << data << " , ";
        }
        std::cout << std::endl;
    }
}