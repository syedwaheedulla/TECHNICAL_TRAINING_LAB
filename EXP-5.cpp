#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the maximum path sum starting from the current node
int maxPathSumHelper(TreeNode* node, int& globalMax) {
    if (node == NULL) return 0;

    // Recursively calculate the maximum path sum for the left and right subtrees
    int leftMax = max(0, maxPathSumHelper(node->left, globalMax));
    int rightMax = max(0, maxPathSumHelper(node->right, globalMax));

    // Calculate the maximum path sum with the current node
    int currentMax = node->val + leftMax + rightMax;

    // Update the global maximum path sum
    globalMax = max(globalMax, currentMax);

    // Return the maximum sum of a path starting from the current node and extending to one of its children
    return node->val + max(leftMax, rightMax);
}

// Function to return the maximum path sum of any non-empty path in the binary tree
int maxPathSum(TreeNode* root) {
    int globalMax = -2147483648; // Manually defining the minimum integer value
    maxPathSumHelper(root, globalMax);
    return globalMax;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Find and print the maximum path sum
    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    return 0;
}
