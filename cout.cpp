#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

class Calculator {
    public:
        int multiply(int a, int b) {
            return a * b;
        }
};

int main() {
    int x = 5;
    int y = 3;

    int sum = add(x, y);
    cout << "Sum: " << sum << '\n';

    Calculator calc;
    int product = calc.multiply(x, y);
    cout << "Product: " << product << '\n';

    return 0;
}