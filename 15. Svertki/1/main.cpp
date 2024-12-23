#include <iostream>
#include <vector>
#include <string>

template <typename Container, typename... Args>
void addElements(Container& container, Args&&... args) {
    (container.push_back((args)), ...);
}

int main() {
    std::vector<int> numbers;
    addElements(numbers, 1, 2, 3, 4, 5);
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> strings;
    addElements(strings, "Hello", "World", "!");
    for (const std::string& str : strings) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
