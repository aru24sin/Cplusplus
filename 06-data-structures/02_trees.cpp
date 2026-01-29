/**
 * Data Structures: Binary Trees
 *
 * Trees appear in MANY LeetCode problems.
 * Master traversals and recursive thinking.
 *
 * Compile: g++ -std=c++17 -o 02_trees 02_trees.cpp
 * Run: ./02_trees
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

// ============================================
// TREE NODE DEFINITION
// ============================================

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// ============================================
// HELPER FUNCTIONS
// ============================================

// Create tree from level order (use -1 for null)
TreeNode* createTree(const vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < nums.size() && nums[i] != -1) {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < nums.size() && nums[i] != -1) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// Delete tree
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Print level order
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "Empty tree" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "| ";
    }
    cout << endl;
}

// ============================================
// TREE TRAVERSALS
// ============================================

// Inorder: Left -> Root -> Right (BST gives sorted order)
void inorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

// Preorder: Root -> Left -> Right
void preorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

// Postorder: Left -> Right -> Root
void postorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

// Level order (BFS)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(level);
    }

    return result;
}

// Iterative inorder using stack
vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* current = root;

    while (current || !stk.empty()) {
        // Go left as far as possible
        while (current) {
            stk.push(current);
            current = current->left;
        }

        // Process node
        current = stk.top();
        stk.pop();
        result.push_back(current->val);

        // Move to right subtree
        current = current->right;
    }

    return result;
}

// ============================================
// COMMON TREE ALGORITHMS
// ============================================

// Height of tree
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Number of nodes
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if balanced (height difference <= 1)
int checkBalance(TreeNode* root) {
    if (!root) return 0;

    int left = checkBalance(root->left);
    if (left == -1) return -1;

    int right = checkBalance(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    return checkBalance(root) != -1;
}

// Maximum path sum
int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if (!root) return 0;

    // Get max contribution from left and right (ignore negative)
    int left = max(0, maxPathSumHelper(root->left, maxSum));
    int right = max(0, maxPathSumHelper(root->right, maxSum));

    // Update global max (path through current node)
    maxSum = max(maxSum, left + right + root->val);

    // Return max contribution for parent
    return max(left, right) + root->val;
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

// Lowest Common Ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;  // p and q are in different subtrees
    return left ? left : right;
}

// Check if same tree
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

// Check if symmetric
bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return left->val == right->val &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// Invert binary tree
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

// ============================================
// BINARY SEARCH TREE OPERATIONS
// ============================================

// Search in BST
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

// Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Validate BST
bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

// ============================================
// MAIN
// ============================================

int main() {
    cout << "=== Binary Trees ===" << endl << endl;

    // Create a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    TreeNode* root = createTree({1, 2, 3, 4, 5, -1, 6});

    cout << "--- Tree Structure ---" << endl;
    cout << "Level order: ";
    printLevelOrder(root);

    // Traversals
    cout << "\n--- Traversals ---" << endl;

    vector<int> result;

    inorder(root, result);
    cout << "Inorder: ";
    for (int v : result) cout << v << " ";
    cout << endl;

    result.clear();
    preorder(root, result);
    cout << "Preorder: ";
    for (int v : result) cout << v << " ";
    cout << endl;

    result.clear();
    postorder(root, result);
    cout << "Postorder: ";
    for (int v : result) cout << v << " ";
    cout << endl;

    auto levels = levelOrder(root);
    cout << "Level order by level: ";
    for (const auto& level : levels) {
        cout << "[";
        for (int v : level) cout << v << " ";
        cout << "] ";
    }
    cout << endl;

    // Properties
    cout << "\n--- Tree Properties ---" << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Node count: " << countNodes(root) << endl;
    cout << "Is balanced: " << (isBalanced(root) ? "yes" : "no") << endl;

    // BST operations
    cout << "\n--- BST Operations ---" << endl;

    //        4
    //       / \
    //      2   6
    //     / \ / \
    //    1  3 5  7

    TreeNode* bst = createTree({4, 2, 6, 1, 3, 5, 7});
    cout << "BST level order: ";
    printLevelOrder(bst);

    cout << "Is valid BST: " << (isValidBST(bst) ? "yes" : "no") << endl;

    result.clear();
    inorder(bst, result);
    cout << "BST inorder (sorted): ";
    for (int v : result) cout << v << " ";
    cout << endl;

    TreeNode* found = searchBST(bst, 5);
    cout << "Search for 5: " << (found ? "found" : "not found") << endl;

    // Other algorithms
    cout << "\n--- Other Algorithms ---" << endl;
    cout << "Max path sum: " << maxPathSum(root) << endl;
    cout << "Is symmetric: " << (isSymmetric(root) ? "yes" : "no") << endl;

    // Symmetric tree test
    TreeNode* symTree = createTree({1, 2, 2, 3, 4, 4, 3});
    cout << "Symmetric tree test: " << (isSymmetric(symTree) ? "yes" : "no") << endl;

    // Cleanup
    deleteTree(root);
    deleteTree(bst);
    deleteTree(symTree);

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Flatten binary tree to linked list (in-place)
     * The "linked list" should use the right pointer
     * Input:     1          Output: 1
     *           / \                  \
     *          2   5       ->         2
     *         / \   \                  \
     *        3   4   6                  3
     *                                    \
     *                                     4
     *                                      \
     *                                       5
     *                                        \
     *                                         6
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Construct binary tree from preorder and inorder traversal
     * preorder = [3,9,20,15,7]
     * inorder = [9,3,15,20,7]
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Serialize and deserialize binary tree
     * Implement two functions:
     * string serialize(TreeNode* root)
     * TreeNode* deserialize(string data)
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Find kth smallest element in BST
     * Input: root = [3,1,4,null,2], k = 1
     * Output: 1
     */

    // YOUR CODE HERE

    return 0;
}
