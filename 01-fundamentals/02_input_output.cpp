/**
 * C++ Fundamentals: Input/Output
 *
 * Understanding I/O is crucial for LeetCode and competitive programming.
 *
 * Compile: g++ -std=c++17 -o 02_io 02_input_output.cpp
 * Run: ./02_io
 */

#include <iostream>
#include <string>
#include <sstream>   // For string streams
#include <iomanip>   // For output formatting

using namespace std;

int main() {
    cout << "=== C++ Input/Output ===" << endl << endl;

    // ============================================
    // BASIC OUTPUT (cout)
    // ============================================

    cout << "--- Basic Output ---" << endl;

    // cout - standard output stream
    cout << "Hello, World!" << endl;

    // Multiple items
    int x = 10, y = 20;
    cout << "x = " << x << ", y = " << y << endl;

    // endl vs '\n'
    // endl flushes the buffer, '\n' is faster
    cout << "Line 1\n";
    cout << "Line 2" << endl;

    // ============================================
    // OUTPUT FORMATTING
    // ============================================

    cout << "\n--- Output Formatting ---" << endl;

    double pi = 3.14159265359;

    // Set precision
    cout << "Default: " << pi << endl;
    cout << fixed << setprecision(2) << "Fixed 2: " << pi << endl;
    cout << setprecision(6) << "Fixed 6: " << pi << endl;
    cout.unsetf(ios::fixed);  // Reset to default

    // Width and fill
    cout << "Width 10: |" << setw(10) << 42 << "|" << endl;
    cout << "Fill with 0: |" << setfill('0') << setw(5) << 42 << "|" << endl;
    cout << setfill(' ');  // Reset fill

    // Left/right alignment
    cout << left << setw(10) << "Left" << "|" << endl;
    cout << right << setw(10) << "Right" << "|" << endl;

    // Hexadecimal, octal, binary
    int num = 255;
    cout << "Decimal: " << dec << num << endl;
    cout << "Hex: " << hex << num << endl;
    cout << "Octal: " << oct << num << endl;
    cout << dec;  // Reset to decimal

    // ============================================
    // BASIC INPUT (cin)
    // ============================================

    cout << "\n--- Basic Input ---" << endl;

    // Note: For automated testing, we'll simulate input
    // In real scenarios, uncomment the cin lines

    /*
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "You are " << age << " years old." << endl;

    double height;
    cout << "Enter your height: ";
    cin >> height;
    cout << "Your height is " << height << endl;
    */

    // Reading strings
    /*
    string name;
    cout << "Enter your first name: ";
    cin >> name;  // Reads until whitespace
    cout << "Hello, " << name << "!" << endl;
    */

    // ============================================
    // READING FULL LINES
    // ============================================

    cout << "\n--- Reading Full Lines ---" << endl;

    // getline reads entire line including spaces
    /*
    string fullName;
    cout << "Enter your full name: ";
    cin.ignore();  // Clear the newline from previous input
    getline(cin, fullName);
    cout << "Full name: " << fullName << endl;
    */

    // Simulating getline behavior
    string line = "John Doe Smith";
    cout << "Simulated line: " << line << endl;

    // ============================================
    // STRING STREAMS (Important for LeetCode!)
    // ============================================

    cout << "\n--- String Streams ---" << endl;

    // istringstream - read from string
    string data = "42 3.14 hello";
    istringstream iss(data);

    int intVal;
    double doubleVal;
    string stringVal;

    iss >> intVal >> doubleVal >> stringVal;

    cout << "Parsed from string:" << endl;
    cout << "  int: " << intVal << endl;
    cout << "  double: " << doubleVal << endl;
    cout << "  string: " << stringVal << endl;

    // ostringstream - write to string
    ostringstream oss;
    oss << "The answer is " << 42 << " and pi is " << 3.14;
    string result = oss.str();
    cout << "Built string: " << result << endl;

    // Parsing space-separated numbers (common in LeetCode)
    string numbers = "1 2 3 4 5";
    istringstream numStream(numbers);
    int n;
    cout << "Parsed numbers: ";
    while (numStream >> n) {
        cout << n << " ";
    }
    cout << endl;

    // ============================================
    // FAST I/O (For Competitive Programming)
    // ============================================

    cout << "\n--- Fast I/O ---" << endl;

    // Add these at the start of main() for faster I/O
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    cout << "For competitive programming, add at start of main():" << endl;
    cout << "  ios_base::sync_with_stdio(false);" << endl;
    cout << "  cin.tie(NULL);" << endl;
    cout << "This disables sync with C stdio and unties cin from cout." << endl;

    // Use '\n' instead of endl for speed
    cout << "Also use '\\n' instead of endl for speed\n";

    // ============================================
    // READING UNTIL EOF (Common Pattern)
    // ============================================

    cout << "\n--- Reading Until EOF ---" << endl;

    // Pattern for reading unknown number of inputs
    /*
    int value;
    while (cin >> value) {
        // Process value
        cout << "Got: " << value << endl;
    }
    */

    // Simulating with stringstream
    istringstream multiInput("10 20 30 40");
    int value;
    cout << "Reading until stream ends: ";
    while (multiInput >> value) {
        cout << value << " ";
    }
    cout << endl;

    // ============================================
    // READING SPECIFIC NUMBER OF INPUTS
    // ============================================

    cout << "\n--- Reading N Inputs ---" << endl;

    // Common LeetCode pattern: first line is count
    /*
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // Process x
    }
    */

    // Simulation
    istringstream leetInput("5 10 20 30 40 50");
    int count;
    leetInput >> count;
    cout << "Reading " << count << " numbers: ";
    for (int i = 0; i < count; i++) {
        int val;
        leetInput >> val;
        cout << val << " ";
    }
    cout << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Parse a CSV line
     * Input string: "John,25,Engineer"
     * Parse into name, age, and job variables
     * Hint: Use getline with ',' as delimiter
     */

    string csvLine = "John,25,Engineer";
    // YOUR CODE HERE


    /**
     * Exercise 2: Format a table
     * Print a multiplication table (1-5) with aligned columns
     * Each number should be right-aligned in a width of 4
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Parse array input
     * Input: "[1,2,3,4,5]"
     * Extract the numbers into a vector
     * (We'll cover vectors soon, for now just print them)
     */

    string arrayInput = "[1,2,3,4,5]";
    // YOUR CODE HERE

    return 0;
}
