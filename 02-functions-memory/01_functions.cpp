/**
 * C++ Functions and Memory: Functions
 *
 * Understanding functions deeply is crucial for writing clean,
 * efficient code in LeetCode problems.
 *
 * Compile: g++ -std=c++17 -o 01_functions 01_functions.cpp
 * Run: ./01_functions
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================================
// FUNCTION DECLARATIONS (Prototypes)
// ============================================

// Declare functions before main, define after
int add(int a, int b);
void printMessage(const string& msg);
double average(const vector<int>& nums);

// ============================================
// BASIC FUNCTIONS
// ============================================

// Simple function
int multiply(int a, int b) {
    return a * b;
}

// Void function (no return value)
void greet(string name) {
    cout << "Hello, " << name << "!" << endl;
}

// Function with no parameters
int getRandomNumber() {
    return 42;  // Guaranteed to be random ;)
}

// ============================================
// PASS BY VALUE VS REFERENCE
// ============================================

// Pass by value - creates a copy (changes don't affect original)
void incrementByValue(int x) {
    x++;  // Only modifies the copy
    cout << "Inside function (by value): " << x << endl;
}

// Pass by reference - modifies the original
void incrementByReference(int& x) {
    x++;  // Modifies the actual variable
    cout << "Inside function (by reference): " << x << endl;
}

// Pass by const reference - read-only, efficient for large objects
void printVector(const vector<int>& vec) {
    // vec.push_back(10);  // ERROR: Cannot modify const reference
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

// Pass by pointer
void incrementByPointer(int* x) {
    (*x)++;  // Dereference and modify
}

// ============================================
// DEFAULT PARAMETERS
// ============================================

// Default parameters must be at the end
void printRepeat(const string& msg, int times = 1, const string& separator = " ") {
    for (int i = 0; i < times; i++) {
        cout << msg;
        if (i < times - 1) cout << separator;
    }
    cout << endl;
}

// ============================================
// FUNCTION OVERLOADING
// ============================================

// Same name, different parameters
int absolute(int x) {
    return (x < 0) ? -x : x;
}

double absolute(double x) {
    return (x < 0) ? -x : x;
}

int add(int a, int b, int c) {  // Overload with 3 params
    return a + b + c;
}

// ============================================
// INLINE FUNCTIONS
// ============================================

// Hint to compiler to replace call with code (optimization)
inline int square(int x) {
    return x * x;
}

// ============================================
// RECURSION
// ============================================

// Classic factorial
int factorial(int n) {
    if (n <= 1) return 1;  // Base case
    return n * factorial(n - 1);  // Recursive case
}

// Fibonacci with recursion (inefficient but illustrative)
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Tail recursion (can be optimized by compiler)
int factorialTail(int n, int acc = 1) {
    if (n <= 1) return acc;
    return factorialTail(n - 1, n * acc);
}

// ============================================
// LAMBDA FUNCTIONS (C++11)
// ============================================

void demonstrateLambdas() {
    cout << "--- Lambda Functions ---" << endl;

    // Basic lambda
    auto add = [](int a, int b) { return a + b; };
    cout << "Lambda add(3, 4): " << add(3, 4) << endl;

    // Lambda with capture
    int multiplier = 10;
    auto times = [multiplier](int x) { return x * multiplier; };
    cout << "Lambda times(5): " << times(5) << endl;

    // Capture by reference
    int counter = 0;
    auto increment = [&counter]() { counter++; };
    increment();
    increment();
    cout << "Counter after 2 increments: " << counter << endl;

    // Capture all by value [=] or by reference [&]
    int a = 1, b = 2;
    auto sum = [=]() { return a + b; };
    cout << "Sum with capture all: " << sum() << endl;

    // Lambda as parameter to algorithm
    vector<int> nums = {3, 1, 4, 1, 5, 9};
    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    cout << "Sorted descending: ";
    for (int n : nums) cout << n << " ";
    cout << endl;
}

// ============================================
// RETURNING MULTIPLE VALUES
// ============================================

// Method 1: Using pair/tuple
#include <tuple>

pair<int, int> divmod(int a, int b) {
    return {a / b, a % b};
}

tuple<int, int, int> getStats(const vector<int>& nums) {
    int min = nums[0], max = nums[0], sum = 0;
    for (int n : nums) {
        if (n < min) min = n;
        if (n > max) max = n;
        sum += n;
    }
    return {min, max, sum};
}

// Method 2: Using reference parameters
void minMax(const vector<int>& nums, int& minVal, int& maxVal) {
    minVal = maxVal = nums[0];
    for (int n : nums) {
        if (n < minVal) minVal = n;
        if (n > maxVal) maxVal = n;
    }
}

// Method 3: Using struct (good for complex returns)
struct Stats {
    int min;
    int max;
    double average;
};

Stats computeStats(const vector<int>& nums) {
    Stats s;
    s.min = s.max = nums[0];
    int sum = 0;
    for (int n : nums) {
        if (n < s.min) s.min = n;
        if (n > s.max) s.max = n;
        sum += n;
    }
    s.average = (double)sum / nums.size();
    return s;
}


// ============================================
// MAIN FUNCTION
// ============================================

int main() {
    cout << "=== Functions in C++ ===" << endl << endl;

    // Basic functions
    cout << "--- Basic Functions ---" << endl;
    cout << "multiply(6, 7): " << multiply(6, 7) << endl;
    greet("C++ Learner");
    cout << "Random number: " << getRandomNumber() << endl;

    // Pass by value vs reference
    cout << "\n--- Pass by Value vs Reference ---" << endl;
    int num = 10;
    cout << "Original: " << num << endl;

    incrementByValue(num);
    cout << "After pass by value: " << num << endl;  // Still 10

    incrementByReference(num);
    cout << "After pass by reference: " << num << endl;  // Now 11

    incrementByPointer(&num);
    cout << "After pass by pointer: " << num << endl;  // Now 12

    // Const reference for efficiency
    cout << "\n--- Const Reference ---" << endl;
    vector<int> bigVector = {1, 2, 3, 4, 5};
    cout << "Vector: ";
    printVector(bigVector);

    // Default parameters
    cout << "\n--- Default Parameters ---" << endl;
    printRepeat("Hi");              // Uses defaults
    printRepeat("Hi", 3);           // Custom times
    printRepeat("Hi", 3, "-");      // All custom

    // Function overloading
    cout << "\n--- Function Overloading ---" << endl;
    cout << "absolute(-5): " << absolute(-5) << endl;
    cout << "absolute(-3.14): " << absolute(-3.14) << endl;
    cout << "add(1, 2): " << add(1, 2) << endl;
    cout << "add(1, 2, 3): " << add(1, 2, 3) << endl;

    // Recursion
    cout << "\n--- Recursion ---" << endl;
    cout << "factorial(5): " << factorial(5) << endl;
    cout << "fibonacci(10): " << fibonacci(10) << endl;
    cout << "factorialTail(5): " << factorialTail(5) << endl;

    // Lambdas
    cout << endl;
    demonstrateLambdas();

    // Returning multiple values
    cout << "\n--- Multiple Return Values ---" << endl;

    auto [quotient, remainder] = divmod(17, 5);  // Structured binding (C++17)
    cout << "17 / 5 = " << quotient << " remainder " << remainder << endl;

    vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};

    auto [minV, maxV, sumV] = getStats(data);
    cout << "Stats: min=" << minV << ", max=" << maxV << ", sum=" << sumV << endl;

    int lo, hi;
    minMax(data, lo, hi);
    cout << "MinMax: " << lo << " to " << hi << endl;

    Stats stats = computeStats(data);
    cout << "Struct stats: min=" << stats.min << ", max=" << stats.max
         << ", avg=" << stats.average << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Write a recursive function to calculate power(base, exp)
     * Without using pow() from cmath
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Write a function that takes a vector by reference
     * and removes all even numbers in-place
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Write a lambda that checks if a number is prime
     * Then use it with std::count_if to count primes in a vector
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Write a recursive binary search function
     * int binarySearch(const vector<int>& arr, int target, int left, int right)
     */

    // YOUR CODE HERE

    return 0;
}

// ============================================
// FUNCTION DEFINITIONS (for prototypes above)
// ============================================

int add(int a, int b) {
    return a + b;
}

void printMessage(const string& msg) {
    cout << "Message: " << msg << endl;
}

double average(const vector<int>& nums) {
    if (nums.empty()) return 0.0;
    int sum = 0;
    for (int n : nums) sum += n;
    return (double)sum / nums.size();
}
