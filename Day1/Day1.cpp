#include <iostream>
#include <fstream>

#include <list>
#include <vector>

using namespace std;

std::list<int> ParseDepths(string fileName);
int GetNumberOfIncreasesFromList(std::list<int> depths);
std::list<int> GetThreeMeasurementsSums(std::list<int> depths);

int main() {
    std::list<int> depths;
    string depth;
    int increases = 0;

     depths = ParseDepths("input.txt");
     //depths = {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};
    auto threeMeasurementsSums = GetThreeMeasurementsSums(depths);

    std::cout << "Increases: " << GetNumberOfIncreasesFromList(threeMeasurementsSums) << endl;

    return 1;
}

std::list<int> ParseDepths(string fileName) {
    ifstream ReadFile(fileName);
    std::list<int> depths;
    string depth;

    while ( getline(ReadFile, depth) ) {
        int intDepth = std::stoi(depth);
        
        depths.push_back(intDepth);
    }
    return depths;
}

int GetNumberOfIncreasesFromList(std::list<int> depths) {

    std::vector<int> depthsVector(depths.begin(), depths.end());
    int increases = 0;

    for (auto i = 0; i < depthsVector.size() - 1; i++) {

        if (depthsVector[i] < depthsVector[i + 1]) {

            std::cout << depthsVector[i] << " < " << depthsVector[i + 1] << endl;
            increases ++;
        }
    }

    return increases;
}

std::list<int> GetThreeMeasurementsSums (std::list<int> depths) {
    std::list<int> threeMeasurementsSums;
    std::vector<int> depthsVector(depths.begin(), depths.end());

    for (auto i = 0; i < depthsVector.size() - 2; i++) {
        auto sum  = depthsVector[i] + depthsVector[i + 1] + depthsVector[i + 2];
        std::cout << sum << " = " << depthsVector[i] << " + " << depthsVector[i + 1] << " + " << depthsVector[i + 2] << endl;
        threeMeasurementsSums.push_back(sum);
    }

    std::cout << "length  " << threeMeasurementsSums.size() << endl;

    return threeMeasurementsSums;
}