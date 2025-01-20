
//SILLY..FAMOUS...


 //ek odd node lelo head pe point...
 //even node lelo even pe point....
 //odd ko odd->next->next...
 //even ko even->next->next...
 //jab last odd hoyga tab usko sbse phle even se link(ek pointer rkhna shuru me even pe)...
 //while loop me even pe hi constraint lgana(as wo aage hai)...

//O(N)..
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