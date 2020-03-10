#include "MatrixOperator.h"

vector<float> MatrixOperator::dotProduct(vector<float> fromVector, vector<vector<float>> toMatrix)
{
	vector<float> dotProduct(toMatrix[0].size());

	for (unsigned int nodeIndex = 0; nodeIndex < toMatrix[0].size(); nodeIndex++) {
		for (unsigned int inputIndex = 0; inputIndex < fromVector.size(); inputIndex++) {
			dotProduct[nodeIndex] += fromVector[inputIndex] * toMatrix[inputIndex][nodeIndex];
		}
	}

	return dotProduct;
}
