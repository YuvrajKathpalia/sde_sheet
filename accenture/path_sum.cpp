//silly
//saaf code..

//ek casesolve..abki recursion dekhlega apna..

//true/false return agar path sum..root se leaf==target...base case  , ek case solve(check for leaf)...then recursive calls-left,right..

//return left||right jha se bhi true aje..

class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum){
        
            if(root == NULL)
            {
                return false;
            }
            //leaf pe phochge..aur sum bhi targetsum ke barabar to hi true return..
            if(root->left == NULL && root->right == NULL && root->val - targetSum == 0)
            {
                return true;
            }
            
            bool left = hasPathSum(root->left,targetSum - root->val);

            bool right = hasPathSum(root->right,targetSum - root->val);
            
            return left || right;   //silly..nice
        }
    };