 //brute..force..stack..o(2*n)..o(n)..
//..sc,,o(n)..

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {

//          stack<int> st;

//     ListNode* temp = head;

    
//     while (temp != NULL) {
          
//         st.push(temp->val);        
//         temp = temp->next;  
//     }

    
//     temp = head;

    
//     while (temp != NULL) {
//         if (temp->val != st.top()) {
                   
//             return false; 
//         }
           
//         st.pop();         
//        temp = temp->next; 
//     }

    
//     return true;
// }
        
    
// };

 //optimal..
 //middle nikalo ..middle ke baad wala reverse krdo..
 //fir dono ko compare krwado..
//..O(N)..O(1)..


class Solution {
public:


  ListNode* reverse(ListNode* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* forward=NULL;

    while(curr!=NULL){

        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }

    return prev;
  }



   bool isPalindrome(ListNode* head) {

    if(head==NULL || head->next==NULL){
        return head;
    }

    //middle nikalo..

    ListNode* fast=head;
    ListNode* slow=head;


//JO MIDDLEWALA QUESTION THA(UMS ELIKHRKHA THA EVEN LIST HAI TO DOOSRA WALA RETURN KRO..ISME TO
//PHLA WALA HI CHAYIE ISLLYE YE KARA..)
    while(fast->next!=NULL && fast->next->next!=NULL){

        fast=fast->next->next;
        slow=slow->next;

    }



    ListNode* new_head = reverse(slow->next);

    ListNode* temp=head;


    while(new_head!=NULL){

        if(temp->val!=new_head->val){
            return false;
        }
        temp=temp->next;
        new_head=new_head->next;
    }


    return true;

     
    }
};