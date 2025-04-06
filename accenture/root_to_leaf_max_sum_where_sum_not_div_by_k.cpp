
// You are given a binary tree with N nodes where each node contains a positive integer value. The goal is to find the maximum sum path from the root to any leaf node. However, you need to ensure that the sum of the values along the path is not divisible by a given integer K.

// Input:

// The first line of input contains an integer N, the number of nodes in the tree.
// The second line contains N space-separated integers representing the values of the nodes.
// The third line contains N-1 pairs of integers u and v, representing the edges of the tree (the tree is rooted at node 1).
// The fourth line contains a single integer K, the divisor.
// Output:

// Print the maximum sum of the path from the root to any leaf node such that the sum is not divisible by K. If no such path exists, print -1.
// Input:

// 7 
//3 4 8 2 1 6 10 
//1 2 1 3 2 4 2 5 3 6 3 7 
//5

// Output:

// 21

// Explanation:

// The possible paths from the root (node 1) to the leaves are:

// 3 -> 4 -> 2 (sum = 9)
// 3 -> 4 -> 1 (sum = 8)
// 3 -> 8 -> 6 (sum = 17)
// 3 -> 8 -> 10 (sum = 21)
// The path with the maximum sum that is not divisible by 5 is 3 -> 8 -> 10, with a sum of 21.



#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

// Clean recursive function to find max sum not divisible by K
void findMaxSum(TreeNode* root, int k, int currSum, int& maxSum) {


    if (!root) return;
    
    currSum += root->val;
    
    // If leaf node, check if sum is valid
    if (!root->left && !root->right) {

        if (currSum % k != 0) {
            maxSum = max(maxSum, currSum);
        }
        return;  //base case...silly..
    }
    
    // Recurse for left and right children
    
    findMaxSum(root->left, k, currSum, maxSum);
    findMaxSum(root->right, k, currSum, maxSum);
}

int main() {
    int n;
    cin >> n;
    
    // Read values
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    // Create nodes... phle user se values leli ,un values ke node bnadiye ek ek krke loop se(vector<treeNode*> lelia)

    vector<TreeNode*> nodes(n);

    for (int i = 0; i < n; i++) {
        nodes[i] = new TreeNode(values[i]);
    }
    
    // Build tree....fir jo nodes bne usse tree banana...n-1 times loop chlega...agar 7 nodes..to 6 edges bnege na.

    for (int i = 0; i < n-1; i++) {

        int u, v;
        cin >> u >> v;

        u--; v--; // Convert to 0-based indexing...kyuki nodes vector me waise hi hai..but jo u,v (input test case se hai usme node val hai)


        // phle left check..h to left assign , ni to right..

        if (!nodes[u]->left) {
            nodes[u]->left = nodes[v];
        } else {
            nodes[u]->right = nodes[v];
        }
    }
    
    int k; //target..
    cin >> k;
    
    int maxSum = -1;

    findMaxSum(nodes[0], k, 0, maxSum); //silly..-nodes[0]..
    
    cout << maxSum << endl;
    
    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete nodes[i];
    }
    
    return 0;
}