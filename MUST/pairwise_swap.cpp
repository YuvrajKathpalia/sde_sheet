https://leetcode.com/problems/swap-nodes-in-pairs/

//silly..acha ..imp..

 //Input: head = [1,2,3,4]

// Output: [2,1,4,3]
//1 aur 2 ko apas me swap , 3 aur 4 ko apas me swap...


//recursion se hoga obvio..jo 1,2 me hora whi 3,4 me and vice versa..

//do nodes lena,root,aur uska agla...
//.bas 1 ko humne 4 se connect krna...(mtlb ki curr->next=solve(curr->next->next)..)mtlb 1 ko 3 ke function return se..
//aur 2 ko ek se krna wo to simple...

//o(n/2)==o(n)...each recurisve call next ke next wale pe lagri to lagbhg adhi calls aygi..
//o(n/2)==o(n)...recuive call stack waali..

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL){  //phle call likho fir base socho..
            return head;
        }

        ListNode* temp1 = head;
        ListNode* temp2= head->next;


        temp1->next=swapPairs(temp1->next->next);
        temp2->next=temp1;

        return temp2;
        
    }
};


//optimal..iterative...

//o(n)...o(1)..


class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
    
            if(head==NULL || head->next==NULL){
                return head;
            }
    
            ListNode* curr=head;
            ListNode* prev= NULL;
            ListNode* forward=NULL;
            ListNode* second=NULL;
    
            ListNode* newhead = head->next;
    
    
            while(curr && curr->next){
    
                 forward=curr->next->next;
                 second=curr->next;
    
                 curr->next=forward;
                 second->next=curr;
    
                 if(prev!=NULL){
                    prev->next=second;
                 }
                 
                 prev=curr;
                 curr=forward;
    
            }
            return newhead;
        }
    };