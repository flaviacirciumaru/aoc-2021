#include <iostream>
#include <fstream>

#include <list>
#include <numeric>

using namespace std;

class Point {
    public: int horizontal;
    public: int depth;

    public:
    Point(){}

    Point(int horizontal, int depth) {
        this->horizontal = horizontal;
        this->depth = depth;
    }

    bool  operator==(const Point& otherPoint) {
        return this->horizontal == otherPoint.horizontal 
            && this->depth == otherPoint.depth;
    }

};

Point& CalculateCoordinates(string fileName);

int main() {
    auto point = CalculateCoordinates("input.txt");

    std::cout << point.horizontal * point.depth;
}

Point& CalculateCoordinates(string fileName) {
    ifstream ReadFile(fileName);
    int horizontal = 0;
    int depth = 0;
    std::string word;
    int aim = 0;

    while (ReadFile >> word) {
       if (word == "forward") {
            std::cout << word << " ";
            string direction;
            ReadFile >> direction;
            std::cout << std::stoi(direction) << " ";
            horizontal = horizontal + std::stoi(direction);
            depth = depth + aim*std::stoi(direction);

            std::cout << "horizontal: " << horizontal << " ";
            std::cout << "depth " << depth << endl;

        }
        if (word == "up") {
            std::cout << word << " ";
            string direction;
            ReadFile >> direction;
            std::cout << -1 * std::stoi(direction) << " ";
            aim = aim -  std::stoi(direction);
            std::cout << "aim: " << aim << endl;
        }
        if (word == "down") {
            std::cout << word << " ";
            string direction;
            ReadFile >> direction;
            std::cout <<  direction << " ";
            aim += std::stoi(direction);
            std::cout << "aim: " << aim << endl;
        }
    }

    std::cout <<  "H: " << horizontal << endl;
    std::cout <<  "D: " << depth << endl;

    Point* point = new Point(horizontal, depth);
    return *point;
}