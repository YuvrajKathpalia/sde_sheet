
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

//acha..doable..


 //bfs se hojega...target node se lagana shuru krenge...
 //phli iteration distance of 1 wale cover krenge left,right ki to call deni aati hai, upar ki call dene ke lie
 //kuch alag krna pdega...kya krenge phle se hi ek function bnalenge jo level order se ek map me sab nodes ke
 //parent track krlega..bas ek line extra jodni q me push krne ke sath sath..mp[curr->left]=curr..parent se map krdia..

 //bas fir wo bfs chlta rhega ...level maintain krlenge..jaise hi level k ki barabar hua..break krdenge...
 //aur q me akhir me whi nodes pde honge jo k distance pe hai...soch ke dekhlo easy h...


//o(n)..sab jagah o(n) hi ari..
//o(n)..


class Solution {
public:

void solve(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent ){
    if(root==NULL){
        return;
    }

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){

        TreeNode* curr =q.front();
        q.pop();

        if(curr->left){
            q.push(curr->left);
            parent[curr->left]=curr;
        }
         if(curr->right){
            q.push(curr->right);
            parent[curr->right]=curr;
        }     
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

    if(k==0){
        return {target->val};
    }

    //level order traversal for keeping track of parents(upar wala distance manage krne ke lie)

    unordered_map<TreeNode*,TreeNode*>parent;

    solve(root,parent);

    //ab target node pe bfs lagana hai..(upar bhi jayge , left,right bhi jayge dono distance mind me rkhna h na)

    queue<TreeNode*>q;
    q.push(target);

    unordered_map<TreeNode* , bool>visited;   //visited map bhi create krna pdega na
    visited[target]=true;

    int level=0;

    while(!q.empty()){

        int n=q.size();

        if(level==k){
            break;
        }
        level++ ;  //else.

        for(int i=0;i<n;i++){

            TreeNode* curr= q.front();
            q.pop();

            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
            }
             if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(parent[curr] && !visited[parent[curr]]){
                q.push(parent[curr]);
                visited[parent[curr]]=true;
            }
        }
    }

    //since jab level=k hogya humne tabhii break krdia...to akhri me queue me whi nodes padi hongi jo at a distance of k hai
    //from target node..

    vector<int>ans;

    while(!q.empty()){

        TreeNode* curr= q.front();
        q.pop();

        ans.push_back(curr->val);
    }


    return ans;
    
    
        
    }

};