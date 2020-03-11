#include "Preprocessor.h"

vector<vector<float>> createValuesStructure(vector<vector<float>> xValues) {
	vector<vector<float>> valuesStructure(xValues.size());

	for (int rowIndex = 0; rowIndex < xValues.size(); rowIndex++) {
		vector<float> row = vector<float>(xValues[rowIndex].size());
		valuesStructure[rowIndex] = row;
	}

	return valuesStructure;
}

float getMinValue(vector<vector<float>> xValues, unsigned int columnIndex) {
	float minValue = std::numeric_limits<float>::max();

	for (vector<float> row : xValues) {
		float rowValue = row[columnIndex];

		minValue = minValue <= rowValue ? minValue : rowValue;
	}

	return minValue;
}

float getMaxValue(vector<vector<float>> xValues, unsigned int columnIndex) {
	float maxValue = -std::numeric_limits<float>::max();

	for (vector<float> row : xValues) {
		float rowValue = row[columnIndex];

		maxValue = maxValue >= rowValue ? maxValue : rowValue;
	}

	return maxValue;
}

vector<vector<float>> Preprocessor::scale(vector<vector<float>> xValues)
{
	vector<vector<float>> valuesScaled = createValuesStructure(xValues);

	for (int columnIndex = 0; columnIndex < xValues[0].size(); columnIndex++) {
		float minValue = getMinValue(xValues, columnIndex);
		float maxValue = getMaxValue(xValues, columnIndex);

		for (int rowIndex = 0; rowIndex < xValues.size(); rowIndex++) {
			valuesScaled[rowIndex][columnIndex] = (xValues[rowIndex][columnIndex] - minValue) / (maxValue - minValue);
		}
	}

	return valuesScaled;
}

vector<float> Preprocessor::addBias(vector<float> xValues)
{
	vector<float> valuesWithBias(xValues.size() + 1);

	for (unsigned int columnIndex = 0; columnIndex < xValues.size(); columnIndex++) {
		valuesWithBias[columnIndex] = xValues[columnIndex];
	}

	valuesWithBias[xValues.size()] = 1;

	return valuesWithBias;
}

vector<vector<float>> Preprocessor::addBias(vector<vector<float>> xValues)
{
	vector<vector<float>> valuesWithBias(xValues.size());

	for (unsigned int rowIndex = 0; rowIndex < xValues.size(); rowIndex++)
	{
		vector<float> row = xValues[rowIndex];
		valuesWithBias[rowIndex] = Preprocessor::addBias(row);
	}

	return valuesWithBias;
}


