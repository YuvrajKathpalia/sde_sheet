//brute force..hashmap....o(n)..o(n)..

//dono complexity..o(n)
//approach 1 using hashmap..


class Solution {
public:
    bool hasCycle(ListNode *head) {

unordered_map <ListNode*, int> count;   //silly..int ,int thodi...

ListNode* temp =head;

while(temp !=NULL){
    //agar equal hogya..to bahar aake false krdo..
    count[temp]++;

    if(count[temp]>1){
        return true;
    }
    temp = temp ->next;

 
}
return false;
        
        
    }
};




// The solution uses the **Floyd’s Tortoise and Hare** algorithm
//  to detect a cycle in a linked list. A fast pointer (moves two steps) 
//  and a slow pointer (moves one step) traverse the list. 
//  If a cycle exists, the two pointers will eventually meet; otherwise, the fast pointer reaches the end.



 

 //optimal..(flloyd detection..)
 //o(n/2)...o(1)...
 
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* fast = head;
        ListNode* slow= head;

        while(fast!=NULL && fast->next!=NULL){

            fast=fast->next->next;
            slow=slow->next;

            if(slow==fast){
                return true;
            }

        }
     
       return false;
    }
};