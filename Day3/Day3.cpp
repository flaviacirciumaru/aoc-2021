#include <iostream>
#include <fstream>

#include <list>
#include <vector>
#include <numeric>

using namespace std;

int GetNumberOfColumns(string fileName);
int GetOxygenGeneratorRating(int numberOfCol);
int GetCOScrubberRating(int numberOfCol);
void ChangeInputWithMostCommonBitNumbers(string inputName, string outputName, int colNumber, char mostCommonBit);

std::vector<int> GetColumnFromFile(int colNumber, string fileName, int numberOfCol);

int main() {
    std::vector<vector<int>> columns;
    std::vector<int> column;

    auto numberOfCol = GetNumberOfColumns("input.txt");

        column = GetColumnFromFile(0, "input.txt", numberOfCol);

        int oxygenGeneratorRating = GetOxygenGeneratorRating(numberOfCol);
        int co2ScrubberRating = GetCOScrubberRating(numberOfCol);

        std::cout << oxygenGeneratorRating * co2ScrubberRating;
}

int GetOxygenGeneratorRating(int numberOfCol) {
    int cursorPosition = 0;
    string inputFile;
    auto column = GetColumnFromFile(cursorPosition, "input.txt", numberOfCol);
    string lastNumber;

    while (column.size() >= 2) {
        std::cout<< "column size: "<< column.size() <<endl;
        std::cout<< "cursor position: "<< cursorPosition <<endl;

            auto mostCommonBitSum = std::accumulate(column.begin(), column.end(), 0);

            std::cout<< "mostCommonBitSum: "<< mostCommonBitSum <<endl;

            if (column.size() == 2) {
                 std::cout<< "common bit is 1" <<endl;
                 ChangeInputWithMostCommonBitNumbers("input.txt", "oxygen.txt", cursorPosition, '1');
            }
        
            if (mostCommonBitSum > column.size()/2) {
                std::cout<< "common bit is 1" <<endl;
                ChangeInputWithMostCommonBitNumbers("input.txt", "oxygen.txt", cursorPosition, '1');
            }
            else if (mostCommonBitSum * 2 == column.size()) {
                std::cout<< "common bit is 1" <<endl;
                ChangeInputWithMostCommonBitNumbers("input.txt", "oxygen.txt", cursorPosition, '1');
            }
            else {
                std::cout<< "common bit is 0" <<endl;
                ChangeInputWithMostCommonBitNumbers("input.txt", "oxygen.txt", cursorPosition, '0');
            }
            cursorPosition++;
            column = GetColumnFromFile(cursorPosition, "oxygen.txt", numberOfCol);
        }
        fstream fin("input.txt", fstream::in);
        getline(fin, lastNumber);
        cout << lastNumber << endl;
    return std::stoi(lastNumber, nullptr, 2);
}

int GetCOScrubberRating(int numberOfCol) {
    int cursorPosition = 0;
    string inputFile;
    auto column = GetColumnFromFile(cursorPosition, "input-copy.txt", numberOfCol); // got lazy copying lines around, hope the reader forgives me
    string lastNumber;

    while (column.size() >= 2) {
        std::cout<< "column size: "<< column.size() <<endl;
        std::cout<< "cursor position: "<< cursorPosition <<endl;

            auto mostCommonBitSum = std::accumulate(column.begin(), column.end(), 0);

            std::cout<< "mostCommonBitSum: "<< mostCommonBitSum <<endl;

            if (column.size() == 2) {
                 std::cout<< "least common bit is 0" <<endl;
                 ChangeInputWithMostCommonBitNumbers("input-copy.txt", "carbon.txt", cursorPosition, '0');
            }
        
            if (mostCommonBitSum > column.size()/2) {
                std::cout<< "least common bit is 1" <<endl;
                ChangeInputWithMostCommonBitNumbers("input-copy.txt", "carbon.txt", cursorPosition, '0');
            }
            else if (mostCommonBitSum * 2 == column.size()) {
                std::cout<< "least common bit is 0" <<endl;
                ChangeInputWithMostCommonBitNumbers("input-copy.txt", "carbon.txt", cursorPosition, '0');
            }
            else {
                std::cout<<"least common bit is 1" <<endl;
                ChangeInputWithMostCommonBitNumbers("input-copy.txt", "carbon.txt", cursorPosition, '1');
            }
            cursorPosition++;
            column = GetColumnFromFile(cursorPosition, "carbon.txt", numberOfCol);
        }
        fstream fin("input-copy.txt", fstream::in);
        getline(fin, lastNumber);
        cout << lastNumber << endl;
    return std::stoi(lastNumber, nullptr, 2);
}

void ChangeInputWithMostCommonBitNumbers(string inputName, string outputName, int colNumber, char mostCommonBit) {
    ofstream WriteFile(outputName, std::ofstream::out | std::ofstream::trunc);
    std::vector<int> column;
    fstream fin(inputName, fstream::in);
    string number;
    std::cout<< "file name: "<< outputName <<endl;

    while (getline(fin, number)) {
        if(number.at(colNumber) == mostCommonBit) {
            std::cout<< "number: "<< number <<endl;
            WriteFile << number << endl;
        }
    }

    WriteFile.close();

    fstream fout(outputName, fstream::in);
    ofstream CopyFile(inputName, std::ofstream::out | std::ofstream::trunc);

    while(getline(fout,number)){
            CopyFile << number << endl;
        }
}

std::vector<int> GetColumnFromFile(int colNumber, string fileName, int rowSize) {
    std::vector<int> column;
    fstream fin(fileName, fstream::in);
    char bit; 
    int cursorPosition = 0;
    int columnPosition = colNumber + rowSize;

    while (fin >> bit) {
        if (colNumber == 0) {
            if (cursorPosition % rowSize == 0) {
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