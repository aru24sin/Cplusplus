/**
 * Data Structures: Linked Lists
 *
 * Fundamental for many LeetCode problems.
 * Master pointer manipulation here.
 *
 * Compile: g++ -std=c++17 -o 01_linked 01_linked_lists.cpp
 * Run: ./01_linked
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================
// LINKED LIST NODE DEFINITION
// ============================================

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ============================================
// HELPER FUNCTIONS
// ============================================

// Create linked list from vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;

    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head;
}

// Print linked list
void printList(ListNode* head, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Delete linked list (prevent memory leaks)
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Get list length
int getLength(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// ============================================
// BASIC OPERATIONS
// ============================================

// Insert at beginning - O(1)
ListNode* insertAtHead(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val, head);
    return newNode;
}

// Insert at end - O(n)
ListNode* insertAtTail(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    if (!head) return newNode;

    ListNode* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

// Insert at position - O(n)
ListNode* insertAtPosition(ListNode* head, int val, int pos) {
    if (pos == 0) return insertAtHead(head, val);

    ListNode* current = head;
    for (int i = 0; i < pos - 1 && current; i++) {
        current = current->next;
    }

    if (!current) return head;  // Position out of bounds

    ListNode* newNode = new ListNode(val, current->next);
    current->next = newNode;

    return head;
}

// Delete by value - O(n)
ListNode* deleteByValue(ListNode* head, int val) {
    if (!head) return nullptr;

    // If head needs to be deleted
    if (head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* current = head;
    while (current->next && current->next->val != val) {
        current = current->next;
    }

    if (current->next) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}

// ============================================
// CLASSIC ALGORITHMS
// ============================================

// Reverse a linked list - O(n)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current) {
        ListNode* next = current->next;  // Save next
        current->next = prev;            // Reverse pointer
        prev = current;                  // Move prev forward
        current = next;                  // Move current forward
    }

    return prev;
}

// Reverse recursively
ListNode* reverseListRecursive(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

// Find middle node (slow-fast pointer technique)
ListNode* findMiddle(ListNode* head) {
    if (!head) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;  // Middle node
}

// Detect cycle (Floyd's algorithm)
bool hasCycle(ListNode* head) {
    if (!head) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

// Find cycle start node
ListNode* detectCycleStart(ListNode* head) {
    if (!head) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    // Find meeting point
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    if (!fast || !fast->next) return nullptr;  // No cycle

    // Find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Merge two sorted lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;

    return dummy.next;
}

// Remove nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode* first = &dummy;
    ListNode* second = &dummy;

    // Advance first pointer by n+1 steps
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    // Move both until first reaches end
    while (first) {
        first = first->next;
        second = second->next;
    }

    // Remove the nth node
    ListNode* toDelete = second->next;
    second->next = second->next->next;
    delete toDelete;

    return dummy.next;
}

// Check if palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* secondHalf = reverseList(slow->next);

    // Compare
    ListNode* p1 = head;
    ListNode* p2 = secondHalf;
    bool isPalin = true;

    while (p2) {
        if (p1->val != p2->val) {
            isPalin = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // Restore list (optional but good practice)
    slow->next = reverseList(secondHalf);

    return isPalin;
}

// ============================================
// MAIN
// ============================================

int main() {
    cout << "=== Linked Lists ===" << endl << endl;

    // Basic operations
    cout << "--- Basic Operations ---" << endl;

    ListNode* list = createList({1, 2, 3, 4, 5});
    printList(list, "Original");

    list = insertAtHead(list, 0);
    printList(list, "Insert 0 at head");

    list = insertAtTail(list, 6);
    printList(list, "Insert 6 at tail");

    list = insertAtPosition(list, 99, 3);
    printList(list, "Insert 99 at pos 3");

    list = deleteByValue(list, 99);
    printList(list, "Delete 99");

    deleteList(list);

    // Reverse
    cout << "\n--- Reverse ---" << endl;
    list = createList({1, 2, 3, 4, 5});
    printList(list, "Original");

    list = reverseList(list);
    printList(list, "Reversed");
    deleteList(list);

    // Find middle
    cout << "\n--- Find Middle ---" << endl;
    list = createList({1, 2, 3, 4, 5});
    printList(list, "List");
    ListNode* mid = findMiddle(list);
    cout << "Middle: " << mid->val << endl;
    deleteList(list);

    list = createList({1, 2, 3, 4, 5, 6});
    printList(list, "List");
    mid = findMiddle(list);
    cout << "Middle: " << mid->val << endl;
    deleteList(list);

    // Cycle detection
    cout << "\n--- Cycle Detection ---" << endl;
    list = createList({1, 2, 3, 4, 5});
    cout << "Has cycle: " << (hasCycle(list) ? "yes" : "no") << endl;

    // Create a cycle for testing
    ListNode* cycleList = createList({1, 2, 3, 4, 5});
    ListNode* tail = cycleList;
    while (tail->next) tail = tail->next;
    tail->next = cycleList->next;  // 5 -> 2 (create cycle)
    cout << "Has cycle (after creating): " << (hasCycle(cycleList) ? "yes" : "no") << endl;

    // Find cycle start
    ListNode* cycleStart = detectCycleStart(cycleList);
    cout << "Cycle starts at: " << cycleStart->val << endl;

    // Break cycle before deleting
    tail->next = nullptr;
    deleteList(cycleList);
    deleteList(list);

    // Merge sorted lists
    cout << "\n--- Merge Sorted Lists ---" << endl;
    ListNode* l1 = createList({1, 3, 5, 7});
    ListNode* l2 = createList({2, 4, 6, 8});
    printList(l1, "List 1");
    printList(l2, "List 2");

    ListNode* merged = mergeTwoLists(l1, l2);
    printList(merged, "Merged");
    deleteList(merged);

    // Palindrome check
    cout << "\n--- Palindrome Check ---" << endl;
    list = createList({1, 2, 3, 2, 1});
    printList(list, "List");
    cout << "Is palindrome: " << (isPalindrome(list) ? "yes" : "no") << endl;
    deleteList(list);

    list = createList({1, 2, 3, 4, 5});
    printList(list, "List");
    cout << "Is palindrome: " << (isPalindrome(list) ? "yes" : "no") << endl;
    deleteList(list);

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Remove all nodes with value val
     * Input: 1->2->6->3->4->5->6, val = 6
     * Output: 1->2->3->4->5
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Add two numbers represented as linked lists
     * Input: l1 = [2,4,3], l2 = [5,6,4]
     * Output: [7,0,8] (342 + 465 = 807)
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Rotate list right by k places
     * Input: 1->2->3->4->5, k = 2
     * Output: 4->5->1->2->3
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Partition list
     * Given x, partition so all nodes < x come before nodes >= x
     * Input: 1->4->3->2->5->2, x = 3
     * Output: 1->2->2->4->3->5
     */

    // YOUR CODE HERE

    return 0;
}
