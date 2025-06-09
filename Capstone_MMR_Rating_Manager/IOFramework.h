#pragma once

#include <string>
#include <vector>

class CSVReader {
public:
	static std::vector<std::vector<std::string>> CSVRead(std::string filePath); // string���� ����
	static std::vector<std::vector<float>> CSVRead_float(std::string filePath); // float���� ����
	static bool isNumber(std::string cell);
};

