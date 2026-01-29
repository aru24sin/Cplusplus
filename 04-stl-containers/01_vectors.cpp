/**
 * C++ STL: Vectors
 *
 * std::vector is THE most important container for LeetCode.
 * Master this thoroughly!
 *
 * Compile: g++ -std=c++17 -o 01_vectors 01_vectors.cpp
 * Run: ./01_vectors
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // For accumulate, iota

using namespace std;

int main() {
    cout << "=== std::vector ===" << endl << endl;

    // ============================================
    // VECTOR CREATION
    // ============================================

    cout << "--- Vector Creation ---" << endl;

    // Empty vector
    vector<int> v1;

    // Vector with initial values (C++11)
    vector<int> v2 = {1, 2, 3, 4, 5};

    // Vector with size (all elements initialized to 0)
    vector<int> v3(5);  // {0, 0, 0, 0, 0}

    // Vector with size and default value
    vector<int> v4(5, 10);  // {10, 10, 10, 10, 10}

    // Copy constructor
    vector<int> v5(v2);  // Copy of v2

    // From array
    int arr[] = {1, 2, 3};
    vector<int> v6(arr, arr + 3);

    // Print helper
    auto print = [](const vector<int>& v, const string& name) {
        cout << name << ": ";
        for (int x : v) cout << x << " ";
        cout << "(size=" << v.size() << ")" << endl;
    };

    print(v2, "v2");
    print(v3, "v3");
    print(v4, "v4");

    // ============================================
    // ACCESSING ELEMENTS
    // ============================================

    cout << "\n--- Accessing Elements ---" << endl;

    vector<int> nums = {10, 20, 30, 40, 50};

    // [] operator (no bounds checking)
    cout << "nums[0]: " << nums[0] << endl;
    cout << "nums[4]: " << nums[4] << endl;

    // at() method (bounds checked, throws exception)
    cout << "nums.at(2): " << nums.at(2) << endl;

    // Front and back
    cout << "nums.front(): " << nums.front() << endl;
    cout << "nums.back(): " << nums.back() << endl;

    // Data pointer (for C compatibility)
    int* ptr = nums.data();
    cout << "ptr[0]: " << ptr[0] << endl;

    // ============================================
    // MODIFYING VECTORS
    // ============================================

    cout << "\n--- Modifying Vectors ---" << endl;

    vector<int> vec = {1, 2, 3};
    print(vec, "Initial");

    // Add to end
    vec.push_back(4);
    print(vec, "After push_back(4)");

    // Remove from end
    vec.pop_back();
    print(vec, "After pop_back()");

    // Insert at position
    vec.insert(vec.begin() + 1, 10);  // Insert 10 at index 1
    print(vec, "After insert at [1]");

    // Insert multiple
    vec.insert(vec.end(), {7, 8, 9});
    print(vec, "After insert {7,8,9}");

    // Erase at position
    vec.erase(vec.begin() + 1);  // Remove element at index 1
    print(vec, "After erase [1]");

    // Erase range
    vec.erase(vec.begin(), vec.begin() + 2);  // Remove first 2
    print(vec, "After erase range");

    // Clear all
    vec.clear();
    print(vec, "After clear");

    // Resize
    vec.resize(5, 42);  // Size 5, filled with 42
    print(vec, "After resize(5, 42)");

    // Assign new values
    vec.assign(3, 100);  // 3 elements of 100
    print(vec, "After assign(3, 100)");

    // ============================================
    // VECTOR SIZE AND CAPACITY
    // ============================================

    cout << "\n--- Size and Capacity ---" << endl;

    vector<int> sizeVec;

    cout << "Empty: size=" << sizeVec.size()
         << ", capacity=" << sizeVec.capacity()
         << ", empty=" << sizeVec.empty() << endl;

    for (int i = 0; i < 10; i++) {
        sizeVec.push_back(i);
        if (i % 3 == 0) {
            cout << "After adding " << i+1 << " elements: "
                 << "size=" << sizeVec.size()
                 << ", capacity=" << sizeVec.capacity() << endl;
        }
    }

    // Reserve capacity (optimization)
    vector<int> reserved;
    reserved.reserve(100);  // Pre-allocate space
    cout << "\nAfter reserve(100): capacity=" << reserved.capacity() << endl;

    // Shrink to fit
    sizeVec.shrink_to_fit();
    cout << "After shrink_to_fit: capacity=" << sizeVec.capacity() << endl;

    // ============================================
    // ITERATING VECTORS
    // ============================================

    cout << "\n--- Iterating Vectors ---" << endl;

    vector<int> data = {1, 2, 3, 4, 5};

    // Index-based
    cout << "Index-based: ";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Range-based for (preferred)
    cout << "Range-based: ";
    for (int x : data) {
        cout << x << " ";
    }
    cout << endl;

    // Range-based with reference (for modification)
    cout << "Doubled: ";
    for (int& x : data) {
        x *= 2;
    }
    for (int x : data) cout << x << " ";
    cout << endl;

    // Iterator-based
    cout << "Iterator: ";
    for (auto it = data.begin(); it != data.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration
    cout << "Reverse: ";
    for (auto it = data.rbegin(); it != data.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // ============================================
    // COMMON ALGORITHMS WITH VECTORS
    // ============================================

    cout << "\n--- Common Algorithms ---" << endl;

    vector<int> algo = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    print(algo, "Original");

    // Sort
    sort(algo.begin(), algo.end());
    print(algo, "Sorted");

    // Sort descending
    sort(algo.begin(), algo.end(), greater<int>());
    print(algo, "Descending");

    // Custom sort
    sort(algo.begin(), algo.end(), [](int a, int b) {
        return a % 3 < b % 3;  // Sort by remainder when divided by 3
    });
    print(algo, "Custom sort");

    // Reverse
    reverse(algo.begin(), algo.end());
    print(algo, "Reversed");

    // Find
    auto it = find(algo.begin(), algo.end(), 5);
    if (it != algo.end()) {
        cout << "Found 5 at index: " << (it - algo.begin()) << endl;
    }

    // Count
    algo = {1, 2, 2, 3, 2, 4, 2};
    cout << "Count of 2: " << count(algo.begin(), algo.end(), 2) << endl;

    // Sum
    int sum = accumulate(algo.begin(), algo.end(), 0);
    cout << "Sum: " << sum << endl;

    // Min/Max
    algo = {5, 2, 8, 1, 9};
    cout << "Min: " << *min_element(algo.begin(), algo.end()) << endl;
    cout << "Max: " << *max_element(algo.begin(), algo.end()) << endl;

    // Fill
    fill(algo.begin(), algo.end(), 0);
    print(algo, "Filled with 0");

    // Iota (fill with incrementing values)
    iota(algo.begin(), algo.end(), 1);  // 1, 2, 3, 4, 5
    print(algo, "Iota from 1");

    // ============================================
    // 2D VECTORS
    // ============================================

    cout << "\n--- 2D Vectors ---" << endl;

    // Create 3x4 matrix filled with 0
    int rows = 3, cols = 4;
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    // Fill with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }

    // Print matrix
    cout << "Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    // Matrix dimensions
    cout << "Rows: " << matrix.size() << endl;
    cout << "Cols: " << matrix[0].size() << endl;

    // Add a row
    matrix.push_back({12, 13, 14, 15});
    cout << "After adding row: " << matrix.size() << " rows" << endl;

    // ============================================
    // LEETCODE PATTERNS
    // ============================================

    cout << "\n--- LeetCode Patterns ---" << endl;

    // Two Sum pattern (find pair that sums to target)
    vector<int> twoSum = {2, 7, 11, 15};
    int target = 9;
    // (Would use hash map in real solution)

    // Sliding window sum
    vector<int> window = {1, 2, 3, 4, 5};
    int k = 3;  // Window size
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += window[i];
    cout << "Initial window sum: " << windowSum << endl;

    // Prefix sum
    vector<int> prefix = {1, 2, 3, 4, 5};
    for (int i = 1; i < prefix.size(); i++) {
        prefix[i] += prefix[i-1];
    }
    print(prefix, "Prefix sum");

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Implement remove duplicates from sorted array
     * Input: [1, 1, 2, 2, 2, 3, 4, 4]
     * Output: [1, 2, 3, 4] (modify in-place, return new size)
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Rotate array by k positions
     * Input: [1, 2, 3, 4, 5], k = 2
     * Output: [4, 5, 1, 2, 3]
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Find the majority element (appears > n/2 times)
     * Input: [3, 2, 3]
     * Output: 3
     * Hint: Boyer-Moore voting algorithm
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Merge two sorted arrays
     * Input: nums1 = [1, 2, 3, 0, 0, 0], m = 3
     *        nums2 = [2, 5, 6], n = 3
     * Output: [1, 2, 2, 3, 5, 6] (merge into nums1)
     */

    // YOUR CODE HERE

    return 0;
}
