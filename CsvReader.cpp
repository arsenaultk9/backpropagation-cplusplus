#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

#include "CsvReader.h";

CsvReader::CsvReader(std::string filename, std::string delm) : fileName(filename), delimeter(delm)
{
}

/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/
std::vector<std::vector<float>> CsvReader::getData()
{
	std::ifstream file(fileName);

	std::vector<std::vector<float>> dataList;

	std::string line = "";
	// Iterate through each line and split the content using delimeter
	while (getline(file, line))
	{
		std::vector<std::string> vec;
		boost::algorithm::split(vec, line, boost::is_any_of(delimeter));

		std::vector<float> vecFloat;
		for (std::string val : vec) 
		{
			vecFloat.push_back(std::stof(val));
		}

		dataList.push_back(vecFloat);
	}
	// Close the File
	file.close();

	return dataList;
}