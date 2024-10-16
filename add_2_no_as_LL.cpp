#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = 0;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
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

ListNode* createListFromInput() {
    cout << "Enter the elements of the linked list (space-separated, -1 to end): ";
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int value;

    while (true) {
        cin >> value;
        if (value == -1) {
            break; // -1 indicates end of input
        }

        ListNode* newNode = new ListNode(value);
        if (head == NULL) {
            head = newNode; // Initialize the head if it's NULL
            tail = head;    // Initialize tail
        } else {
            tail->next = newNode; // Link new node at the end
            tail = newNode;       // Move tail pointer
        }
    }

    return head;
}

int main() {
    // Create first linked list
    cout << "Create first linked list:\n";
    ListNode* l1 = createListFromInput();

    // Create second linked list
    cout << "Create second linked list:\n";
    ListNode* l2 = createListFromInput();

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    std::cout << "Result: ";
    printList(result);
    
    return 0;
}


// struct ListNode defines a new structure type named ListNode. In C++, a struct is similar to a class but defaults to public access for its members.
