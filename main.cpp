#include <iostream>
#include <vector>
#include <string>

#include "CSVReader.h"
#include "DataPreparator.h";
#include "Preprocessor.h"
#include "RandomMatrixGenerator.h"

using namespace std;

int main()
{
    CsvReader reader("pima-indians-diabetes.data.csv"); // 9 column source. 
    std::vector<std::vector<float>> dataSet = reader.getData();

    DataPreparator preparator;
    vector<vector<float>> xValue = preparator.getXData(dataSet, 8);
    vector<float> yVale = preparator.getYData(dataSet, 8);

    Preprocessor preprocessor;
    vector<vector<float>> xValuesScaled = preprocessor.scale(xValue);

    RandomMatrixGenerator randomMatrixGenerator;

    vector<vector<float>> w1 = randomMatrixGenerator.generateMatrix(9, 4);
    vector<vector<float>> w2 = randomMatrixGenerator.generateMatrix(5, 1);

    vector<vector<float>> xValuesTraining = preprocessor.addBias(xValuesScaled);
    for (unsigned int iteration = 0; iteration < 9000; iteration++) {
        cout << iteration;
    }
}