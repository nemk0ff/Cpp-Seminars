#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename Container, typename T, typename... Args>
bool containsAny(const Container& container, const T& value, const Args&... args) {
    if (std::find(container.begin(), container.end(), value) != container.end()) {
        return true; // Найден хотя бы один элемент
    }
    return (containsAny(container, args) || ...);
}

template <typename Container, typename T>
bool containsAny(const Container& container, const T& value) {
    return std::find(container.begin(), container.end(), value) != container.end();
}


template <typename Container, typename T, typename... Args>
bool containsAll(const Container& container, const T& value, const Args&... args) {
    if (std::find(container.begin(), container.end(), value) == container.end()) {
        return false; // Не найден хотя бы один элемент
    }
    return (containsAll(container, args) && ...);
}

template <typename Container, typename T>
bool containsAll(const Container& container, const T& value) {
    return std::find(container.begin(), container.end(), value) != container.end();
}


template <typename Container, typename... Args>
bool containsNone(const Container& container, const Args&... args) {
    return !(containsAny(container, args) || ...);
}


int main() {
    vector<int> numbers = {12, 2024, 1, 31, 2006, 9};

    cout << containsAny(numbers, 1, 2024) << endl;
    cout << containsAny(numbers, 5, 0) << endl;
    cout << containsAll(numbers, 1, 12, 31) << endl;
    cout << containsAll(numbers, 1, 2, 6) << endl;
    cout << containsNone(numbers, 123, 7) << endl;
    cout << containsNone(numbers, 1, 2) << endl;

    return 0;
}
