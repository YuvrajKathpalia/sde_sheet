
 //o(n)..
 //o(n)..

 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {


        vector<vector<int>>result;

        if(root==NULL){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int n=q.size();
            vector<int>ans;

            for(int i=0; i<n;i++){

                TreeNode* front = q.front();
                q.pop();

                ans.push_back(front->val);

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }                                  
           }
             
             result.push_back(ans);

        }

         return result;

         
        
    }
};