


https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

//dfs..recurssion...
//push back kro node 1d vector me ...ab fir condition lagao agar wo leaf node hai to 
//mtlb valid path bngya hai, result me jo bhi pada hai 2d vector me daaldo..
//AGAR LEAF NODE NI HAI TO LEFT,RIGHT KI CALL DEDO...AUR BAAD ME POP BACK BHI KRDENA RESULT
//ME SE BACKTRACK KRDENA MATLB...


//o(n)..
//o(n)..


class Solution {
  public:
  
  void solve(Node* root, vector<vector<int>>&ans, vector<int>&result){
      
      if(root==NULL){
          return;
      }
      
      result.push_back(root->data);
      
      if(root->left==NULL && root->right==NULL){
          ans.push_back(result);
      }
      else{
          solve(root->left,ans,result);
          solve(root->right,ans,result);
      }
      
      result.pop_back();    //backtrack..
  }
    vector<vector<int>> Paths(Node* root) {
    
      vector<vector<int>>ans;
      vector<int>result;
      
      solve(root,ans,result);
      
      return ans;
      
      
    }
};
