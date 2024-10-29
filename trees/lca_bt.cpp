
 //o(n)..
 //o(h)....
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL && right == NULL) {
            return NULL;
        }
        else if (left == NULL) {
            return right;
        }
        else if (right == NULL) {
            return left;
        }
         
       else{         //dono non null..dono jgh se value aari ..mtlb yhi lca node hai..node return krdo.
        return root;
       }
    }
};


