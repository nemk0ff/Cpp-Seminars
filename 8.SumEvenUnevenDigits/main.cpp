#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class SumEvenOdd {
public:
    int sumEven = 0;
    int sumUnEven = 0;
    void operator()(int number) {
        if (number % 2 == 0) {
            sumEven += number;
        } else {
            sumUnEven += number;
        }
        cout << number << endl;
    }
};

int main() {
    // sumEven = 0;
    // sumUnEven = 0;
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SumEvenOdd sumEvenOdd;

    sumEvenOdd = std::for_each(numbers.begin(), numbers.end(), sumEvenOdd);

    std::cout << "Sum of even numbers: " << sumEvenOdd.sumEven << std::endl;
    std::cout << "Sum of uneven numbers: " << sumEvenOdd.sumUnEven << std::endl;

    return 0;
}
