#include <bits/stdc++.h>
using namespace std;

string sortString(const string& str) {
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
}

map<string, string> loadDictionary(const string& filename) {
    map<string, string> dictionary;
    ifstream file(filename);

    string word;

    while (getline(file,word)) {
        if (dictionary.find(sortString(word)) == dictionary.end()) {
            dictionary[sortString(word)] = word;
        }
    }
    return std::move(dictionary);
}

vector<string> decryptAnagrams(const map<string, string>& dictionary, const string& inputString) {
    vector<string> words;

    stringstream ss(inputString);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    vector<string> result;
    for(auto it: words) {
        string sortedWord = sortString(it);
        for (const auto& dictWord : dictionary) {
            if(dictWord.first == sortedWord) {
                result.push_back(dictWord.second);
                break;
            }
        }
    }
    return result;
}

int main() {
    const string filename = "input.txt";
    const map<string, string> dictionary = loadDictionary(filename);

    string inputString = "my frinde";
    vector<string> decryptedWords = decryptAnagrams(dictionary, inputString);

    for (const auto& word : decryptedWords) {
        cout << word << "v ";
    }
    cout << endl;

    return 0;
}
