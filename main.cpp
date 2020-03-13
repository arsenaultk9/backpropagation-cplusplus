#include <iostream>
#include <vector>
#include <string>

#include "CSVReader.h"
#include "DataPreparator.h";
#include "Preprocessor.h"
#include "RandomMatrixGenerator.h"
#include "MatrixOperator.h"
#include "MathUtils.h"

using namespace std;

int main()
{
	CsvReader reader("pima-indians-diabetes.data.csv"); // 9 column source. 
	std::vector<std::vector<float>> dataSet = reader.getData();

	DataPreparator preparator;
	vector<vector<float>> xValues = preparator.getXData(dataSet, 8);
	vector<float> yValues = preparator.getYData(dataSet, 8);

	Preprocessor preprocessor;
	vector<vector<float>> xValuesScaled = preprocessor.scale(xValues);

	RandomMatrixGenerator randomMatrixGenerator;

	vector<vector<float>> w1 = randomMatrixGenerator.generateMatrix(9, 4);
	vector<vector<float>> w2 = randomMatrixGenerator.generateMatrix(5, 1);

	vector<vector<float>> xValuesTraining = preprocessor.addBias(xValuesScaled);

	MatrixOperator matrixOperator;

	vector<float>(*activationFunctionPtr)(vector<float>) { MathUtils::sigmoid };
	float (*costFunctionPtr)(float, float) { MathUtils::meanSquaredCost };
	float (*costDerivativeFunctionPtr)(float, float) { MathUtils::meanSquaredCostDerivative };

	for (unsigned int iteration = 0; iteration < 9000; iteration++) {
		vector<float> yHats;
		float cost = 0;

		for (unsigned int dataIndex = 0; dataIndex < xValuesTraining.size(); dataIndex++) {
			vector<float> currentX = xValuesTraining[dataIndex];
			vector<float> productW1 = matrixOperator.dotProduct(currentX, w1);
			
			vector<float> activationW1 = activationFunctionPtr(productW1);
			activationW1 = preprocessor.addBias(activationW1);

			vector<float> productW2 = matrixOperator.dotProduct(activationW1, w2);
			vector<float> activationW2 = activationFunctionPtr(productW2);

			float yHat = activationW2[0];
			yHats.push_back(yHat);

			float y = yValues[dataIndex];
			cost = costFunctionPtr(y, yHat) / xValuesTraining.size();

			float yHatDerivative = costDerivativeFunctionPtr(y, yHat);
			vector<float> w2ActivationDerivative = matrixOperator.scalarMultiplication(MathUtils::sigmoidDerivative(productW2), yHatDerivative);
		}

		if (iteration % 100 == 0) {
			cout << "iteration: " << iteration << endl;
			cout << "cost: " << cost << endl;
		}
	}
}