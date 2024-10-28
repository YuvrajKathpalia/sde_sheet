
//tc-..if same trres- o(m) or o(n)..if not..- min(o(m,n))..
//sc..similalrly sc..


https://leetcode.com/problems/same-tree/description/

//tc-..if same trres- o(m) or o(n)..if not..- min(o(m,n))..
//sc..similalrly sc..

 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL && q==NULL){
            return true;
        }
        
        if(p==NULL || q==NULL){  //agar dono me se koi ek null , doosra null ni
            return false;
        }

        if(p->val==q->val){
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }

        
        return false;


    }
};