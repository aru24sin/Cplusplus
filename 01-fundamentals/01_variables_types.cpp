/**
 * C++ Fundamentals: Variables and Data Types
 *
 * C++ is a statically typed language - you must declare types.
 * This is different from Python where types are inferred.
 *
 * Compile: g++ -std=c++17 -o 01_variables 01_variables_types.cpp
 * Run: ./01_variables
 */

#include <iostream>
#include <string>
#include <limits>   // For numeric limits

using namespace std;

int main() {
    cout << "=== C++ Variables and Data Types ===" << endl << endl;

    // ============================================
    // BASIC DATA TYPES
    // ============================================

    cout << "--- Integer Types ---" << endl;

    // Integer types (signed by default)
    int myInt = 42;                    // Usually 4 bytes, -2B to 2B
    short myShort = 100;               // Usually 2 bytes
    long myLong = 1000000L;            // Usually 4 or 8 bytes
    long long myLongLong = 9000000000LL; // At least 8 bytes

    cout << "int: " << myInt << " (size: " << sizeof(int) << " bytes)" << endl;
    cout << "short: " << myShort << " (size: " << sizeof(short) << " bytes)" << endl;
    cout << "long: " << myLong << " (size: " << sizeof(long) << " bytes)" << endl;
    cout << "long long: " << myLongLong << " (size: " << sizeof(long long) << " bytes)" << endl;

    // Unsigned integers (only positive values, double the positive range)
    unsigned int positiveOnly = 4294967295;  // Max value for 4-byte unsigned
    cout << "unsigned int: " << positiveOnly << endl;

    cout << "\n--- Floating Point Types ---" << endl;

    float myFloat = 3.14f;             // 4 bytes, ~7 decimal digits precision
    double myDouble = 3.14159265359;   // 8 bytes, ~15 decimal digits precision

    cout << "float: " << myFloat << " (size: " << sizeof(float) << " bytes)" << endl;
    cout << "double: " << myDouble << " (size: " << sizeof(double) << " bytes)" << endl;

    cout << "\n--- Character and Boolean ---" << endl;

    char myChar = 'A';                 // Single character, 1 byte
    bool myBool = true;                // true or false

    cout << "char: " << myChar << " (ASCII: " << (int)myChar << ")" << endl;
    cout << "bool: " << myBool << " (true=1, false=0)" << endl;
    cout << boolalpha;  // Print "true"/"false" instead of 1/0
    cout << "bool (boolalpha): " << myBool << endl;

    // ============================================
    // STRINGS
    // ============================================

    cout << "\n--- Strings ---" << endl;

    // C++ string (preferred)
    string myString = "Hello, C++!";
    cout << "string: " << myString << endl;
    cout << "length: " << myString.length() << endl;
    cout << "first char: " << myString[0] << endl;

    // String concatenation
    string firstName = "John";
    string lastName = "Doe";
    string fullName = firstName + " " + lastName;
    cout << "concatenation: " << fullName << endl;

    // C-style string (array of chars) - avoid in modern C++
    const char* cString = "C-style string";
    cout << "C-string: " << cString << endl;

    // ============================================
    // CONSTANTS
    // ============================================

    cout << "\n--- Constants ---" << endl;

    const int MAX_SIZE = 100;          // Cannot be changed
    constexpr int COMPILE_TIME = 50;   // Evaluated at compile time (C++11)

    cout << "const: " << MAX_SIZE << endl;
    cout << "constexpr: " << COMPILE_TIME << endl;

    // MAX_SIZE = 200;  // ERROR: Cannot modify const

    // ============================================
    // TYPE INFERENCE (auto)
    // ============================================

    cout << "\n--- Type Inference (auto) ---" << endl;

    auto inferredInt = 42;             // Compiler infers int
    auto inferredDouble = 3.14;        // Compiler infers double
    auto inferredString = string("Hello");  // Compiler infers string

    cout << "auto int: " << inferredInt << endl;
    cout << "auto double: " << inferredDouble << endl;
    cout << "auto string: " << inferredString << endl;

    // ============================================
    // TYPE CASTING
    // ============================================

    cout << "\n--- Type Casting ---" << endl;

    double pi = 3.14159;

    // C-style cast (avoid)
    int truncated1 = (int)pi;

    // C++ style casts (preferred)
    int truncated2 = static_cast<int>(pi);

    cout << "Original double: " << pi << endl;
    cout << "Cast to int: " << truncated2 << endl;

    // Integer division vs floating point
    cout << "5 / 2 = " << 5 / 2 << " (integer division)" << endl;
    cout << "5.0 / 2 = " << 5.0 / 2 << " (floating point)" << endl;

    // ============================================
    // NUMERIC LIMITS
    // ============================================

    cout << "\n--- Numeric Limits ---" << endl;

    cout << "int max: " << numeric_limits<int>::max() << endl;
    cout << "int min: " << numeric_limits<int>::min() << endl;
    cout << "double max: " << numeric_limits<double>::max() << endl;

    // Important for LeetCode: overflow
    int maxInt = numeric_limits<int>::max();
    cout << "max int + 1 = " << maxInt + 1 << " (OVERFLOW!)" << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Declare variables for a person's info
     * - name (string)
     * - age (int)
     * - height (double, in meters)
     * - isStudent (bool)
     * Print them in a formatted way
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Temperature Converter
     * Convert 98.6 Fahrenheit to Celsius
     * Formula: C = (F - 32) * 5/9
     * Watch out for integer division!
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Swap two integers without using a temp variable
     * Hint: Use arithmetic or XOR
     */

    // YOUR CODE HERE

    return 0;
}
