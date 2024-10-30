
https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//khud..easy..o(n)..o(H)..(level order se bhi hojega)..(level order lgao
//fir loop lgao 2d array me jis jis vector ka size usme 1 hai, wo ek vector me store krlo)
//sort krlena..


void solve(Node* root, vector<int>& ans) {
    if (root == NULL) {
        return;
    }


    if (root->left == NULL && root->right != NULL) {
        ans.push_back(root->right->data);
    }
   
    else if (root->right == NULL && root->left != NULL) {
        ans.push_back(root->left->data);
    }

    // left and right subtrees ki call
    solve(root->left, ans);
    solve(root->right, ans);
}



vector<int> noSibling(Node* node) {
    
    vector<int> ans;
    
    solve(node, ans);
    
    if(ans.empty()){
        return {-1};
    }
    sort(ans.begin(),ans.end());  //sorted me chayie...
    
    return ans;
}