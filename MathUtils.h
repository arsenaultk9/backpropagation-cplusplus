#pragma once

#include<vector>

using namespace std;

class MathUtils
{
	static float sigmoid(float sourceArray);

public:
	static vector<float> sigmoid(vector<float> sourceArray);
	static vector<float> sigmoidDerivative(vector<float> source);

	static float meanSquaredCost(float y, float yHat);
	static float meanSquaredCostDerivative(float y, float yHat);
};

