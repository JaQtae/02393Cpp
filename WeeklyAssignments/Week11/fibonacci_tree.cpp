#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int value; //  F(n)
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to build the Fibonacci tree
TreeNode* buildFibonacciTree(int n) {
    if (n == 0 || n == 1) {
        return new TreeNode(1); // Base cases: F(0) = 1, F(1) = 1
    }
    // I had swapped them around... oops
    TreeNode* rightSubtree = buildFibonacciTree(n - 2); // Recursively build left and right subtrees for F(n-2) and F(n-1), respectively
    TreeNode* leftSubtree = buildFibonacciTree(n - 1);
    TreeNode* node = new TreeNode(leftSubtree->value + rightSubtree->value); // F(n) = F(n-2) + F(n-1)
    node->left = leftSubtree;
    node->right = rightSubtree;
    return node;
}

void preOrderTraversal(TreeNode* node, vector<int>& values) {
    if (!node) return; // Base case: empty tree
    values.push_back(node->value);  // Parent node
    preOrderTraversal(node->left, values); // Left child of parent node
    preOrderTraversal(node->right, values); // Right child of parent node
}

int calculateSize(TreeNode* node) {
    if (!node) return 0; // Base case
    return 1 + calculateSize(node->left) + calculateSize(node->right); // root + left subtree + right subtree
}

int calculateDepth(TreeNode* node) {
    if (!node) return -1; // Base case: Depth of an empty tree is -1
    return 1 + max(calculateDepth(node->left), calculateDepth(node->right));
}

int countLeaves(TreeNode* node) {
    if (!node) return 0; // Base case: empty tree
    if (!node->left && !node->right) return 1; // Base case: leaf node found
    return countLeaves(node->left) + countLeaves(node->right);
}

int main() {
    int n; // Fibonacci number to calculate for
    cin >> n;
    if (n < 0) return 0;  // End if negative input.

    TreeNode* root = buildFibonacciTree(n);

    // Pre-order traversal
    vector<int> preOrderValues;
    preOrderTraversal(root, preOrderValues);

    cout << "Call tree in pre-order: ";
    for (int val : preOrderValues) {
        cout << val << " ";
    }
    cout << endl;

    // Tree metrics
    cout << "Call tree size: " << calculateSize(root) << endl;
    cout << "Call tree depth: " << calculateDepth(root) << endl;
    cout << "Call tree leafs: " << countLeaves(root) << endl;

    return 0;
}