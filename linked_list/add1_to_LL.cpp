//o(n+n+n)..
//o(n)..(of creating nodes)...


class Solution {
  public:
  
  
  Node* reverse(Node* head){
      
      
      Node* curr=head;
      Node* prev=NULL;
      Node* forward=NULL;
      
      while(curr!=NULL){
          
          forward=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forward;
      }
      
      return prev;
  }
  
    Node* addOne(Node* head) {
        
       
       head=reverse(head);
       
       
       Node* dummy = new Node(-1);
       Node* temp =dummy;
       
       
       int carry=1;
       
       
       while(head || carry){
           
           int sum = (head?  head->data :0) + carry;
           
           carry=sum/10;
           
           temp->next= new Node(sum%10);
           temp=temp->next;
           
           if(head!=NULL){   //ye na kre segmentation fault araa tha..
              head=head->next;
           }
           
       }
       
       Node* reversed = reverse(dummy->next);
       
       return reversed;
       
    }
};