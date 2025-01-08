

//inorder lgao dono trees pe...do vectormilgye..

//fir dono vector ko merge krdoo jaie merge sort me krte the...

//bas fir final vector return krdo...agar bst maange final..to sorted array..ya fir inorder... to bst bhi hume..mid nikalke 
//ata hi hai...neeche derkha wo bhi...


// m+n
// m+n


#include <iostream>
#include <vector>
using namespace std;

// Define the structure of a Node for the Binary Search Tree (BST)
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // In-order traversal to get the elements in sorted order
    void inorder(Node* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    // Merge two sorted arrays
    vector<int> mergeArray(const vector<int>& bst1, const vector<int>& bst2) {
        int i = 0, j = 0, k = 0;
        vector<int> ans(bst1.size() + bst2.size());

        // Merge the two arrays using two-pointer technique
        while (i < bst1.size() && j < bst2.size()) {
            if (bst1[i] < bst2[j]) {
                ans[k++] = bst1[i++];
            } else {
                ans[k++] = bst2[j++];
            }
        }
        // Add remaining elements of bst1, if any
        while (i < bst1.size()) {
            ans[k++] = bst1[i++];
        }
        // Add remaining elements of bst2, if any
        while (j < bst2.size()) {
            ans[k++] = bst2[j++];
        }

        return ans;
    }

    // Main function to merge two BSTs
    vector<int> merge(Node* root1, Node* root2) {
        vector<int> bst1, bst2;

        // Get sorted elements of the first tree
        inorder(root1, bst1);
        // Get sorted elements of the second tree
        inorder(root2, bst2);

        // Merge the two sorted arrays
        return mergeArray(bst1, bst2);
    }
};

// Helper function to insert a node into a BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to print the elements of the vector
void printVector(const vector<int>& vec) {
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    
    // Inserting elements in first BST
    root1 = insert(root1, 5);
    root1 = insert(root1, 3);
    root1 = insert(root1, 7);
    root1 = insert(root1, 2);
    root1 = insert(root1, 4);
    
    // Inserting elements in second BST
    root2 = insert(root2, 10);
    root2 = insert(root2, 8);
    root2 = insert(root2, 12);
    root2 = insert(root2, 9);

    Solution sol;
    
    // Merging two BSTs and getting the sorted list
    vector<int> result = sol.merge(root1, root2);
    
    // Printing the result
    printVector(result);

    return 0;
}



//INORDER TO BST..OR SAY...SORTED ARRAY TO BST..

//khud
 //mtlb ek treeke se inorder to bst puchre...inorder to balanced bst hume ata
 //mid nikalke jo krte whi krdete hh

//  O(n) because each node is visited once and constructing the tree involves processing each element of the array exactly once.
//  Space Complexity: O(n) (including the recursion stack and storage for the tree nodes).

//WSE TO BALANCED TREE ME SPACE..LOGN HONA CHIE...WORST CASE..SKEWED TREE ME SPACE...N

class Solution {
public:

TreeNode* solve(int s, int e ,vector<int>& nums ){

        if(s>e){
            return NULL;
         }
       
       int mid = (s+e)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(s,mid-1,nums);
        root->right = solve(mid+1 ,e , nums);

        return root;


}
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int s=0;
        int e =nums.size()-1;


       
        return solve(s,e,nums);

       
        
    }
};