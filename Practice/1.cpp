#include <iostream>
using namespace std;

int subtract(int x, int y) {
    int difference = x - y;
    return difference;
}

int add(int x, int y) {
    int sum = x + y;
    return sum;
}

int main() {
    int x;
    cout << "Input X: ";
    cin >> x;
    
    int y;
    cout << "Input Y: ";
    cin >> y;

    cout << '\n' << "Sum: " << add(x, y);
    cout << '\n' << "Difference: " << subtract(x, y);
    return 0;
}