#include <iostream>
using namespace std;

int main() {
    //basic operations
    float x = 2;
    float y = 4;
    int n = 14;
    int m = 2;
    float sum = x + y;
    float difference = x - y;
    float quotient = x / y;
    float product = x * y;
    int modulus = n % m;

    //increment (same with decrement except difference instead of sum)
    int z = ++x; //x=3, z=3
    int z = x++; //x=3, z=2
}