#include <iostream>
#include <variant>
#include <cmath>

using Result = std::variant<std::monostate, double, std::pair<double, double>>;

Result solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            return std::monostate();
        }
        return -c / b;
    }

    double Dis = b * b - 4 * a * c;

    if (Dis > 0) {
        double root1 = (-b + std::sqrt(Dis)) / (2 * a);
        double root2 = (-b - std::sqrt(Dis)) / (2 * a);
        return std::make_pair(root1, root2);
    }
    else if (Dis == 0) {
        double root = -b / (2 * a);
        return root;
    }

    return std::monostate();
}

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    std::variant<std::monostate, double, std::pair<double, double> > result = solveQuadratic(a, b, c);

    if (std::holds_alternative<std::monostate>(result)) {
        std::cout << "D < 0" << std::endl;
    } else if (std::holds_alternative<double>(result)) {
        std::cout << "D = 0: " << std::get<double>(result) << std::endl;
    } else if (std::holds_alternative<std::monostate>(result)) {
        std::cout << "D > 0: " << std::get<std::pair<double, double>>(result).first << " and " << std::get<std::pair<double, double>>(result).second << std::endl;
    }
    return 0;
}
