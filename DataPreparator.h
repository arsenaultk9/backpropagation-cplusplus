#pragma once

#include <vector>
#include <string>

using namespace std;

class DataPreparator
{
public:
	DataPreparator();

	vector<vector<float>> getXData(vector<vector<float>> dataSet, int nbOfColumns);
	vector<float> getYData(vector<vector<float>> dataSet, int nbOfColumnsToSkip);
};

