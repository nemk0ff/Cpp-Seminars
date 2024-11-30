#include <bits/stdc++.h>
using namespace std;
class AnagrammsWorker{
private:
    map<string, vector<string> > OurDictionary;
    vector<vector<string> > descryptedSentences;
public:
    AnagrammsWorker() { }

    void setOurDictionary(const string& filename) {
        map<string, vector<string> > dictionary;
        ifstream file(filename);

        string word;

        while (getline(file,word)) {
            if (dictionary.find(sortString(word)) == dictionary.end()) {
                dictionary[sortString(word)].push_back(word);
            }
            else{
                dictionary.find(sortString(word))->second.push_back(word);
            }
        }
        OurDictionary = dictionary;
    }

    string sortString(const string& str) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        return sortedStr;
    }

    void decryptAnagrams(const string& inputString) {
        vector<string> words; // Слова во входной строке

        stringstream ss(inputString);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        vector<vector<string> > result; // расшифровка слов

        for(auto it: words) {
            string sortedWord = sortString(it);

            vector<string> anagramms; // Собираем сюда все анаграммы слова

            for (const auto& dictWord : OurDictionary) {
                // Если нашли анаграмму, то добавляем в вектор
                if(dictWord.first == sortedWord) {
                    anagramms = dictWord.second;
                    break;
                }
            }
            result.push_back(anagramms);
        }

        descryptedSentences = result;
    }

    void printDescryptedSentences(){
        cout << "   descryptedSentences: " << endl;
        int i = 1;
        for(auto it: descryptedSentences) {
            cout << endl;
            cout << "Word " << i << endl;
            for (auto it2: it) {
                cout << it2 << ", ";
            }
            i++;
        }
    }

    void printSentence(vector<string>){

    }

    void printDictionary(){
        cout << "   Dictionary: " << endl;
        for(auto it: OurDictionary){
            for(auto it2: it.second){
                cout << it2 << ", ";
            }
        }
        cout << endl;
    }

    void printSortedDictionary(){
        cout << "   SortedDictionary: " << endl;
        for(auto it: OurDictionary){
            cout << it.first << ", ";
        }
        cout << endl;
    }
};


int main() {
    AnagrammsWorker worker;
    const string filename = "input.txt";
    worker.setOurDictionary(filename);

    string inputString = "tlae nihgt";
    worker.decryptAnagrams(inputString);

    worker.printDictionary();

    worker.printSortedDictionary();

    worker.printDescryptedSentences();


    return 0;
}
