https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

//easy..silly..khud...


//dfs...recursive call.....left se jo sum ara + right se jo sum..
//condition..aagr leaf node to wha tk ka sum return...
//base case...nul node to 0 return,...

//o(n)..
//o(h)...


class Solution {
  public:
  
  
  int solve(Node* root , int value){
      
      if(root==NULL){
          return 0;
      }
      
      int sum = value*10 + root->data;
      
      if(root->left==NULL && root->right==NULL){
          return sum;
      }
      
      return solve(root->left,sum)+solve(root->right,sum);
      
  }
  
  
    int treePathsSum(Node *root) {
        
        return solve(root,0);
        
        
    }
};
