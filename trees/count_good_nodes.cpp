https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

//khud...easy..dfs..
//o(n)..
//o(h)...

//left ki call , right ki call..use phle value dekhlena max se jada hai to update,count++...void return function bnana(coutn ko as refrence pass krna)..


class Solution {
public:


void solve(TreeNode* root , int &count, int maxi){

    if(root==NULL){
        return;
    }

    int x=root->val;

    if(x>=maxi){
        maxi=x;
        count++;
    }

    solve(root->left,count,maxi);
    solve(root->right,count,maxi);
}
    int goodNodes(TreeNode* root) {


        int count=0;
        int maxi=INT_MIN;

        solve(root,count,maxi);

        return count;
        
    }
};