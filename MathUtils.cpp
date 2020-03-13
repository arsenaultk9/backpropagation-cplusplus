#include "MathUtils.h"

float MathUtils::sigmoid(float source) {
	return 1 / (1 + exp(-source));
}

vector<float> MathUtils::sigmoid(vector<float> sourceArray) {
	vector <float> output(sourceArray.size());

	for (unsigned int index = 0; index < sourceArray.size(); index++) {
		output[index] = sigmoid(sourceArray[index]);
	}

	return output;
}

vector<float> MathUtils::sigmoidDerivative(vector<float> sourceArray)
{
	vector <float> output(sourceArray.size());

	for (unsigned int index = 0; index < sourceArray.size(); index++) {
		output[index] = sigmoid(sourceArray[index]) * (1 - sigmoid(sourceArray[index]));
	}

	return output;
}

float MathUtils::meanSquaredCost(float y, float yHat) {
	return pow((double)yHat - y, 2);
}

float MathUtils::meanSquaredCostDerivative(float y, float yHat)
{
	return 2 * (yHat - y);
}


