//o(n+n+n)..
//o(n)..(of creating nodes)...


class Solution {
  public:
  
  
  Node* reverse(Node* head){
      
      Node* curr=head;
      Node* prev=NULL;
      Node* forw =NULL;
      
      while(curr!=NULL){
          forw=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forw;
      }
      
      return prev;
  }
    Node* addOne(Node* head) {
        
        
        Node* newhead = reverse(head);
        
        
        Node* dummy  = new Node(-1);
        Node* temp = dummy;
        
        Node* curr= newhead;
        
        int carry=1;
        
        
        while(curr!=NULL || carry!=0){
            
            
            int sum = (curr? curr->data : 0)+carry;   //carry last me 1 rehbhi jega tab bhi chlega ye...
            
            temp->next= new Node(sum%10);
            temp=temp->next;
            
            carry=sum/10;
            
            if(curr!=NULL){
                curr=curr->next;
            }
            
        }
        
        Node* resultHead = reverse(dummy->next);
        
        return resultHead; 
        
    }
};