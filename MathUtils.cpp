#include "MathUtils.h"

vector<float> MathUtils::sigmoidVector(vector<float> sourceArray) {
	vector <float> output(sourceArray.size());

	for (unsigned int index = 0; index < sourceArray.size(); index++) {
		output[index] = 1 / (1 + exp(-sourceArray[index]));
	}

	return output;
}
