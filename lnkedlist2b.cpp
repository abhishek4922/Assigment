//Insert an element in a linked list in sorted order.
#include <iostream>
using namespace std;

// Node class
class Node5 {
public:
    int val;
    Node5* next;

    Node5(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

void insert_sorted(Node5** head, Node5* element) {
    if (*head == nullptr || element->val < (*head)->val) {
        element->next = *head;
        *head = element;
        return;
    }

    Node5* current = *head;
    while (current->next != nullptr && current->next->val < element->val) {
        current = current->next;
    }

    element->next = current->next;
    current->next = element;
}

void pList(Node5* head) {
    Node5* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node5* head = nullptr;
    int n;
    cout<<"Enter the total number of element in the linked list:"<<" ";
    cin>>n;
    int a[n];
    for(int i=0 ;i<n ;++i){
        cout<<"Enter the value of :"<<" ";
        cin>>a[i]; 
        insert_sorted(&head, new Node5(a[i]));
    }
    pList(head); 

    return 0;
}