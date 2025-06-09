#pragma once

#include <string>
#include <vector>

class CSVReader {
public:
	static std::vector<std::vector<std::string>> CSVRead(std::string filePath); // string으로 읽음
	static std::vector<std::vector<float>> CSVRead_float(std::string filePath); // float으로 읽음
	static bool isNumber(std::string cell);
};

