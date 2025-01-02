
#include <iostream>
using namespace std;

// Node class represents a node in a linked list

class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the list

    Node(int data1) {   //main isi contructor ka kaam hai
        data = data1;
        next = nullptr;
    }
    
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    Node* curr = head;  
    Node* prev = NULL; 
    Node* forward = NULL;

    while (curr != NULL) {  
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;  
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n; // Number of nodes in the linked list
    cout << "Enter the number of nodes: ";
    cin >> n;

   

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter the values for the linked list: ";
    
    
    for (int i = 0; i < n; i++) {
        
        int value;
        cin >> value;

        Node* newNode = new Node(value);
        
        
        if (head == nullptr) {
            // Initialize the head and tail
            head = newNode;
            tail = newNode;
        } 
        
        else {
            // Append to the linked list
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
