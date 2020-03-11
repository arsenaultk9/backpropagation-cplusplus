#include "MatrixOperator.h"

vector<float> MatrixOperator::dotProduct(vector<float> fromVector, vector<vector<float>> toMatrix)
{
	vector<float> dotProduct(toMatrix[0].size());

	for (unsigned int nodeIndex = 0; nodeIndex < toMatrix[0].size(); nodeIndex++) {
		float nodeSummation = 0;

		for (unsigned int inputIndex = 0; inputIndex < fromVector.size(); inputIndex++) {
			nodeSummation += fromVector[inputIndex] * toMatrix[inputIndex][nodeIndex];
		}

		dotProduct[nodeIndex] = nodeSummation;
	}

	return dotProduct;
}
