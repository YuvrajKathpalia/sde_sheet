//optimal..yhi approach..

 //left ki call denge , right ki call denge...
 //har point pe dimater update krte jayge..max chayie na ..

 //diamter will be left+right at any node..(distance)...jaise example 1 me..1,2,3,4,5 me...
 //1 ke lie left height nikal aayi 2,right height 1.. to left+right =3...to bas yhi krna...

 //jo hum height wale function me krte the whi krenge, diamter update krte rhenge ...

//  The logic behind this solution revolves around calculating the diameter of a binary tree by determining the longest path between any two nodes. The key steps are:

// For each node, calculate the height of its left and right subtrees.
// Update the diameter by considering the sum of the heights of the left and right subtrees at that node (this gives the longest path through that node).
// Use recursion to visit every node, updating the diameter along the way.
// Return the maximum diameter after all nodes are processed.
// This approach efficiently calculates the diameter in a single traversal (O(N)) of the tree.

//o(n)..
//o(n)..

class Solution {
public:


int calculateheight(TreeNode* root,int& diameter){

    if(root==NULL){
        return 0;
    }

    int left = calculateheight(root->left,diameter);
    int right=calculateheight(root->right,diameter);

    diameter = max(diameter , left+right);

    return 1+max(left,right);
}


    int diameterOfBinaryTree(TreeNode* root) {

        int diameter=0;
        calculateheight(root,diameter);


        return diameter;
        
    }
};