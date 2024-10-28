


https://leetcode.com/problems/subtree-of-another-tree/description/


 //SAME TREE WALA LOGIC HI LGANA ..sametree wala function ki call di roots pe , 
 //agar false aya to , samefun call fir root->left,subroot , root-<right,subroot pe di... or lgake
 //khi se true ajaye to return hojayga..


//tc..o(n*m)..(wort car node of root ke lie call krna pdra sametree function)
//o(h+m)..where h is height of root tree, m is height of subtree.


class Solution {
public:

bool sametree(TreeNode* p , TreeNode* q){

    if(p==NULL && q==NULL){
        return true;
    }
    if(p==NULL || q==NULL){
        return false;
    }

    if(p->val==q->val){
        return sametree(p->left,q->left) && sametree(p->right,q->right);
    }

    return false;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root==NULL){
            return false;
        }

        if(sametree(root,subRoot)){
            return true;
        }

        return isSubtree(root->left,subRoot)  || isSubtree(root->right,subRoot);
        
    }
};