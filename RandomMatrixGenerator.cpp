#include "RandomMatrixGenerator.h"

float getValueBetweenZeroAndOne() {
	return static_cast<float>(rand()) / static_cast <float> (RAND_MAX);
}

vector<vector<float>> RandomMatrixGenerator::generateMatrix(int rowCount, int columnCount)
{
	vector<vector<float>> matrix(rowCount);

	for (unsigned int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
		matrix[rowIndex] = vector<float>(columnCount);

		for (unsigned int columnIndex = 0; columnIndex < columnCount; columnIndex++) {
			matrix[rowIndex][columnIndex] = getValueBetweenZeroAndOne();
		}
	}

	return matrix;
}
