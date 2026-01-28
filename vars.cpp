#include <iostream>
using namespace std;

int main() {
    int x = 2;
    float y = 3.2;
    //A double will use 8 bytes or 64 bits of memory while a float uses only 4 bytes or 32 bits.
    //This means that a float is less precise since it can store fewer digits after the decimal place.
    double z = 4.555;
    string f = "Hello World";
    char o = 'o';
    bool isEven = true;

    cout << x << '\n';
    cout << y << '\n';
    cout << z << '\n';
    cout << f << '\n';
    cout << o << '\n';
    cout << isEven << '\n';
}