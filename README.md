# C++ for Data Structures & Algorithms

A comprehensive learning path from C++ fundamentals to LeetCode mastery.

## Prerequisites

- Basic programming knowledge (you have Python/TypeScript background)
- g++ compiler (comes with Xcode Command Line Tools on Mac)
- VS Code with C/C++ extension

## Compilation

All files can be compiled with:
```bash
g++ -std=c++17 -o output_name filename.cpp
./output_name
```

## Learning Path

### Module 1: Fundamentals (Start Here)
**Time: 3-4 hours**

| File | Topics | Key Concepts |
|------|--------|--------------|
| `01-fundamentals/01_variables_types.cpp` | Types, variables, const | Static typing, sizeof, limits |
| `01-fundamentals/02_input_output.cpp` | cin, cout, streams | I/O for competitive programming |
| `01-fundamentals/03_operators_control.cpp` | Operators, loops, conditionals | Bitwise ops, control flow |
| `01-fundamentals/04_arrays_strings.cpp` | Arrays, C++ strings | String manipulation, ASCII |

**Key C++ Differences from Python:**
- Must declare types: `int x = 5;` not `x = 5`
- Use `{}` braces, not indentation
- Arrays are fixed size, use `vector` instead
- String is a class with methods like `.length()`, `.substr()`

### Module 2: Functions and Memory
**Time: 2-3 hours**

| File | Topics |
|------|--------|
| `02-functions-memory/01_functions.cpp` | Functions, lambdas, recursion |
| `02-functions-memory/02_pointers_references.cpp` | Pointers, references, dynamic memory |

**Critical Concepts:**
- Pass by reference (`&`) for efficiency
- Pointers (`*`) for linked structures
- `new`/`delete` for dynamic memory
- Smart pointers for safety

### Module 3: Object-Oriented Programming
**Time: 2 hours**

| File | Topics |
|------|--------|
| `03-oop/01_classes_objects.cpp` | Classes, inheritance, polymorphism |

### Module 4: STL Containers (Essential!)
**Time: 4-5 hours**

| File | Topics | LeetCode Use |
|------|--------|--------------|
| `04-stl-containers/01_vectors.cpp` | vector, iteration, algorithms | Arrays, dynamic arrays |
| `04-stl-containers/02_maps_sets.cpp` | map, unordered_map, set | Hash tables, counting |
| `04-stl-containers/03_stacks_queues.cpp` | stack, queue, priority_queue | BFS, DFS, heaps |

**Most Important STL for LeetCode:**
```cpp
vector<int> arr;           // Dynamic array
unordered_map<int, int> m; // Hash map O(1)
unordered_set<int> s;      // Hash set O(1)
priority_queue<int> pq;    // Max heap
stack<int> stk;            // LIFO
queue<int> q;              // FIFO (BFS)
```

### Module 5: Algorithms
**Time: 3-4 hours**

| File | Topics |
|------|--------|
| `05-algorithms/01_sorting_searching.cpp` | Sort algorithms, binary search |

### Module 6: Data Structures
**Time: 4-5 hours**

| File | Topics | LeetCode Problems |
|------|--------|-------------------|
| `06-data-structures/01_linked_lists.cpp` | Singly linked list operations | Reverse, cycle detection, merge |
| `06-data-structures/02_trees.cpp` | Binary trees, BST, traversals | DFS, BFS, path problems |

### Module 7: LeetCode Patterns
**Time: 4-5 hours**

| File | Pattern | Problem Types |
|------|---------|---------------|
| `07-leetcode-patterns/01_two_pointers.cpp` | Two pointers | Sorted arrays, palindromes |
| `07-leetcode-patterns/02_sliding_window.cpp` | Sliding window | Substrings, subarrays |

## Quick Reference

### Common STL Operations

```cpp
// Vector
vector<int> v = {1, 2, 3};
v.push_back(4);          // Add to end
v.pop_back();            // Remove from end
v.size();                // Size
v[0];                    // Access
sort(v.begin(), v.end()); // Sort

// Unordered Map (Hash Map)
unordered_map<string, int> m;
m["key"] = 1;            // Insert/update
m.count("key");          // Check exists (0 or 1)
m.find("key");           // Iterator or m.end()
for (auto& [k, v] : m)   // Iterate

// Unordered Set
unordered_set<int> s;
s.insert(1);             // Add
s.count(1);              // Check exists
s.erase(1);              // Remove

// Priority Queue
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
pq.push(1);              // Add
pq.top();                // Peek max/min
pq.pop();                // Remove top

// Stack
stack<int> stk;
stk.push(1);
stk.top();
stk.pop();

// Queue
queue<int> q;
q.push(1);
q.front();
q.pop();
```

### LeetCode Templates

```cpp
// Binary Search
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// BFS
void bfs(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        // Process node
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// DFS
void dfs(TreeNode* root) {
    if (!root) return;
    // Process node
    dfs(root->left);
    dfs(root->right);
}

// Two Pointers
int left = 0, right = arr.size() - 1;
while (left < right) {
    // Process
    left++; right--;
}

// Sliding Window
int left = 0;
for (int right = 0; right < n; right++) {
    // Expand window
    while (/* shrink condition */) {
        // Shrink window
        left++;
    }
    // Update answer
}
```

## Complexity Cheat Sheet

| Operation | vector | unordered_map | map | unordered_set | set |
|-----------|--------|---------------|-----|---------------|-----|
| Access | O(1) | O(1) avg | O(log n) | - | - |
| Search | O(n) | O(1) avg | O(log n) | O(1) avg | O(log n) |
| Insert | O(1)* | O(1) avg | O(log n) | O(1) avg | O(log n) |
| Delete | O(n) | O(1) avg | O(log n) | O(1) avg | O(log n) |

*amortized

## Suggested Study Schedule

| Day | Focus | Files |
|-----|-------|-------|
| 1 | C++ Basics | `01-fundamentals/*` |
| 2 | Memory & Functions | `02-functions-memory/*` |
| 3 | STL Containers | `04-stl-containers/*` |
| 4 | Data Structures | `06-data-structures/*` |
| 5 | Algorithms | `05-algorithms/*` |
| 6 | LeetCode Patterns | `07-leetcode-patterns/*` |
| 7+ | Practice | LeetCode Easy problems |

## LeetCode Problem Recommendations

### Easy (Start Here)
1. Two Sum (Hash Map)
2. Valid Parentheses (Stack)
3. Merge Two Sorted Lists (Linked List)
4. Maximum Subarray (DP/Kadane)
5. Binary Search
6. Reverse Linked List

### Medium (Build Up)
1. 3Sum (Two Pointers)
2. Container With Most Water (Two Pointers)
3. Longest Substring Without Repeat (Sliding Window)
4. Binary Tree Level Order (BFS)
5. Validate BST (DFS)
6. Top K Frequent Elements (Heap)

### Patterns to Master
1. Two Pointers
2. Sliding Window
3. Binary Search variations
4. BFS/DFS
5. Dynamic Programming (separate study)
6. Backtracking (separate study)

## Tips for Success

1. **Compile frequently** - C++ errors can be cryptic
2. **Use `-std=c++17`** - Modern features make life easier
3. **Learn STL well** - It's your toolkit for LeetCode
4. **Watch for edge cases** - Empty arrays, single elements, overflow
5. **Practice typing** - Speed matters in interviews
