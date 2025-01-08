//BRUTE...JHA BHI COUNT>1 HOGYA(USEMAP)...(FOR DETECT CYCLE QUESTION SET LELENA....KOI BHI REPEATED ELEMNT AYA TO PTA CHLEJEGA)

//approach1..brute force...hashmap.. jaha count>1 agya..wo node return 
//o(n)..o(n)..

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {

//         unordered_map<ListNode* , int> count;


// if (head == NULL || head->next == NULL) {
//     return NULL; 
// }
        
        
//         ListNode* temp = head;  

//         while(temp!=NULL){
            

//             count[temp]++;
//             if(count[temp]>1){

//                 return temp;
//             }
//             temp = temp ->next;
//         }

//         return NULL; //no cycle...

//     }
// };


//optimal..flloyd detection..ye approach array me bhi lagkegi.refer to..
//https://leetcode.com/problems/find-the-duplicate-number/submissions/1367738396/

//o(n)..
//o(1)..

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

       ListNode* slow= head;
       ListNode* fast = head;

       while(fast!=NULL && fast->next!=NULL){

          fast=fast->next->next;
          slow=slow->next;
       
       if(slow==fast){    //intersection point..(NOW WE KNOE CYCLEEXISTS)...
         
         slow= head;
       

       while(slow!=fast){

        slow=slow->next;
        fast=fast->next;
       }
       return slow; //or fast..
       }
    }

       return NULL;

    }
};