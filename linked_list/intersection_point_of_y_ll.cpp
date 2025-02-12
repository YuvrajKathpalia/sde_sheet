
 ////o(n)..o(1)..
// phle to length ka differnce barabar krna pdega obvio..jitna diff utna uske had ko age leaao..
//fir loop chlao agar head same hai to return krdo..

class Solution {
public:

int lengthh(ListNode* node){

    ListNode* temp = node;

    int length=0;

    while(temp!=NULL){
        length++;
        temp=temp->next;
    }

    return length;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int lenA = lengthh(temp1);
        int lenB = lengthh(temp2);

        if(lenA < lenB){

            while(lenA!=lenB){

                lenB--;
                temp2=temp2->next;
            
            }
        }

        else if(lenB < lenA){

            while(lenA!=lenB){

                lenA--;
                temp1=temp1->next;
            
            }
        }

        

        while(temp1!=NULL && temp2!=NULL){

            if(temp1==temp2){
                return temp1; //or temp2;
            }

            temp1=temp1->next;
            temp2=temp2->next;
        }

        return NULL;
        
    }
};
