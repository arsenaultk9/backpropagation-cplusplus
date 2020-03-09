#include "DataPreparator.h"

using namespace std;

DataPreparator::DataPreparator()
{
}

vector<vector<float>> DataPreparator::getXData(vector<vector<float>> dataSet, int nbOfColumns)
{
	vector<vector<float>> xData(dataSet.size());

	int currentRow = 0;
	for (vector<float> line : dataSet)
	{
		vector<float> xDataRow(nbOfColumns);

		for (unsigned int column = 0; column < nbOfColumns; column++)
		{
			xDataRow[column] = line[column];
		}

		xData[currentRow] = xDataRow;
		currentRow++;
	}

	return xData;
}

vector<float> DataPreparator::getYData(vector<vector<float>> dataSet, int nbOfColumnsToSkip)
{
	vector<float> yData(dataSet.size());

	int currentRow = 0;
	for (vector<float> line : dataSet)
	{
		yData[currentRow] = line[nbOfColumnsToSkip];
		currentRow++;
	}

	return yData;
}
