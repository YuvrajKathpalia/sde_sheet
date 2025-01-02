
//approach1 ..recursive..simple///

//acha..length calculate krli...agar k >length tab to revrse possible ni head return krdo...

//whi iterative loop chlao prev,curr,forward wala jaise reverse ll me chlate ho...
//sath me count pointer bhi maintain krte rhna count<k  rhna chiye....

//jab loop se bahar aaoge tab 1 group reverse hua wa milega...
//baaki bache hue part ko recurssion sambhal lega..

//tc..o(n) hi bnegi overall.. o(n)+ k*n/k==o(n)..
//sc...o(n/k)..in worst case when k=1...sc=o(n)..


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL || k==1){
            return head;
        }

        int length=0;
        ListNode* temp= head;

        while(temp!=NULL){
            length++;
            temp=temp->next;
        }

        if(k>length){
            return head;
        }

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward= NULL;

        int count=0;

        while(curr!=NULL && count<k){
          
          forward=curr->next;
          curr->next=prev;

          prev=curr;
          curr=forward;

          count++;
        }

//12345,k=3.... 321 reverse hogye..(1 head hai , 3 prev , 4 forward)..head->next = call(forward,k)...

        if(forward!=NULL){ 
            head->next= reverseKGroup(forward,k);     
        }

        return prev;
        
    }
};



 //approach2.. BETTER...
 //STACK...

 //TC...O(N)HI AYGI.. O(N)+ O(K*N/K)..PUSH ,POP HI TO HORA ANDAR...NESTED LOOP NI H YE..

 //SC...O(K)..STACK KI (EKBARI ME K ELEMENTS HI TO H STACK ME)..BETTER HOGYI.O(N) KE COMPARISON ME...

//  The approach reverses nodes in groups of size \(k\)
//   using a stack. It traverses the list in chunks, 
//   pushing \(k\) nodes onto the stack and then popping
//    them in reverse order. If fewer than \(k\) nodes remain,
//     they are left as is.



class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL || k==1){
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next= head;

        ListNode* curr= head;
        ListNode* prev=dummy;

        while(true){

            int count=0;

            ListNode* temp=curr;

            for(int i=0; i<k && temp!=NULL ;i++){

                temp=temp->next;
                count++;
            }

            if(count<k){
                prev->next=curr;
                break;
            }

            stack<ListNode*>st;

            for(int i=0;i<k;i++){
                st.push(curr);
                curr=curr->next;
            }

            while(!st.empty()){

                prev->next=st.top();
                st.pop();
                prev=prev->next;

            }

            prev->next=curr;
        }


        return dummy->next;

    }
};