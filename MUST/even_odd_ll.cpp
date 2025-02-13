
//SILLY..FAMOUS...


 //ek odd node lelo head pe point...
 //even node lelo even pe point....
 //odd ko odd->next->next...
 //even ko even->next->next...
 //ye krne se 2 alg list bnjaygi..

 //jab even last ya null pe phoch jaye while loop tod dena..aur odd jha pe hoga us time usko shuru wale
 //even head se link krdena...(ek pointer rkhna save krke even head ke equal shuru me..)


//O(N/2)==o(N)....
//O(1)...


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {


        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* odd = head;
        ListNode* even =head->next;

        ListNode* evenhead= even;


        while(even!=NULL && even->next!=NULL){

            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }

        odd->next=evenhead;

        return head; //odd mt return krdena wo to lat pe phochadia na...
        
        
    }
};