

https://leetcode.com/problems/binary-tree-maximum-path-sum/

//acha..concept clearing..similar to diameter...

//call krenge function , maxi maintain krenge ek...
//maxi =max(maxi , root->val+ leftsum + rightsum ).. equation yhi bnegii we know..har node pe max path sum issi se niklega...

//leftsum , rightsum me left,right ki call dedenge(-ve wala case bhi handle krna pdega aur koi left/right node -ve return krri usse consider hi ni krenge 0 maanlenge..)...

//aur jab function me andar return krni ki baat aygi tab path sum bhejna hai na.. tab root->val + leftsum/rightsum me se jo max hoga(leftsum+rightsum thodi bhejge..bahr se koi path ara
//tab dono thodi consider krskte hai)...obvio dry run krke dekhlo example 2..(9 se 15 hi to jaskta na possible path)(silly)

//o(n)..
//o(n)...


class Solution {
public:

int solve(TreeNode* root , int& maxi){

    if(root==NULL){
        return 0;
    }

    int leftsum = max(0 ,solve(root->left,maxi));   //agar neagtive sum ara..to consider ni krenge...
    int rightsum =max(0,solve(root->right,maxi));

    maxi = max(maxi , root->val+leftsum+rightsum);

    return max(leftsum,rightsum)+root->val;
}
    int maxPathSum(TreeNode* root) {

        int maxi=INT_MIN;
        solve(root,maxi);

        return maxi;
        
    }
};