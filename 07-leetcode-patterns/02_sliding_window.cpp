/**
 * LeetCode Patterns: Sliding Window
 *
 * Essential for substring/subarray problems.
 *
 * Compile: g++ -std=c++17 -o 02_window 02_sliding_window.cpp
 * Run: ./02_window
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <deque>

using namespace std;

// ============================================
// PATTERN 1: FIXED SIZE WINDOW
// ============================================

// Maximum sum of subarray of size k
int maxSumSubarray(vector<int>& nums, int k) {
    if (nums.size() < k) return 0;

    // Calculate sum of first window
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];  // Add new, remove old
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

// Find all anagrams in a string
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.size() < p.size()) return result;

    vector<int> pCount(26, 0), sCount(26, 0);

    // Count characters in p
    for (char c : p) {
        pCount[c - 'a']++;
    }

    // Initialize first window
    for (int i = 0; i < p.size(); i++) {
        sCount[s[i] - 'a']++;
    }

    if (sCount == pCount) result.push_back(0);

    // Slide window
    for (int i = p.size(); i < s.size(); i++) {
        sCount[s[i] - 'a']++;           // Add new char
        sCount[s[i - p.size()] - 'a']--; // Remove old char

        if (sCount == pCount) {
            result.push_back(i - p.size() + 1);
        }
    }

    return result;
}

// Maximum of all subarrays of size k (using deque)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;  // Store indices, front is always max

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices outside current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements (they'll never be max)
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Window is complete
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

// ============================================
// PATTERN 2: VARIABLE SIZE WINDOW
// ============================================

// Minimum size subarray with sum >= target
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        // Shrink window while condition is met
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}

// Longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];

        // If char exists in current window, shrink
        if (lastIndex.count(c) && lastIndex[c] >= left) {
            left = lastIndex[c] + 1;
        }

        maxLen = max(maxLen, right - left + 1);
        lastIndex[c] = right;
    }

    return maxLen;
}

// Longest substring with at most K distinct characters
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> charCount;
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {
        charCount[s[right]]++;

        // Shrink window if too many distinct chars
        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

// Longest repeating character replacement
int characterReplacement(string s, int k) {
    vector<int> count(26, 0);
    int maxCount = 0;  // Count of most frequent char in window
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);

        // Window size - maxCount = chars that need replacement
        // If > k, need to shrink
        while (right - left + 1 - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

// ============================================
// PATTERN 3: WINDOW WITH CONDITION
// ============================================

// Minimum window substring
string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    unordered_map<char, int> need, have;

    for (char c : t) {
        need[c]++;
    }

    int required = need.size();  // Unique chars needed
    int formed = 0;              // Unique chars satisfied
    int minLen = INT_MAX;
    int start = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        have[c]++;

        // Check if current char satisfies requirement
        if (need.count(c) && have[c] == need[c]) {
            formed++;
        }

        // Try to shrink window
        while (formed == required) {
            // Update minimum
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            // Remove leftmost char
            char leftChar = s[left];
            have[leftChar]--;
            if (need.count(leftChar) && have[leftChar] < need[leftChar]) {
                formed--;
            }
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

// Subarrays with K different integers
int subarraysWithKDistinct(vector<int>& nums, int k) {
    // Count subarrays with at most k - count subarrays with at most k-1
    auto atMostK = [&](int k) {
        unordered_map<int, int> count;
        int result = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            count[nums[right]]++;

            while (count.size() > k) {
                count[nums[left]]--;
                if (count[nums[left]] == 0) {
                    count.erase(nums[left]);
                }
                left++;
            }

            result += right - left + 1;
        }

        return result;
    };

    return atMostK(k) - atMostK(k - 1);
}

// ============================================
// HELPER
// ============================================

void printVector(const vector<int>& v, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// ============================================
// MAIN
// ============================================

int main() {
    cout << "=== Sliding Window Pattern ===" << endl << endl;

    // Fixed size window
    cout << "--- Fixed Size Window ---" << endl;

    vector<int> nums1 = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    cout << "Max sum subarray of size 4: " << maxSumSubarray(nums1, 4) << endl;

    string s1 = "cbaebabacd", p1 = "abc";
    auto anagrams = findAnagrams(s1, p1);
    printVector(anagrams, "Anagram indices of 'abc' in 'cbaebabacd'");

    vector<int> nums2 = {1, 3, -1, -3, 5, 3, 6, 7};
    auto maxWindow = maxSlidingWindow(nums2, 3);
    printVector(maxWindow, "Max in sliding window of size 3");

    // Variable size window
    cout << "\n--- Variable Size Window ---" << endl;

    vector<int> nums3 = {2, 3, 1, 2, 4, 3};
    cout << "Min subarray with sum >= 7: " << minSubArrayLen(7, nums3) << endl;

    string s2 = "abcabcbb";
    cout << "Longest substring without repeat in '" << s2 << "': "
         << lengthOfLongestSubstring(s2) << endl;

    string s3 = "eceba";
    cout << "Longest with at most 2 distinct in '" << s3 << "': "
         << lengthOfLongestSubstringKDistinct(s3, 2) << endl;

    string s4 = "AABABBA";
    cout << "Character replacement (k=1) in '" << s4 << "': "
         << characterReplacement(s4, 1) << endl;

    // Window with condition
    cout << "\n--- Window with Condition ---" << endl;

    string s5 = "ADOBECODEBANC", t5 = "ABC";
    cout << "Min window of '" << t5 << "' in '" << s5 << "': '"
         << minWindow(s5, t5) << "'" << endl;

    vector<int> nums4 = {1, 2, 1, 2, 3};
    cout << "Subarrays with exactly 2 distinct: "
         << subarraysWithKDistinct(nums4, 2) << endl;

    // Template
    cout << "\n--- Sliding Window Template ---" << endl;
    cout << "int left = 0;\n";
    cout << "for (int right = 0; right < n; right++) {\n";
    cout << "    // Add nums[right] to window\n";
    cout << "    \n";
    cout << "    while (/* window needs shrinking */) {\n";
    cout << "        // Remove nums[left] from window\n";
    cout << "        left++;\n";
    cout << "    }\n";
    cout << "    \n";
    cout << "    // Update answer\n";
    cout << "}" << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Permutation in String
     * Check if s2 contains a permutation of s1
     * Input: s1 = "ab", s2 = "eidbaooo"
     * Output: true ("ba" is permutation of "ab")
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Fruit Into Baskets
     * Longest subarray with at most 2 distinct values
     * Input: fruits = [1,2,1,2,3,3,2]
     * Output: 4 (subarray [2,1,2,3] but wait for only 2 types... [1,2,1,2] = 4)
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Longest Substring with At Least K Repeating Characters
     * Each character appears at least k times
     * Input: s = "aaabb", k = 3
     * Output: 3 ("aaa")
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Substring with Concatenation of All Words
     * Find all starting indices where s contains all words concatenated
     * Input: s = "barfoothefoobarman", words = ["foo","bar"]
     * Output: [0, 9]
     */

    // YOUR CODE HERE

    return 0;
}
