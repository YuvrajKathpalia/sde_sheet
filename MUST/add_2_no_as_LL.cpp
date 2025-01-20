//o(max(m,n))..
//o(max(m,n))..

#include <iostream>
using namespace std;



class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the list

    Node(int data1) {   //main isi contructor ka kaam hai
        data = data1;
        next = nullptr;
    }
    
    Node(int data1,Node* next1){ //in wale questions me jha user input krvara... usme ye bhi jroori ..kyuki tail->next=newnode...ye sab to krre na
        data=data1;
        next=next1;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp =dummy;

        int carry=0;


        while(l1 || l2 || carry){

            int sum=0;

            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
             if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }

            sum += carry;
            
            carry= sum/10;

            temp->next = new ListNode(sum%10);
            temp=temp->next;  //silly..

        }

        return dummy->next;
        
    }



void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}



int main() {
    int n1, n2;

    // Input for the first linked list
    cout << "Enter the number of nodes for the first linked list: ";
    cin >> n1;

    ListNode* l1 = nullptr;  //head..
    ListNode* tail1 = nullptr;

    cout << "Enter the values for the first linked list: ";
    for (int i = 0; i < n1; i++) {
        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);
        if (l1 == nullptr) {
            l1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    // Input for the second linked list
    cout << "Enter the number of nodes for the second linked list: ";
    cin >> n2;

    ListNode* l2 = nullptr;
    ListNode* tail2 = nullptr;

    cout << "Enter the values for the second linked list: ";
    for (int i = 0; i < n2; i++) {
        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);
        if (l2 == nullptr) {
            l2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    // Print the original linked lists
    cout << "First Linked List: ";
    printList(l1);
    cout << "Second Linked List: ";
    printList(l2);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the resultant linked list
    cout << "Resultant Linked List: ";
    printList(result);

    return 0;
}