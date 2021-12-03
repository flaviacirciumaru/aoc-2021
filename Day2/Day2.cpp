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
    std::list<int> horizontals;
    std::list<int> verticals;

    while (ReadFile >> word) {
       if (word == "forward") {
            std::cout << word << " ";
            string direction;
            ReadFile >> direction;
            std::cout << direction << endl;
            verticals.push_back(std::stoi(direction));
        }
        if (word == "up") {
            std::cout << word << " ";
            string direction;
            ReadFile >> direction;
            std::cout << -1 * std::stoi(direction) << endl;
            horizontals.push_back(-1 * std::stoi(direction));
        }
        if (word == "down") {
            std::cout << word << " ";
            string direction;
            ReadFile >> direction;
            std::cout <<  direction << endl;
            horizontals.push_back(std::stoi(direction));
        }
    }
    
    horizontal  = std::accumulate(horizontals.begin(), horizontals.end(), 0);
    std::cout <<  "H: " << horizontal << endl;

    depth = std::accumulate(verticals.begin(), verticals.end(), 0);
    std::cout <<  "D: " << depth << endl;

    Point* point = new Point(horizontal, depth);
    return *point;
}