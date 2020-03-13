#pragma once

#include <vector>

using namespace std;

class MatrixOperator
{
public:
	vector<float> dotProduct(vector<float> fromVector, vector<vector<float>> toMatrix);
	vector<float> scalarMultiplication(vector<float> fromVector, float scaler);
};

