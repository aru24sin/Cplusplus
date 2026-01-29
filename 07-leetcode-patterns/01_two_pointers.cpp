/**
 * LeetCode Patterns: Two Pointers
 *
 * One of the most common patterns in array/string problems.
 *
 * Compile: g++ -std=c++17 -o 01_two_ptr 01_two_pointers.cpp
 * Run: ./01_two_ptr
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// ============================================
// PATTERN 1: OPPOSITE DIRECTION (Start/End)
// ============================================

// Two Sum II (sorted array)
vector<int> twoSumSorted(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left + 1, right + 1};  // 1-indexed
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {};
}

// Three Sum (find all triplets that sum to 0)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Two pointer for remaining two numbers
        int left = i + 1, right = nums.size() - 1;
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

// Container with most water
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        int water = min(height[left], height[right]) * (right - left);
        maxWater = max(maxWater, water);

        // Move the shorter side (it limits the height)
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

// Valid palindrome (ignoring non-alphanumeric)
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Skip non-alphanumeric
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

// Reverse string in-place
void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// ============================================
// PATTERN 2: SAME DIRECTION (Fast/Slow)
// ============================================

// Remove duplicates from sorted array
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int slow = 0;  // Position to place next unique element

    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }

    return slow + 1;  // New length
}

// Remove element
int removeElement(vector<int>& nums, int val) {
    int slow = 0;

    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    return slow;
}

// Move zeroes to end
void moveZeroes(vector<int>& nums) {
    int slow = 0;

    // Move non-zero elements to front
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}

// Sort colors (Dutch National Flag)
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {  // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// ============================================
// PATTERN 3: SLIDING WINDOW VARIANT
// ============================================

// Minimum size subarray sum
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

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
    vector<int> lastSeen(128, -1);  // ASCII
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];

        // If character was seen in current window, move left
        if (lastSeen[c] >= left) {
            left = lastSeen[c] + 1;
        }

        maxLen = max(maxLen, right - left + 1);
        lastSeen[c] = right;
    }

    return maxLen;
}

// ============================================
// PATTERN 4: LINKED LIST (Fast/Slow)
// ============================================

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Find middle of linked list
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Detect cycle
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

// ============================================
// HELPER FUNCTIONS
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
    cout << "=== Two Pointers Pattern ===" << endl << endl;

    // Opposite direction examples
    cout << "--- Opposite Direction ---" << endl;

    vector<int> nums1 = {2, 7, 11, 15};
    auto result = twoSumSorted(nums1, 9);
    printVector(result, "Two Sum II (target=9)");

    vector<int> nums2 = {-1, 0, 1, 2, -1, -4};
    auto triplets = threeSum(nums2);
    cout << "Three Sum:" << endl;
    for (const auto& t : triplets) {
        printVector(t, "  ");
    }

    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Container with most water: " << maxArea(heights) << endl;

    string palindrome = "A man, a plan, a canal: Panama";
    cout << "\"" << palindrome << "\" is palindrome: "
         << (isPalindrome(palindrome) ? "yes" : "no") << endl;

    // Same direction examples
    cout << "\n--- Same Direction ---" << endl;

    vector<int> dupes = {1, 1, 2, 2, 3, 4, 4};
    int newLen = removeDuplicates(dupes);
    cout << "Remove duplicates, new length: " << newLen << endl;
    printVector(vector<int>(dupes.begin(), dupes.begin() + newLen), "Array");

    vector<int> zeros = {0, 1, 0, 3, 12};
    moveZeroes(zeros);
    printVector(zeros, "Move zeroes");

    vector<int> colors = {2, 0, 2, 1, 1, 0};
    sortColors(colors);
    printVector(colors, "Sort colors");

    // Sliding window variant
    cout << "\n--- Sliding Window ---" << endl;

    vector<int> subarray = {2, 3, 1, 2, 4, 3};
    cout << "Min subarray length for sum >= 7: " << minSubArrayLen(7, subarray) << endl;

    string str = "abcabcbb";
    cout << "Longest substring without repeat in \"" << str << "\": "
         << lengthOfLongestSubstring(str) << endl;

    // ============================================
    // WHEN TO USE TWO POINTERS
    // ============================================

    cout << "\n--- When to Use Two Pointers ---" << endl;
    cout << "1. Sorted array - opposite direction pointers" << endl;
    cout << "2. Remove/modify in-place - fast/slow pointers" << endl;
    cout << "3. Palindrome check - opposite direction" << endl;
    cout << "4. Linked list cycle - fast/slow pointers" << endl;
    cout << "5. Sliding window - left/right boundary" << endl;
    cout << "6. Partition array - low/mid/high pointers" << endl;

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Three Sum Closest
     * Find three integers whose sum is closest to target
     * Input: nums = [-1,2,1,-4], target = 1
     * Output: 2 (-1 + 2 + 1 = 2)
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Trapping Rain Water
     * Given elevation map, compute water that can be trapped
     * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
     * Output: 6
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Remove Duplicates II (allow at most 2 duplicates)
     * Input: [1,1,1,2,2,3]
     * Output: 5, nums = [1,1,2,2,3]
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Linked List Cycle II (return node where cycle begins)
     * If no cycle, return null
     */

    // YOUR CODE HERE

    return 0;
}
