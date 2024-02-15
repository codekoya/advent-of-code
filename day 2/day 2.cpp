#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main(int argc, char* argv[])
{
    std::ifstream file("input.txt");
    std::string line = "";
    int gameId = 0, gameNum = 0;
    int sum = 0, minSum = 0;
    std::string word;
    while (std::getline(file, line)) {
        int minRed = 0, minGreen = 0, minBlue = 0;
        std::stringstream ss(line);
        ss >> word;
        ss >> gameId;
        ss.ignore(1);
        while (ss >> gameNum) {
            ss >> word;
            switch (word[0]) {
            case 'r':
                if (gameNum > 12)
                    gameId = 0;
                minRed = std::max(minRed, gameNum);
                break;
            case 'g':
                if (gameNum > 13)
                    gameId = 0;
                minGreen = std::max(minGreen, gameNum);
                break;
            case 'b':
                if (gameNum > 14)
                    gameId = 0;
                minBlue = std::max(minBlue, gameNum);
                break;
            }
        }
        sum += gameId;
        minSum += minRed * minGreen * minBlue;
        printf("minSum %d \n", minSum);
    }
}