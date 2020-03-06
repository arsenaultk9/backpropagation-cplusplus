#include <iostream>
#include <vector>
#include <string>

#include "CSVReader.h"
#include "DataPreparator.h";

using namespace std;

int main()
{
    CsvReader reader("pima-indians-diabetes.data.csv"); // 9 column source. 
    std::vector<std::vector<std::string>> dataSet = reader.getData();

    DataPreparator preparator;
    vector<vector<string>> xValue = preparator.getXData(dataSet, 8);
    vector<string> yVale = preparator.getYData(dataSet, 8);

    // Print the content of row by row on screen
    for (std::vector<std::string> line : dataSet)
    {
        for (std::string entry : line)
        {
            std::cout << entry << " , ";
        }
        std::cout << std::endl;
    }
}