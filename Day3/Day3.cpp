#include <iostream>
#include <fstream>

#include <list>
#include <vector>
#include <numeric>

using namespace std;

int GetNumberOfColumns(string fileName);
std::vector<int> GetColumnFromFile(int colNumber, string fileName, int numberOfCol);

int main() {
    std::vector<vector<int>> columns;
    std::vector<int> column;
    int mostCommonBitSum = 0;
    string gammaRate;
    string epsilonRate;

    auto numberOfCol = GetNumberOfColumns("input.txt");

    for (auto i = 0; i < numberOfCol; i++) {
        int mostCommonBitSum = 0;
        column = GetColumnFromFile(i, "input.txt", numberOfCol);
        mostCommonBitSum = std::accumulate(column.begin(), column.end(), 0);
        
        if (mostCommonBitSum < column.size()/2) {
            gammaRate.push_back('0');
            epsilonRate.push_back('1');
        }
        else {
            gammaRate.push_back('1');
            epsilonRate.push_back('0');
        }
    }
     int gamma = std::stoi(gammaRate, nullptr, 2);
     int epsilon = std::stoi(epsilonRate, nullptr, 2);

    std::cout<< gammaRate << " " << gamma <<endl;
    std::cout<< epsilonRate << " " << epsilon <<endl;

    std::cout << gamma * epsilon;
}

std::vector<int> GetColumnFromFile(int colNumber, string fileName, int rowSize) {
    std::vector<int> column;
    fstream fin(fileName, fstream::in);

    char bit; 

    int cursorPosition = 0;
    int columnPosition = colNumber + rowSize;

    while (fin >> bit) {
        if (colNumber == 0) { // to avoid dividing by 0 later on
            if (cursorPosition % columnPosition == 0) {
                column.push_back((int) bit - '0');
            }
        }
        else if (cursorPosition == colNumber) {
            column.push_back((int) bit - '0');
        }
        else if (cursorPosition > rowSize && cursorPosition % (columnPosition) == 0) {
            column.push_back((int) bit - '0');
            columnPosition = columnPosition + rowSize;
        }
        cursorPosition++;
    }
    return column;
}

int GetNumberOfColumns(string fileName) {
    ifstream ReadFile(fileName);;
    string line;

   getline(ReadFile, line);
    
    return line.length();
}