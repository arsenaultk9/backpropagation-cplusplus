#include <iostream>
#include <vector>
#include <string>

#include "CSVReader.h"
#include "DataPreparator.h";
#include "Preprocessor.h"

using namespace std;

int main()
{
    CsvReader reader("pima-indians-diabetes.data.csv"); // 9 column source. 
    std::vector<std::vector<float>> dataSet = reader.getData();

    DataPreparator preparator;
    vector<vector<float>> xValue = preparator.getXData(dataSet, 8);
    vector<float> yVale = preparator.getYData(dataSet, 8);

    Preprocessor preprocessor;
    vector<vector<float>> xValueScale = preprocessor.scale(xValue);
}