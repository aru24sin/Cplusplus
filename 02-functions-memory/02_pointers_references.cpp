/**
 * C++ Functions and Memory: Pointers and References
 *
 * Understanding memory is what separates good C++ programmers from great ones.
 * Essential for linked lists, trees, and graph problems.
 *
 * Compile: g++ -std=c++17 -o 02_pointers 02_pointers_references.cpp
 * Run: ./02_pointers
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "=== Pointers and References ===" << endl << endl;

    // ============================================
    // MEMORY BASICS
    // ============================================

    cout << "--- Memory Basics ---" << endl;

    int x = 42;

    // Every variable has an address in memory
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;  // & is the "address-of" operator
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;

    // ============================================
    // POINTERS
    // ============================================

    cout << "\n--- Pointers ---" << endl;

    // A pointer stores a memory address
    int* ptr = &x;  // ptr points to x

    cout << "ptr (address): " << ptr << endl;
    cout << "*ptr (value at address): " << *ptr << endl;  // * is dereference

    // Modify through pointer
    *ptr = 100;
    cout << "After *ptr = 100, x = " << x << endl;

    // Pointer arithmetic (careful!)
    int arr[] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;  // Arrays decay to pointers

    cout << "\nPointer arithmetic:" << endl;
    cout << "arrPtr points to: " << *arrPtr << endl;
    cout << "arrPtr + 1 points to: " << *(arrPtr + 1) << endl;
    cout << "arrPtr + 2 points to: " << *(arrPtr + 2) << endl;

    // Iterate array with pointer
    cout << "Array via pointer: ";
    for (int* p = arr; p < arr + 5; p++) {
        cout << *p << " ";
    }
    cout << endl;

    // ============================================
    // NULL AND NULLPTR
    // ============================================

    cout << "\n--- Null Pointers ---" << endl;

    int* nullPtr = nullptr;  // Modern C++ (preferred)
    // int* nullPtr = NULL;  // C-style (avoid)
    // int* nullPtr = 0;     // Also valid but avoid

    if (nullPtr == nullptr) {
        cout << "Pointer is null" << endl;
    }

    // Always check before dereferencing!
    if (nullPtr != nullptr) {
        cout << *nullPtr << endl;  // Would crash if executed on null
    } else {
        cout << "Cannot dereference null pointer" << endl;
    }

    // ============================================
    // REFERENCES
    // ============================================

    cout << "\n--- References ---" << endl;

    int original = 50;
    int& ref = original;  // ref is an alias for original

    cout << "original: " << original << endl;
    cout << "ref: " << ref << endl;
    cout << "Address of original: " << &original << endl;
    cout << "Address of ref: " << &ref << " (same!)" << endl;

    // Modify through reference
    ref = 75;
    cout << "After ref = 75, original = " << original << endl;

    // References vs Pointers:
    // - References cannot be null
    // - References cannot be reassigned to refer to different variable
    // - References don't need dereferencing syntax
    // - References are often preferred for function parameters

    // ============================================
    // CONST WITH POINTERS
    // ============================================

    cout << "\n--- Const with Pointers ---" << endl;

    int value = 10;
    int other = 20;

    // Pointer to const - can't modify value through pointer
    const int* ptrToConst = &value;
    // *ptrToConst = 20;  // ERROR
    ptrToConst = &other;  // OK - can change what it points to

    // Const pointer - can't change what it points to
    int* const constPtr = &value;
    *constPtr = 20;  // OK - can modify value
    // constPtr = &other;  // ERROR - can't change address

    // Const pointer to const - both are const
    const int* const fullyConst = &value;
    // *fullyConst = 30;  // ERROR
    // fullyConst = &other;  // ERROR

    cout << "Read the pointer declarations right to left:" << endl;
    cout << "const int* ptr  = 'ptr is a pointer to const int'" << endl;
    cout << "int* const ptr  = 'ptr is a const pointer to int'" << endl;

    // ============================================
    // DYNAMIC MEMORY ALLOCATION
    // ============================================

    cout << "\n--- Dynamic Memory (new/delete) ---" << endl;

    // Allocate single variable
    int* dynamicInt = new int;
    *dynamicInt = 42;
    cout << "Dynamic int: " << *dynamicInt << endl;

    // Allocate with initial value
    int* dynamicInit = new int(100);
    cout << "Dynamic int (initialized): " << *dynamicInit << endl;

    // Don't forget to free memory!
    delete dynamicInt;
    delete dynamicInit;

    // Allocate array
    int* dynamicArr = new int[5];
    for (int i = 0; i < 5; i++) {
        dynamicArr[i] = i * 10;
    }
    cout << "Dynamic array: ";
    for (int i = 0; i < 5; i++) {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;

    // Free array (use delete[] for arrays!)
    delete[] dynamicArr;

    // After delete, pointer is dangling - set to nullptr
    dynamicArr = nullptr;

    // ============================================
    // COMMON POINTER PATTERNS FOR DSA
    // ============================================

    cout << "\n--- DSA Pointer Patterns ---" << endl;

    // Linked List Node structure
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    // Create a simple linked list: 1 -> 2 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // Traverse linked list
    cout << "Linked list: ";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;

    // Two-pointer technique on array
    int twoPtr[] = {1, 2, 3, 4, 5};
    int* left = twoPtr;
    int* right = twoPtr + 4;

    cout << "Two pointers: left=" << *left << ", right=" << *right << endl;

    // Clean up linked list
    current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    // ============================================
    // SMART POINTERS (C++11) - PREVIEW
    // ============================================

    cout << "\n--- Smart Pointers (Preview) ---" << endl;

    #include <memory>

    // unique_ptr - single owner
    unique_ptr<int> smartPtr = make_unique<int>(42);
    cout << "unique_ptr: " << *smartPtr << endl;
    // No need to delete - automatically freed when out of scope

    // shared_ptr - multiple owners (reference counted)
    shared_ptr<int> shared1 = make_shared<int>(100);
    shared_ptr<int> shared2 = shared1;  // Both point to same memory
    cout << "shared_ptr use count: " << shared1.use_count() << endl;

    cout << "\nSmart pointers auto-delete - no memory leaks!" << endl;

    // ============================================
    // COMMON MISTAKES
    // ============================================

    cout << "\n--- Common Mistakes to Avoid ---" << endl;

    cout << "1. Dereferencing null pointer" << endl;
    cout << "2. Using pointer after delete (dangling pointer)" << endl;
    cout << "3. Memory leaks (forgetting to delete)" << endl;
    cout << "4. Double delete" << endl;
    cout << "5. Using delete instead of delete[] for arrays" << endl;
    cout << "6. Returning pointer to local variable" << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Swap two integers using pointers
     * void swap(int* a, int* b)
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Reverse an array using pointers
     * void reverse(int* arr, int size)
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Implement a simple singly linked list
     * - Create a linked list with values 1, 2, 3, 4, 5
     * - Write a function to print it
     * - Write a function to reverse it
     * - Don't forget to delete all nodes!
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Find the middle element of a linked list
     * Use the fast-slow pointer technique
     * Fast moves 2 steps, slow moves 1 step
     * When fast reaches end, slow is at middle
     */

    // YOUR CODE HERE

    return 0;
}
