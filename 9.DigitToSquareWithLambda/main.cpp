#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void foo(vector<int>& numbers, const function<int(int)>& function) {
    transform(numbers.begin(), numbers.end(), numbers.begin(), function);
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    foo(numbers, [](int x) { return x * x; });

    cout << "Result: ";

    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
