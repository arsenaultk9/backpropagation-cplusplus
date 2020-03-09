#pragma once

#include <vector>
#include <string>

using namespace std;

class Preprocessor
{
public:
	vector<vector<float>> scale(vector<vector<float>> xValues);
	vector<vector<float>> addBias(vector<vector<float>> xValues);
};

