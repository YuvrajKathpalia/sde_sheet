//max depth...


//tc..o(n)...
//sc..o(h)..(worst case..o(n)...best casr..o(logn)..
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left,right)+1;

        
    }
};