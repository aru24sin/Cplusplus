/**
 * C++ Fundamentals: Arrays and Strings
 *
 * Foundation for most data structure problems.
 *
 * Compile: g++ -std=c++17 -o 04_arrays 04_arrays_strings.cpp
 * Run: ./04_arrays
 */

#include <iostream>
#include <string>
#include <cstring>    // For C-style string functions
#include <algorithm>  // For sort, reverse, etc.
#include <vector>     // Preview of vectors

using namespace std;

int main() {
    cout << "=== Arrays and Strings ===" << endl << endl;

    // ============================================
    // C-STYLE ARRAYS (Fixed size)
    // ============================================

    cout << "--- C-Style Arrays ---" << endl;

    // Declaration and initialization
    int numbers[5] = {10, 20, 30, 40, 50};

    // Access elements (0-indexed)
    cout << "First element: " << numbers[0] << endl;
    cout << "Last element: " << numbers[4] << endl;

    // Modify elements
    numbers[2] = 35;
    cout << "Modified third element: " << numbers[2] << endl;

    // Print all elements
    cout << "All elements: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Array size (only works for arrays, not pointers)
    cout << "Array size: " << sizeof(numbers) / sizeof(numbers[0]) << endl;

    // Partial initialization (rest are 0)
    int partial[5] = {1, 2};  // {1, 2, 0, 0, 0}
    cout << "Partial init: ";
    for (int i = 0; i < 5; i++) cout << partial[i] << " ";
    cout << endl;

    // Initialize all to 0
    int zeros[5] = {0};
    // or in C++: int zeros[5] = {};

    // ============================================
    // 2D ARRAYS
    // ============================================

    cout << "\n--- 2D Arrays ---" << endl;

    // Declaration
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Access elements
    cout << "Element [1][2]: " << matrix[1][2] << endl;  // 7

    // Print 2D array
    cout << "Full matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // ============================================
    // C++ STRINGS
    // ============================================

    cout << "\n--- C++ Strings ---" << endl;

    string str = "Hello, World!";

    // Basic properties
    cout << "String: " << str << endl;
    cout << "Length: " << str.length() << endl;  // or str.size()
    cout << "Empty? " << str.empty() << endl;

    // Access characters
    cout << "First char: " << str[0] << endl;
    cout << "Last char: " << str[str.length() - 1] << endl;
    cout << "At index 7: " << str.at(7) << endl;  // Bounds checked

    // Modify characters
    str[0] = 'h';
    cout << "Modified: " << str << endl;

    // ============================================
    // STRING OPERATIONS
    // ============================================

    cout << "\n--- String Operations ---" << endl;

    string s1 = "Hello";
    string s2 = "World";

    // Concatenation
    string s3 = s1 + " " + s2;
    cout << "Concatenated: " << s3 << endl;

    // Append
    s1 += "!";
    cout << "Appended: " << s1 << endl;

    // Compare
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "s1 < s2: " << (s1 < s2) << " (lexicographic)" << endl;

    // Substring
    string sub = s3.substr(0, 5);  // Start at 0, length 5
    cout << "Substring (0, 5): " << sub << endl;

    // Find
    size_t pos = s3.find("World");
    if (pos != string::npos) {
        cout << "Found 'World' at position: " << pos << endl;
    }

    // Replace
    string s4 = "Hello World";
    s4.replace(6, 5, "C++");  // Start at 6, replace 5 chars
    cout << "Replaced: " << s4 << endl;

    // Insert
    s4.insert(5, " Beautiful");
    cout << "Inserted: " << s4 << endl;

    // Erase
    s4.erase(5, 10);  // Start at 5, erase 10 chars
    cout << "Erased: " << s4 << endl;

    // ============================================
    // STRING ITERATION
    // ============================================

    cout << "\n--- String Iteration ---" << endl;

    string word = "CODING";

    // Index-based
    cout << "Index-based: ";
    for (int i = 0; i < word.length(); i++) {
        cout << word[i] << " ";
    }
    cout << endl;

    // Range-based for (C++11)
    cout << "Range-based: ";
    for (char c : word) {
        cout << c << " ";
    }
    cout << endl;

    // With reference (for modification)
    cout << "Lowercase: ";
    for (char& c : word) {
        c = tolower(c);
    }
    cout << word << endl;

    // ============================================
    // STRING UTILITY FUNCTIONS
    // ============================================

    cout << "\n--- String Utilities ---" << endl;

    string test = "  Hello World  ";

    // Convert to lowercase (in-place)
    string lower = test;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "Lowercase: '" << lower << "'" << endl;

    // Convert to uppercase
    string upper = test;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    cout << "Uppercase: '" << upper << "'" << endl;

    // Reverse
    string rev = "Hello";
    reverse(rev.begin(), rev.end());
    cout << "Reversed: " << rev << endl;

    // Number to string
    int num = 42;
    string numStr = to_string(num);
    cout << "Int to string: " << numStr << endl;

    // String to number
    string strNum = "123";
    int parsed = stoi(strNum);      // string to int
    double parsedD = stod("3.14");  // string to double
    cout << "String to int: " << parsed << endl;
    cout << "String to double: " << parsedD << endl;

    // ============================================
    // CHARACTER UTILITIES
    // ============================================

    cout << "\n--- Character Utilities ---" << endl;

    char ch = 'A';
    cout << "isalpha('A'): " << isalpha(ch) << endl;
    cout << "isdigit('A'): " << isdigit(ch) << endl;
    cout << "isalnum('A'): " << isalnum(ch) << endl;
    cout << "isupper('A'): " << isupper(ch) << endl;
    cout << "islower('A'): " << islower(ch) << endl;
    cout << "isspace(' '): " << isspace(' ') << endl;
    cout << "tolower('A'): " << (char)tolower(ch) << endl;
    cout << "toupper('a'): " << (char)toupper('a') << endl;

    // ASCII values
    cout << "\nASCII values:" << endl;
    cout << "'A' = " << (int)'A' << endl;
    cout << "'a' = " << (int)'a' << endl;
    cout << "'0' = " << (int)'0' << endl;

    // Character arithmetic (common in LeetCode)
    char digit = '7';
    int digitValue = digit - '0';  // Convert char digit to int
    cout << "Char '7' to int: " << digitValue << endl;

    char letter = 'e';
    int letterIndex = letter - 'a';  // 0-indexed position in alphabet
    cout << "Index of 'e' in alphabet: " << letterIndex << endl;

    // ============================================
    // COMMON ARRAY/STRING ALGORITHMS
    // ============================================

    cout << "\n--- Common Algorithms ---" << endl;

    int arr[] = {5, 2, 8, 1, 9, 3};
    int n = 6;

    // Find min and max
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    cout << "Min: " << minVal << ", Max: " << maxVal << endl;

    // Sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;

    // Reverse array in-place
    int arrCopy[] = {1, 2, 3, 4, 5};
    int left = 0, right = 4;
    while (left < right) {
        swap(arrCopy[left], arrCopy[right]);
        left++;
        right--;
    }
    cout << "Reversed array: ";
    for (int i = 0; i < 5; i++) cout << arrCopy[i] << " ";
    cout << endl;

    // ============================================
    // PREVIEW: VECTORS (Better than arrays!)
    // ============================================

    cout << "\n--- Preview: Vectors ---" << endl;

    // We'll cover vectors in detail later, but here's a taste
    vector<int> vec = {1, 2, 3, 4, 5};

    vec.push_back(6);  // Add element
    cout << "Vector: ";
    for (int v : vec) cout << v << " ";
    cout << endl;
    cout << "Size: " << vec.size() << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Reverse a string without using reverse()
     * Input: "algorithm"
     * Output: "mhtirogla"
     */

    string toReverse = "algorithm";
    // YOUR CODE HERE


    /**
     * Exercise 2: Check if a string is a palindrome
     * Input: "racecar"
     * Output: true
     * Ignore case and non-alphanumeric characters
     */

    string palindromeTest = "A man, a plan, a canal: Panama";
    // YOUR CODE HERE


    /**
     * Exercise 3: Find the most frequent character in a string
     * Input: "programming"
     * Output: 'g' (appears 2 times)
     * Hint: Use an array of size 26 to count letters
     */

    string freqTest = "programming";
    // YOUR CODE HERE


    /**
     * Exercise 4: Rotate an array to the right by k positions
     * Input: [1, 2, 3, 4, 5], k = 2
     * Output: [4, 5, 1, 2, 3]
     * Hint: Multiple reverses or use modulo
     */

    // YOUR CODE HERE

    return 0;
}
