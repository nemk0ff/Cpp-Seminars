#include <iostream>
#include <vector>
using namespace std;

// template <class T>
// bool foo(vector<T>& first, vector<T>& second)
// {
//     if(first.size() < second.size()) return false;
//     size_t i = 0, j = 0;
//     while(i < first.size() && j < second.size())
//     {
//         if(second.at(j) == first.at(i))
//         {
//             j++;
//         }
//         i++;
//     }
//     if(j != second.size()) return false;
//     return true;
// }
template <class T>
bool foo(const vector<T>& first, const vector<T>& second) {
    if (first.size() < second.size()) return false;

    auto it_first = first.begin();
    auto it_second = second.begin();

    while (it_first != first.end() && it_second != second.end()) {
        if (*it_second == *it_first) {
            ++it_second; // Перемещаем итератор второго вектора, если нашли совпадение
        }
        ++it_first; // Всегда перемещаем итератор первого вектора
    }

    return it_second == second.end(); // Если все элементы второго вектора найдены в первом
}


int main() {
    vector<int> int_first = {1,2,3,4,5,6,7,8,9};
    vector<int> int_second = {1,3,5,7,8};
    vector<int> int_third = {2,1,3,5,7,8};

    cout << foo(int_first, int_second) << endl;
    cout << foo(int_first, int_third) << endl;
    cout << foo(int_second, int_first) << endl;

    vector<string> string_first = {"aaa", "bbb", "ccc", "ddd", "eee", "fff"};
    vector<string> string_second = {"aaa", "ccc", "ddd", "eee"};
    vector<string> string_third = {"aaa", "ddd", "ccc"};

    cout << foo(string_first, string_second) << endl;
    cout << foo(string_first, string_third) << endl;
    cout << foo(string_third, string_first) << endl;

    return 0;
}
