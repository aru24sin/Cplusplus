/**
 * C++ STL: Stacks, Queues, and Priority Queues
 *
 * Essential data structures for many algorithm problems.
 *
 * Compile: g++ -std=c++17 -o 03_stacks 03_stacks_queues.cpp
 * Run: ./03_stacks
 */

#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <functional>  // For greater<>

using namespace std;

int main() {
    cout << "=== Stacks, Queues, and Priority Queues ===" << endl << endl;

    // ============================================
    // STACK (LIFO - Last In First Out)
    // ============================================

    cout << "--- Stack ---" << endl;

    stack<int> stk;

    // Push elements
    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << "Stack top: " << stk.top() << endl;  // 30
    cout << "Stack size: " << stk.size() << endl;

    // Pop elements
    cout << "Popping: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";  // 30, 20, 10
        stk.pop();
    }
    cout << endl;

    // Stack from vector (custom underlying container)
    vector<int> vec = {1, 2, 3};
    stack<int, vector<int>> stkFromVec(vec);

    // ============================================
    // QUEUE (FIFO - First In First Out)
    // ============================================

    cout << "\n--- Queue ---" << endl;

    queue<int> q;

    // Enqueue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue front: " << q.front() << endl;  // 10
    cout << "Queue back: " << q.back() << endl;    // 30
    cout << "Queue size: " << q.size() << endl;

    // Dequeue
    cout << "Dequeuing: ";
    while (!q.empty()) {
        cout << q.front() << " ";  // 10, 20, 30
        q.pop();
    }
    cout << endl;

    // ============================================
    // DEQUE (Double-Ended Queue)
    // ============================================

    cout << "\n--- Deque ---" << endl;

    deque<int> dq;

    // Add to both ends
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(1);
    dq.push_front(0);

    cout << "Deque: ";
    for (int x : dq) cout << x << " ";  // 0, 1, 2, 3
    cout << endl;

    // Random access (like vector)
    cout << "dq[2]: " << dq[2] << endl;

    // Remove from both ends
    dq.pop_front();
    dq.pop_back();
    cout << "After pop_front and pop_back: ";
    for (int x : dq) cout << x << " ";  // 1, 2
    cout << endl;

    // ============================================
    // PRIORITY QUEUE (Heap)
    // ============================================

    cout << "\n--- Priority Queue (Max Heap) ---" << endl;

    // Default is MAX heap
    priority_queue<int> maxHeap;

    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);

    cout << "Max heap top: " << maxHeap.top() << endl;  // 50

    cout << "Popping: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";  // 50, 30, 20, 10
        maxHeap.pop();
    }
    cout << endl;

    // MIN heap
    cout << "\n--- Priority Queue (Min Heap) ---" << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);

    cout << "Min heap top: " << minHeap.top() << endl;  // 10

    cout << "Popping: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";  // 10, 20, 30, 50
        minHeap.pop();
    }
    cout << endl;

    // Priority queue with pairs
    cout << "\n--- Priority Queue with Pairs ---" << endl;

    // For pairs, compares first element, then second
    priority_queue<pair<int, string>> pairHeap;

    pairHeap.push({3, "three"});
    pairHeap.push({1, "one"});
    pairHeap.push({2, "two"});

    while (!pairHeap.empty()) {
        auto [priority, name] = pairHeap.top();
        cout << priority << ": " << name << endl;
        pairHeap.pop();
    }

    // Custom comparator
    cout << "\n--- Custom Comparator ---" << endl;

    auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first;  // Min heap by first element
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> customHeap(cmp);

    customHeap.push({3, "three"});
    customHeap.push({1, "one"});
    customHeap.push({2, "two"});

    while (!customHeap.empty()) {
        auto [priority, name] = customHeap.top();
        cout << priority << ": " << name << endl;
        customHeap.pop();
    }

    // ============================================
    // LEETCODE PATTERNS
    // ============================================

    cout << "\n--- LeetCode Patterns ---" << endl;

    // Pattern 1: Valid Parentheses
    cout << "\nValid Parentheses:" << endl;
    string brackets = "({[]})";
    stack<char> bracketStack;
    bool valid = true;

    for (char c : brackets) {
        if (c == '(' || c == '{' || c == '[') {
            bracketStack.push(c);
        } else {
            if (bracketStack.empty()) {
                valid = false;
                break;
            }
            char top = bracketStack.top();
            bracketStack.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                valid = false;
                break;
            }
        }
    }
    valid = valid && bracketStack.empty();
    cout << "\"" << brackets << "\" is valid: " << (valid ? "yes" : "no") << endl;

    // Pattern 2: BFS with Queue
    cout << "\nBFS Level Order (simulated):" << endl;
    queue<pair<int, int>> bfsQueue;  // (node, level)
    bfsQueue.push({1, 0});
    bfsQueue.push({2, 1});
    bfsQueue.push({3, 1});
    bfsQueue.push({4, 2});
    bfsQueue.push({5, 2});

    while (!bfsQueue.empty()) {
        auto [node, level] = bfsQueue.front();
        bfsQueue.pop();
        cout << "Node " << node << " at level " << level << endl;
    }

    // Pattern 3: Monotonic Stack (Next Greater Element)
    cout << "\nNext Greater Element:" << endl;
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result(nums.size(), -1);
    stack<int> monoStack;  // Store indices

    for (int i = 0; i < nums.size(); i++) {
        while (!monoStack.empty() && nums[monoStack.top()] < nums[i]) {
            result[monoStack.top()] = nums[i];
            monoStack.pop();
        }
        monoStack.push(i);
    }

    cout << "Array: ";
    for (int n : nums) cout << n << " ";
    cout << "\nNext greater: ";
    for (int n : result) cout << n << " ";
    cout << endl;

    // Pattern 4: K Largest Elements
    cout << "\nK Largest Elements:" << endl;
    vector<int> elements = {3, 2, 1, 5, 6, 4};
    int k = 3;

    // Use min heap of size k
    priority_queue<int, vector<int>, greater<int>> kHeap;

    for (int num : elements) {
        kHeap.push(num);
        if (kHeap.size() > k) {
            kHeap.pop();  // Remove smallest
        }
    }

    cout << "Top " << k << " elements: ";
    while (!kHeap.empty()) {
        cout << kHeap.top() << " ";
        kHeap.pop();
    }
    cout << endl;

    // Pattern 5: Sliding Window Maximum
    cout << "\nSliding Window Maximum:" << endl;
    vector<int> windowNums = {1, 3, -1, -3, 5, 3, 6, 7};
    int windowK = 3;
    deque<int> windowDq;  // Store indices
    vector<int> maxInWindow;

    for (int i = 0; i < windowNums.size(); i++) {
        // Remove elements outside window
        while (!windowDq.empty() && windowDq.front() <= i - windowK) {
            windowDq.pop_front();
        }
        // Remove smaller elements (they'll never be maximum)
        while (!windowDq.empty() && windowNums[windowDq.back()] < windowNums[i]) {
            windowDq.pop_back();
        }
        windowDq.push_back(i);

        if (i >= windowK - 1) {
            maxInWindow.push_back(windowNums[windowDq.front()]);
        }
    }

    cout << "Array: ";
    for (int n : windowNums) cout << n << " ";
    cout << "\nMax in each window of " << windowK << ": ";
    for (int n : maxInWindow) cout << n << " ";
    cout << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Implement a Min Stack
     * A stack that supports:
     * - push(x)
     * - pop()
     * - top()
     * - getMin() in O(1)
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Evaluate Reverse Polish Notation
     * Input: ["2","1","+","3","*"]
     * Output: 9 ((2 + 1) * 3)
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Implement Queue using Two Stacks
     * Support push, pop, peek, empty
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Merge K Sorted Lists
     * Given K sorted linked lists, merge them into one sorted list
     * Use a priority queue with custom comparator
     */

    // YOUR CODE HERE

    return 0;
}
