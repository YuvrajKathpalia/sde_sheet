//length-n-1 (delete wali se peeche wali) tak phoch jao...
 //fir...curr->next ko delete krdena aur.... curr->next=curr->next->next... agli wali se link...
 //return head..

 //edge case..if n=length..mtlb head remove krna..to ListNode* newhead =head->next..delete head...aur return newhead..

 //o(n)..
 //o(1)..

 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length=0;

        ListNode* temp= head;

        while(temp!=NULL){

            length++;
            temp=temp->next;
        }


//handle edge case..head hi delete krna hai jab..

         if (n == length) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }


        int count=0;
        ListNode* curr=head;

        while(count!=length-n-1){

            curr =curr->next;
            count++;
        }

        ListNode* deletewali = curr->next;

        curr->next=curr->next->next;
        delete(deletewali);

        return head;


        
    }
};