#pragma once

#include <vector>
#include <string>

using namespace std;

class DataPreparator
{
public:
	DataPreparator();

	vector<vector<string>> getXData(vector<vector<string>> dataSet, int nbOfColumns);
	vector<string> getYData(vector<vector<string>> dataSet, int nbOfColumnsToSkip);
};

