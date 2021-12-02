#include <iostream>
#include <fstream>

#include <list>
#include <vector>

using namespace std;

std::list<int> ParseDepths(string fileName);
int GetNumberOfIncreasesFromList(std::list<int> depths);

int main() {
    std::list<int> depths;
    string depth;
    int increases = 0;

    depths = ParseDepths("input.txt");

    std::cout << "Increases: " << GetNumberOfIncreasesFromList(depths) << endl;

    return 1;
}

std::list<int> ParseDepths(string fileName) {
    ifstream ReadFile(fileName);
    std::list<int> depths;
    string depth;

    while ( getline(ReadFile, depth) ) {
        int intDepth = std::stoi(depth);
        
        depths.push_front(intDepth);
    }
    return depths;
}

int GetNumberOfIncreasesFromList(std::list<int> depths) {

    std::vector<int> depthsInt(depths.begin(), depths.end());
    int increases = 0;

    for (auto i = 0; i < depthsInt.size() - 1; i++) {

        if (depthsInt[i] > depthsInt[i + 1]) {

            std::cout << depthsInt[i] << " > " << depthsInt[i + 1] << endl;
            increases ++;
        }
    }

    return increases;
}