/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


 //tc =o(n)..sc=o(1)..normal approach..

 
class Solution {


public:

int getlength(ListNode* head){

    int length = 0;
    while(head!=NULL){
        length++;
        head = head-> next;
    }
    return length;
}
    ListNode* middleNode(ListNode* head) {
        

    int length = getlength(head);
    int ans = (length)/2;

    ListNode* temp = head;
    int count = 0;
    
    while (count < ans){
        temp = temp ->next;
        count++;
    }
    return temp;

    }
};


//optimal approach..
//slow-fast pointer..(2 pointer technqiue)
//floyd cycle detection..

//agar even number of nodes hai to baad wali node return krni..


class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){

            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
        
    }
};