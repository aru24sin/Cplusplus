/**
 * C++ STL: Maps and Sets
 *
 * Hash-based and tree-based associative containers.
 * Essential for many LeetCode problems!
 *
 * Compile: g++ -std=c++17 -o 02_maps 02_maps_sets.cpp
 * Run: ./02_maps
 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "=== Maps and Sets ===" << endl << endl;

    // ============================================
    // UNORDERED_MAP (Hash Map) - O(1) average
    // ============================================

    cout << "--- unordered_map (Hash Map) ---" << endl;

    // Most common for LeetCode!
    unordered_map<string, int> wordCount;

    // Insert elements
    wordCount["hello"] = 1;
    wordCount["world"] = 2;
    wordCount.insert({"foo", 3});
    wordCount.insert(make_pair("bar", 4));

    // Access elements
    cout << "wordCount[\"hello\"]: " << wordCount["hello"] << endl;

    // WARNING: [] creates entry if key doesn't exist!
    cout << "wordCount[\"new\"]: " << wordCount["new"] << endl;  // Creates with value 0
    cout << "Size after accessing \"new\": " << wordCount.size() << endl;

    // Safe access with find()
    auto it = wordCount.find("hello");
    if (it != wordCount.end()) {
        cout << "Found: " << it->first << " -> " << it->second << endl;
    }

    // Check existence with count()
    if (wordCount.count("world") > 0) {
        cout << "\"world\" exists" << endl;
    }

    // Iterate
    cout << "All entries:" << endl;
    for (const auto& [key, value] : wordCount) {  // Structured binding (C++17)
        cout << "  " << key << ": " << value << endl;
    }

    // Erase
    wordCount.erase("new");

    // ============================================
    // MAP (Ordered Map) - O(log n)
    // ============================================

    cout << "\n--- map (Ordered/Tree Map) ---" << endl;

    // Keys are sorted!
    map<string, int> orderedMap;
    orderedMap["banana"] = 3;
    orderedMap["apple"] = 1;
    orderedMap["cherry"] = 2;

    cout << "Ordered iteration:" << endl;
    for (const auto& [key, value] : orderedMap) {
        cout << "  " << key << ": " << value << endl;  // apple, banana, cherry
    }

    // Lower and upper bound
    map<int, string> scores;
    scores[50] = "F";
    scores[60] = "D";
    scores[70] = "C";
    scores[80] = "B";
    scores[90] = "A";

    int studentScore = 75;
    auto lb = scores.lower_bound(studentScore);  // First >= studentScore
    auto ub = scores.upper_bound(studentScore);  // First > studentScore

    if (lb != scores.begin()) {
        --lb;  // Go to the grade just below
        cout << "Score " << studentScore << " gets grade: " << lb->second << endl;
    }

    // ============================================
    // UNORDERED_SET (Hash Set) - O(1) average
    // ============================================

    cout << "\n--- unordered_set (Hash Set) ---" << endl;

    unordered_set<int> uniqueNums;

    // Insert
    uniqueNums.insert(5);
    uniqueNums.insert(3);
    uniqueNums.insert(5);  // Duplicate, won't be added
    uniqueNums.insert(1);

    cout << "Size: " << uniqueNums.size() << endl;  // 3, not 4

    // Check existence
    if (uniqueNums.count(3) > 0) {  // or find() != end()
        cout << "3 exists in set" << endl;
    }

    // Iterate (no guaranteed order)
    cout << "Elements: ";
    for (int x : uniqueNums) {
        cout << x << " ";
    }
    cout << endl;

    // From vector (deduplicate)
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    unordered_set<int> unique(nums.begin(), nums.end());
    cout << "Unique count: " << unique.size() << endl;

    // ============================================
    // SET (Ordered Set) - O(log n)
    // ============================================

    cout << "\n--- set (Ordered Set) ---" << endl;

    set<int> orderedSet;
    orderedSet.insert(5);
    orderedSet.insert(3);
    orderedSet.insert(8);
    orderedSet.insert(1);

    cout << "Ordered elements: ";
    for (int x : orderedSet) {
        cout << x << " ";  // 1, 3, 5, 8
    }
    cout << endl;

    // Lower/upper bound
    auto lbSet = orderedSet.lower_bound(4);  // First >= 4
    cout << "lower_bound(4): " << *lbSet << endl;  // 5

    // Min and max
    cout << "Min: " << *orderedSet.begin() << endl;
    cout << "Max: " << *orderedSet.rbegin() << endl;

    // ============================================
    // MULTISET AND MULTIMAP
    // ============================================

    cout << "\n--- multiset and multimap ---" << endl;

    // Allows duplicates
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    ms.insert(3);

    cout << "Multiset count of 5: " << ms.count(5) << endl;  // 3

    multimap<string, int> mm;
    mm.insert({"apple", 1});
    mm.insert({"apple", 2});
    mm.insert({"apple", 3});

    // Get all values for a key
    auto range = mm.equal_range("apple");
    cout << "All values for 'apple': ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl;

    // ============================================
    // COMMON LEETCODE PATTERNS
    // ============================================

    cout << "\n--- LeetCode Patterns ---" << endl;

    // Pattern 1: Two Sum using hash map
    vector<int> twoSumNums = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < twoSumNums.size(); i++) {
        int complement = target - twoSumNums[i];
        if (numToIndex.count(complement)) {
            cout << "Two Sum indices: " << numToIndex[complement] << ", " << i << endl;
            break;
        }
        numToIndex[twoSumNums[i]] = i;
    }

    // Pattern 2: Frequency count
    string str = "programming";
    unordered_map<char, int> freq;
    for (char c : str) {
        freq[c]++;
    }
    cout << "Character frequencies in '" << str << "':" << endl;
    for (const auto& [ch, count] : freq) {
        cout << "  '" << ch << "': " << count << endl;
    }

    // Pattern 3: Find duplicates
    vector<int> withDupes = {1, 2, 3, 2, 4, 3, 5};
    unordered_set<int> seen;
    cout << "Duplicates: ";
    for (int n : withDupes) {
        if (seen.count(n)) {
            cout << n << " ";
        }
        seen.insert(n);
    }
    cout << endl;

    // Pattern 4: Group anagrams
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    unordered_map<string, vector<string>> anagramGroups;

    for (const string& word : words) {
        string sorted = word;
        sort(sorted.begin(), sorted.end());
        anagramGroups[sorted].push_back(word);
    }

    cout << "Anagram groups:" << endl;
    for (const auto& [key, group] : anagramGroups) {
        cout << "  ";
        for (const string& w : group) {
            cout << w << " ";
        }
        cout << endl;
    }

    // Pattern 5: Sliding window with set
    vector<int> arr = {1, 2, 3, 1, 2, 3};
    int k = 3;  // Window size
    unordered_set<int> windowSet;
    bool hasDuplicatesInWindow = false;

    for (int i = 0; i < arr.size(); i++) {
        if (i >= k) {
            windowSet.erase(arr[i - k]);  // Remove element leaving window
        }
        if (windowSet.count(arr[i])) {
            hasDuplicatesInWindow = true;
            break;
        }
        windowSet.insert(arr[i]);
    }
    cout << "Has duplicates in window of size " << k << ": "
         << (hasDuplicatesInWindow ? "yes" : "no") << endl;

    // ============================================
    // CUSTOM HASH FOR UNORDERED CONTAINERS
    // ============================================

    cout << "\n--- Custom Hash ---" << endl;

    // For pair<int, int> as key
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    unordered_set<pair<int, int>, PairHash> pointSet;
    pointSet.insert({1, 2});
    pointSet.insert({3, 4});
    cout << "Point (1,2) exists: " << pointSet.count({1, 2}) << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Find first non-repeating character
     * Input: "leetcode"
     * Output: 0 (index of 'l')
     * Input: "loveleetcode"
     * Output: 2 (index of 'v')
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Check if two strings are isomorphic
     * Input: s = "egg", t = "add"
     * Output: true (e->a, g->d)
     * Input: s = "foo", t = "bar"
     * Output: false
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Find intersection of two arrays
     * Input: nums1 = [1,2,2,1], nums2 = [2,2]
     * Output: [2] (unique intersection)
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: LRU Cache (design problem)
     * Implement a cache with:
     * - get(key) returns value or -1
     * - put(key, value) inserts/updates
     * - When capacity exceeded, remove least recently used
     * Hint: Use unordered_map + list (doubly linked list)
     */

    // YOUR CODE HERE

    return 0;
}
