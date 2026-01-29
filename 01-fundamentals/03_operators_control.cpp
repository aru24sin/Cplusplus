/**
 * C++ Fundamentals: Operators and Control Flow
 *
 * Master these for efficient algorithm implementation.
 *
 * Compile: g++ -std=c++17 -o 03_control 03_operators_control.cpp
 * Run: ./03_control
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "=== Operators and Control Flow ===" << endl << endl;

    // ============================================
    // ARITHMETIC OPERATORS
    // ============================================

    cout << "--- Arithmetic Operators ---" << endl;

    int a = 17, b = 5;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << " (integer division)" << endl;
    cout << "a % b = " << (a % b) << " (modulo/remainder)" << endl;

    // Increment/Decrement
    int x = 5;
    cout << "\nx = " << x << endl;
    cout << "++x = " << ++x << " (pre-increment, x is now " << x << ")" << endl;
    cout << "x++ = " << x++ << " (post-increment, x is now " << x << ")" << endl;

    // Compound assignment
    int c = 10;
    c += 5;  // c = c + 5
    cout << "\nc += 5: " << c << endl;
    c *= 2;  // c = c * 2
    cout << "c *= 2: " << c << endl;

    // ============================================
    // COMPARISON OPERATORS
    // ============================================

    cout << "\n--- Comparison Operators ---" << endl;

    int p = 10, q = 20;
    cout << boolalpha;  // Print true/false instead of 1/0

    cout << "p = " << p << ", q = " << q << endl;
    cout << "p == q: " << (p == q) << endl;
    cout << "p != q: " << (p != q) << endl;
    cout << "p < q: " << (p < q) << endl;
    cout << "p <= q: " << (p <= q) << endl;
    cout << "p > q: " << (p > q) << endl;
    cout << "p >= q: " << (p >= q) << endl;

    // ============================================
    // LOGICAL OPERATORS
    // ============================================

    cout << "\n--- Logical Operators ---" << endl;

    bool t = true, f = false;

    cout << "true && false: " << (t && f) << " (AND)" << endl;
    cout << "true || false: " << (t || f) << " (OR)" << endl;
    cout << "!true: " << (!t) << " (NOT)" << endl;

    // Short-circuit evaluation
    cout << "\nShort-circuit: false && (expensive) won't evaluate expensive" << endl;

    // ============================================
    // BITWISE OPERATORS (Important for LeetCode!)
    // ============================================

    cout << "\n--- Bitwise Operators ---" << endl;

    int m = 5;   // Binary: 0101
    int n = 3;   // Binary: 0011

    cout << "m = " << m << " (binary: 0101)" << endl;
    cout << "n = " << n << " (binary: 0011)" << endl;

    cout << "m & n = " << (m & n) << " (AND: 0001)" << endl;
    cout << "m | n = " << (m | n) << " (OR: 0111)" << endl;
    cout << "m ^ n = " << (m ^ n) << " (XOR: 0110)" << endl;
    cout << "~m = " << (~m) << " (NOT)" << endl;
    cout << "m << 1 = " << (m << 1) << " (left shift, multiply by 2)" << endl;
    cout << "m >> 1 = " << (m >> 1) << " (right shift, divide by 2)" << endl;

    // Common bit manipulation tricks
    cout << "\nBit manipulation tricks:" << endl;
    int num = 6;
    cout << "Is " << num << " even? " << ((num & 1) == 0) << " (check last bit)" << endl;
    cout << "Is " << num << " power of 2? " << ((num & (num - 1)) == 0) << endl;

    // ============================================
    // IF/ELSE STATEMENTS
    // ============================================

    cout << "\n--- If/Else Statements ---" << endl;

    int score = 85;

    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 80) {
        cout << "Grade: B" << endl;
    } else if (score >= 70) {
        cout << "Grade: C" << endl;
    } else {
        cout << "Grade: F" << endl;
    }

    // Single-line if (use sparingly)
    if (score > 50) cout << "Passed!" << endl;

    // ============================================
    // TERNARY OPERATOR
    // ============================================

    cout << "\n--- Ternary Operator ---" << endl;

    int age = 20;
    string status = (age >= 18) ? "Adult" : "Minor";
    cout << "Age " << age << ": " << status << endl;

    // Nested ternary (avoid for readability)
    int val = 15;
    string category = (val < 10) ? "Small" : (val < 20) ? "Medium" : "Large";
    cout << "Value " << val << ": " << category << endl;

    // ============================================
    // SWITCH STATEMENT
    // ============================================

    cout << "\n--- Switch Statement ---" << endl;

    int day = 3;

    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
        case 7:  // Fall-through
            cout << "Weekend!" << endl;
            break;
        default:
            cout << "Invalid day" << endl;
    }

    // ============================================
    // FOR LOOPS
    // ============================================

    cout << "\n--- For Loops ---" << endl;

    // Traditional for loop
    cout << "Traditional: ";
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Reverse loop
    cout << "Reverse: ";
    for (int i = 4; i >= 0; i--) {
        cout << i << " ";
    }
    cout << endl;

    // Step by 2
    cout << "Step by 2: ";
    for (int i = 0; i < 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    // Nested loops
    cout << "Nested (2x3):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "  (" << i << "," << j << ")";
        }
        cout << endl;
    }

    // ============================================
    // WHILE LOOPS
    // ============================================

    cout << "\n--- While Loops ---" << endl;

    // While loop
    int count = 0;
    cout << "While: ";
    while (count < 5) {
        cout << count << " ";
        count++;
    }
    cout << endl;

    // Do-while (always runs at least once)
    int doCount = 0;
    cout << "Do-while: ";
    do {
        cout << doCount << " ";
        doCount++;
    } while (doCount < 5);
    cout << endl;

    // ============================================
    // BREAK AND CONTINUE
    // ============================================

    cout << "\n--- Break and Continue ---" << endl;

    // Break - exit loop early
    cout << "Break at 3: ";
    for (int i = 0; i < 10; i++) {
        if (i == 3) break;
        cout << i << " ";
    }
    cout << endl;

    // Continue - skip current iteration
    cout << "Skip evens: ";
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) continue;
        cout << i << " ";
    }
    cout << endl;

    // ============================================
    // COMMON PATTERNS FOR LEETCODE
    // ============================================

    cout << "\n--- LeetCode Patterns ---" << endl;

    // Two pointers
    cout << "Two pointers pattern:" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    int left = 0, right = 4;
    while (left < right) {
        cout << "  left=" << arr[left] << ", right=" << arr[right] << endl;
        left++;
        right--;
    }

    // Sliding window simulation
    cout << "\nSliding window concept (window size 3):" << endl;
    for (int i = 0; i <= 2; i++) {
        cout << "  Window starting at " << i << ": [";
        for (int j = i; j < i + 3 && j < 5; j++) {
            cout << arr[j];
            if (j < i + 2) cout << ", ";
        }
        cout << "]" << endl;
    }

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: FizzBuzz
     * Print numbers 1-20
     * - If divisible by 3: print "Fizz"
     * - If divisible by 5: print "Buzz"
     * - If divisible by both: print "FizzBuzz"
     * - Otherwise: print the number
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Count set bits
     * Given an integer, count how many bits are 1
     * Example: 13 (binary: 1101) has 3 set bits
     */

    int testNum = 13;
    // YOUR CODE HERE


    /**
     * Exercise 3: Print a triangle
     * Print a right triangle of * with height 5
     * *
     * **
     * ***
     * ****
     * *****
     */

    // YOUR CODE HERE

    return 0;
}
