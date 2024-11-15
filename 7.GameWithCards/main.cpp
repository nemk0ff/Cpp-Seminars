#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Error:" << argv[0] << "I need <input_file> <output_file>" << endl;
        return 1;
    }
    string NameInputFile = "../../" + (string)argv[1];
    string NameOutputFile = "../../" + (string)argv[2];

    ifstream inputFile(NameInputFile);
    if (!inputFile) {
        cout << "I can't open input file." << endl;
        return 1;
    }

    ofstream outputFile(NameOutputFile);
    if (!outputFile) {
        cout << "I can't open output file." << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        inputFile >> cards[i];
    }

    sort(cards.begin(), cards.end(), greater<int>());

    int SumOfBiggestNumbers = accumulate(cards.begin(), cards.begin() + cards.size() / 2, 0);

    int SumOfSmallestNumbers = accumulate(cards.begin() + cards.size() / 2, cards.begin() + cards.size(), 0);

    outputFile << SumOfBiggestNumbers - SumOfSmallestNumbers << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
