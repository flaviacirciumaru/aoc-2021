#include <iostream>
#include <fstream>

#include <list>
#include <vector>

using namespace std;

int main() {
    std::list<int> depths;
    string depth;
    int increases = 0; // having fun remembering to declare variables, otherwise shit happens

    ifstream ReadFile("input.txt");

    while ( getline(ReadFile, depth) ) {
        int intDepth = std::stoi(depth);
        
        depths.push_front(intDepth);

        std::cout << "Added depth: " << intDepth << endl;
    }

    std::vector<int> depthsInt(depths.begin(), depths.end());

    for (auto i = 0; i < depthsInt.size() - 1; i++) {

        if (depthsInt[i] > depthsInt[i + 1]) {

            std::cout << depthsInt[i] << " > " << depthsInt[i + 1] << endl;
            increases ++;

        }
    }

    std::cout << "Increases: " << increases << endl;

    return 1;
}