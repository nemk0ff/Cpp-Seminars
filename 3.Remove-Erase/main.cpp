#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
void delete_number(){
    ifstream inputFile("../../input.txt");
    ofstream outputFile("../../output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error" << endl;
        return;
    }
    string line;

    std::vector<int> numbers;
    int singleNumber;

    if (getline(inputFile, line)) {
        size_t delimiterPos = line.find(';');

        if (delimiterPos != std::string::npos) {
            std::string numbersPart = line.substr(0, delimiterPos);
            std::string singleNumberPart = line.substr(delimiterPos + 1);

            std::istringstream issNumbers(numbersPart);

            int number;

            while (issNumbers >> number) {
                numbers.push_back(number);
            }

            std::istringstream(singleNumberPart) >> singleNumber;
        }
        else
        {
            cout <<" Error in format of string" << endl;
        }
    }

    inputFile.close();

    numbers.erase(std::remove(numbers.begin(), numbers.end(), singleNumber), numbers.end());

    for (const int num : numbers) {
        outputFile << num << " ";
    }

    outputFile.close();
}
int main() {
    delete_number();
    return 0;
}
