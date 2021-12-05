#include <iostream>
#include <fstream>

#include <list>
#include <vector>
#include <numeric>
#include <sstream>


#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

int main() {

    // read first line
    ifstream ReadFile("input.txt");
    string bingoElementsString;
    getline(ReadFile, bingoElementsString);
    stringstream bingoStream(bingoElementsString);

    // split elements by comma and add them to vector
    std::vector<int> bingoElements;

    while(bingoStream.good()) {
      string substr;
      getline(bingoStream, substr, ',');
      bingoElements.push_back(stoi(substr));
   }


    std::vector<MatrixXd> matrixes;
    string matrixElement;
    int i = 0, j = 0;
    int currentMatrix = -1;

    while (getline(ReadFile, matrixElement, ' ')) {
        if(j == 4) {
            string element;
            string currentLineElement;
            string nextLineElement;

            if(matrixElement.empty()) { //if the last element at the end of the line is a single digit number
                getline(ReadFile, element, ' ');
                currentLineElement = element.substr(0, element.find('\n'));
                nextLineElement = element.substr(element.find('\n') + 1, element.size());
            }
            else {
                currentLineElement = matrixElement.substr(0, matrixElement.find('\n'));
                nextLineElement = matrixElement.substr(matrixElement.find('\n') + 1, matrixElement.size());
            }
            
            std::cout << "position : " << i <<", " << j << " = ";
            cout << currentLineElement << endl;
            
            matrixElement = nextLineElement;

            j++;
        }

        if (!matrixElement.empty() && matrixElement!= " " && matrixElement!="\n") {
            if (j > 4) {
                j = 0;
                i++;
            }
            if (i > 4) {
                i = 0;
            }
            if (i == 0 && j == 0) {
                currentMatrix  = currentMatrix + 1;

                i = 0;
                j = 0;
                std::cout << "matrix: " << currentMatrix << endl;
            }
            
            std::cout << "position : " << i <<", " << j << " = ";
            std::cout << stoi(matrixElement) << endl;
            matrixes.at(currentMatrix)(i, j) = stoi(matrixElement);
            j++;
        }     

    }

   //for(int i = 0; i < bingoElements.size(); i++) {  
     // cout << bingoElements.at(i) << " ";
   //}

    // create array if matrixes 
    return 1;
}