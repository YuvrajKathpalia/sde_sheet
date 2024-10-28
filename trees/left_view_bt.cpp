//APPROACH1..
//LEVEL order... 
//2d array leke level order traversal lgao.. fir loop lgado 2d array me
//aur har elemnt ka phla number uthalo bas..

//O(N)..O(N..)


vector<vector<int>> levelorder(Node* root){
    
    vector<vector<int>>result;
    
    if(root==NULL){
        return result;
    }
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        
        int n=q.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            
            Node* curr = q.front();
            q.pop();
            
            ans.push_back(curr->data);
            
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        
        result.push_back(ans);
        
    }
    
    return result;
}

vector<int> leftView(Node *root)
{
   
   vector<int>ans;
   vector<vector<int>> result = levelorder(root);
   
   for(auto x : result){
       
       ans.push_back(x.front());  //agar right view hota..to x.back() krte...
   }
   
   return ans;
   
   
}

//approach2..recursion..BASE CASE , EK CONDITION SOLVE , RECURSION CALLS..
//parametrs..vector aur level..har level se ek hi chie na..

//base case..null 

//PHLA level to root daljega..doosra level to left(agr ni to right) daljega..
//vector ka size level se ek kum to push back

//recursive calls..
//(left view me phle left ki ,rightview hota to phle right ki)

//o(n)..o(n)..


void solve(Node* root, vector<int> &ans, int level) {

if(root == NULL)
return;


if(ans.size() == level -1)
ans.push_back(root->data);


solve(root->left, ans, level+1);
solve(root->right, ans, level+1);      //call to deni hi pdegi right ki bhi..kya pta LEFT wale null ho sare...
                                       //aur ekbaar jab ans ka size jitne total level hai utna hogya..mtlb sab left
                                       //wale cover krlie... right wala satisfy hi nui hogi conditon..
}


vector<int> leftView(Node *root)

{
vector<int> ans;
solve(root, ans, 1);
return ans;
}