#include "pch.h"
#include "IOFramework.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<std::string>> CSVReader::CSVRead(std::string filePath) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "������ �� �� �����ϴ�: " << filePath << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    file.close();
    return data;
}

std::vector<std::vector<float>> CSVReader::CSVRead_float(std::string filePath) {
    std::vector<std::vector<float>> data;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "������ �� �� �����ϴ�: " << filePath << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<float> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            try {
                // ���ڸ� float���� ��ȯ�Ͽ� ����
                float value = std::stof(cell);
                row.push_back(value);
            }
            catch (const std::invalid_argument& e) {
                // ���ڰ� �ƴ� ��� ����
                continue;
            }
        }
        data.push_back(row);
    }

    file.close();
    return data;
}
