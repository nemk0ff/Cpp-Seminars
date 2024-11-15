#include <iostream>
#include <string>
#include <optional>
#include <cstdlib>

std::optional<double> parseArgument(const std::string& arg) {
    char* endptr;
    double value = std::strtod(arg.c_str(), &endptr);

    if (endptr != arg.c_str() && *endptr == '\0') {
        return value;
    }

    return std::nullopt;
}

int main(int argc, char* argv[]) {
    double sum = 0.0;
    bool hasNumbers = false;

    for (int i = 1; i < argc; ++i) {
        std::optional<double> parsedValue = parseArgument(argv[i]);
        if (parsedValue) {
            sum += *parsedValue;
            hasNumbers = true;
        } else {
            std::cout << "This argument is not digit: " << argv[i] << std::endl;
        }
    }

    if (hasNumbers) {
        std::cout << "Sum of digits: " << sum << std::endl;
    } else {
        std::cout << "There are not digits(" << std::endl;
    }

    return 0;
}
