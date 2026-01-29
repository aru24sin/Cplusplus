/**
 * Algorithms: Sorting and Searching
 *
 * Core algorithms that appear constantly in interviews.
 *
 * Compile: g++ -std=c++17 -o 01_sort 01_sorting_searching.cpp
 * Run: ./01_sort
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================
// SORTING ALGORITHMS
// ============================================

// Bubble Sort - O(n²)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Already sorted
    }
}

// Selection Sort - O(n²)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort - O(n²), good for nearly sorted
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort - O(n log n)
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort - O(n log n) average, O(n²) worst
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort - O(n log n)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ============================================
// SEARCHING ALGORITHMS
// ============================================

// Linear Search - O(n)
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Binary Search - O(log n) - array must be sorted!
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// Binary Search - Recursive
int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    }
    return binarySearchRecursive(arr, target, left, mid - 1);
}

// ============================================
// BINARY SEARCH VARIATIONS (Very important!)
// ============================================

// Find first occurrence
int findFirst(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Keep searching left
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// Find last occurrence
int findLast(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Keep searching right
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// Lower bound: first element >= target
int lowerBound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;  // Returns arr.size() if all elements < target
}

// Upper bound: first element > target
int upperBound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// Search in rotated sorted array
int searchRotated(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;

        // Left half is sorted
        if (arr[left] <= arr[mid]) {
            if (target >= arr[left] && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > arr[mid] && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

// Find peak element
int findPeakElement(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            right = mid;  // Peak is at mid or left of mid
        } else {
            left = mid + 1;  // Peak is right of mid
        }
    }

    return left;
}

// Search for minimum in rotated sorted array
int findMin(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) {
            left = mid + 1;  // Min is in right half
        } else {
            right = mid;  // Min is at mid or left of mid
        }
    }

    return arr[left];
}

// ============================================
// HELPER FUNCTIONS
// ============================================

void printArray(const vector<int>& arr, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// ============================================
// MAIN
// ============================================

int main() {
    cout << "=== Sorting and Searching Algorithms ===" << endl << endl;

    // Sorting demonstrations
    cout << "--- Sorting Algorithms ---" << endl;

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    vector<int> test = arr;
    bubbleSort(test);
    printArray(test, "Bubble Sort");

    test = arr;
    selectionSort(test);
    printArray(test, "Selection Sort");

    test = arr;
    insertionSort(test);
    printArray(test, "Insertion Sort");

    test = arr;
    mergeSort(test, 0, test.size() - 1);
    printArray(test, "Merge Sort");

    test = arr;
    quickSort(test, 0, test.size() - 1);
    printArray(test, "Quick Sort");

    test = arr;
    heapSort(test);
    printArray(test, "Heap Sort");

    // Using STL
    test = arr;
    sort(test.begin(), test.end());
    printArray(test, "STL sort");

    // Custom comparator
    test = arr;
    sort(test.begin(), test.end(), greater<int>());
    printArray(test, "Descending");

    // Searching
    cout << "\n--- Searching Algorithms ---" << endl;

    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArray(sorted, "Array");

    cout << "Linear search for 7: " << linearSearch(sorted, 7) << endl;
    cout << "Binary search for 7: " << binarySearch(sorted, 7) << endl;
    cout << "Binary search for 11: " << binarySearch(sorted, 11) << endl;

    // Binary search variations
    cout << "\n--- Binary Search Variations ---" << endl;

    vector<int> withDupes = {1, 2, 2, 2, 3, 4, 4, 5};
    printArray(withDupes, "Array with dupes");

    cout << "First occurrence of 2: " << findFirst(withDupes, 2) << endl;
    cout << "Last occurrence of 2: " << findLast(withDupes, 2) << endl;
    cout << "Lower bound of 2: " << lowerBound(withDupes, 2) << endl;
    cout << "Upper bound of 2: " << upperBound(withDupes, 2) << endl;

    // STL binary search
    cout << "\nSTL binary search:" << endl;
    cout << "binary_search for 3: " << binary_search(sorted.begin(), sorted.end(), 3) << endl;
    cout << "lower_bound for 5: " << (lower_bound(sorted.begin(), sorted.end(), 5) - sorted.begin()) << endl;
    cout << "upper_bound for 5: " << (upper_bound(sorted.begin(), sorted.end(), 5) - sorted.begin()) << endl;

    // Rotated array
    cout << "\n--- Rotated Array ---" << endl;

    vector<int> rotated = {4, 5, 6, 7, 0, 1, 2};
    printArray(rotated, "Rotated array");

    cout << "Search for 0: " << searchRotated(rotated, 0) << endl;
    cout << "Find minimum: " << findMin(rotated) << endl;

    // Peak element
    cout << "\n--- Peak Element ---" << endl;
    vector<int> peak = {1, 2, 3, 1};
    printArray(peak, "Array");
    cout << "Peak at index: " << findPeakElement(peak) << endl;

    // ============================================
    // COMPLEXITY SUMMARY
    // ============================================

    cout << "\n--- Time Complexity Summary ---" << endl;
    cout << "Bubble Sort:    O(n²)" << endl;
    cout << "Selection Sort: O(n²)" << endl;
    cout << "Insertion Sort: O(n²), O(n) for nearly sorted" << endl;
    cout << "Merge Sort:     O(n log n), stable" << endl;
    cout << "Quick Sort:     O(n log n) avg, O(n²) worst" << endl;
    cout << "Heap Sort:      O(n log n), in-place" << endl;
    cout << "Binary Search:  O(log n)" << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Find the square root of a number using binary search
     * Input: 8
     * Output: 2 (floor of sqrt(8))
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Search a 2D matrix
     * Matrix where each row is sorted and first element of row > last of previous
     * Input: [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
     * Output: true
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Find median of two sorted arrays
     * Input: nums1 = [1,3], nums2 = [2]
     * Output: 2.0
     * Try to achieve O(log(m+n))
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Count inversions in an array using merge sort
     * Inversion: arr[i] > arr[j] where i < j
     * Input: [2, 4, 1, 3, 5]
     * Output: 3 (pairs: (2,1), (4,1), (4,3))
     */

    // YOUR CODE HERE

    return 0;
}
