https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

//acha..famous..silly..doable..

//1)traverse left boundary...(phle leftki call agr ni to right ki call).(usme leaf mt calculate krna last wali)
//2)fir traverse leaf nodes saari..(aata hume)
//3)traverse right boundary..... ab left boundary aur sari leaf nodes hogyi abb right boudary chiyee
// but ulti chiyee na to usme phle calls krenge fir push back last me taki wo last se phochke hi shuru kre...

//mtlb leftnoundary me preorder traversal ,rightboundary me postorder traversal
//aur leaves print krvana hume aata hi hai..ek condition check aur 2 rec calls


//o(n)..
//o(n)..

class Solution {
public:


void leftboundary(Node* root, vector<int>&ans){
    
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    
    ans.push_back(root->data);
    
    if(root->left){
        leftboundary(root->left,ans);
    }
    
    else{
        leftboundary(root->right,ans);
    }
}


void rightboundary(Node* root, vector<int>&ans){
    
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    
    
    if(root->right){
        rightboundary(root->right,ans);
    }
    
    else{
        rightboundary(root->left,ans);
    }
    
    ans.push_back(root->data);
}


void leaves(Node* root, vector<int>&ans){
    
    if(root==NULL){
        return;
    }
    
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    
    leaves(root->left,ans);
    leaves(root->right,ans);
    
}

    vector <int> boundary(Node *root)
    {
      
      vector<int>ans;
      
      if(root==NULL){
          return ans;
      }
      
      ans.push_back(root->data);
      
      leftboundary(root->left,ans);
      
      leaves(root->left,ans);
      leaves(root->right,ans);
      
      rightboundary(root->right,ans);
      
      return ans;
    }
};