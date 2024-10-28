
https://leetcode.com/problems/balanced-binary-tree/description/


 //similar to how we handled diamter of bt...
 //jaise height calculate krte...whi function pass krdenge.. aur ek bool variable as refrence pass krdege
 //har point pe wo left,riight subtree ka height ka differnecce nikalega..aur >1 hua to false..warna true hi...

// The intuition behind this solution is to recursively calculate the height of the left and right subtrees while checking if their height difference exceeds 1 at any node. If it does, mark the tree as unbalanced and return the result.

 //o(n)..
 //o(n)....


class Solution {
public:

int height(TreeNode* root ,bool& balanced){

    if(root==NULL){
        return 0;
    }

    int left = height(root->left,balanced);
    int right =height(root->right,balanced);

    if(abs(left-right)>1){
        balanced=false;
    }


    return 1+ max(left,right);
}
    bool isBalanced(TreeNode* root) {

        bool balanced= true;

        height(root,balanced);

        return balanced;
        
    }
};