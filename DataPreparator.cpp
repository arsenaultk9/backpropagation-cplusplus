#include "DataPreparator.h"

using namespace std;

DataPreparator::DataPreparator()
{
}

vector<vector<string>> DataPreparator::getXData(vector<vector<string>> dataSet, int nbOfColumns)
{
	vector<vector<string>> xData(dataSet.size());

	int currentRow = 0;
	for (vector<string> line : dataSet)
	{
		vector<string> xDataRow(nbOfColumns);

		for (unsigned int column = 0; column < nbOfColumns; column++)
		{
			xDataRow[column] = line[column];
		}

		xData[currentRow] = xDataRow;
		currentRow++;
	}

	return xData;
}

vector<string> DataPreparator::getYData(vector<vector<string>> dataSet, int nbOfColumnsToSkip)
{
	vector<string> yData(dataSet.size());

	int currentRow = 0;
	for (vector<string> line : dataSet)
	{
		yData[currentRow] = line[nbOfColumnsToSkip];
		currentRow++;
	}

	return yData;
}
