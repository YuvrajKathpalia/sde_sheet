//ek booolean aur index maintain krlena..
//agr left to right ki turn to seedha seedha result[index] = curr->val..
//else...result[n-i-1] hojega..


 //o(n)..
 //o(n)
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>ans;

        queue<TreeNode*>q;
        q.push(root);

        if(root==NULL){
            return ans;
        }
        

        bool leftToright=true;

        while(!q.empty()){

            int n=q.size();
            vector<int>result(n);

            for(int i=0;i<n;i++){

                TreeNode* curr= q.front();
                q.pop();

                int index=i;

                if(leftToright){
                    index=i;
                }
                else{
                    index=n-i-1;
                }

                result[index]=curr->val;  


                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

                
            }

            leftToright = !leftToright;
            ans.push_back(result);
        }

        return ans;
        
    }
};