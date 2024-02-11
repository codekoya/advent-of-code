
#include <iostream>
#include <fstream>
#include <map>
#include <string>

int extractDigit(std::string num) {
    std::string array[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (char c : num) {
        if (c >= '1' && c <= '9') 
            return c - '0';
        else {
            for (int i = 0;i < sizeof(array);i++) {
                if (array[i] == num.c_str())
                    return i + 1;
            }
        }
    }
}

int main()
{
    std::ifstream file("input.txt");
    std::string   line = "";
    std::string numArray[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int sum = 0;
    while (std::getline(file, line)) {
        std::map<int, std::string> mapValues;
        for (int i = 0; i < line.length(); i++) {
            for (std::string num : numArray) {
                if (line.substr(i, num.length()) == num) {
                    int index = line.find(num);
                    while (index != std::string::npos) {
                        mapValues[index] = num;
                        index = line.find(num, index + 1);
                    }
                }
            }
        }
        int firstDigit = extractDigit(mapValues.begin()->second);
        int secondDigit = extractDigit((--mapValues.end())->second);
        sum += firstDigit * 10 + secondDigit;
    }
    printf("sum %d \n", sum);
}

