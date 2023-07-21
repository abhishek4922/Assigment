#include <iostream>
using namespace std;

// Node class
class Node2 {
public:
    int val;
    Node2* next;

    Node2(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node2* head;

public:
    LinkedList() {
        this->head = nullptr;
    }

    void insertAtEnd(int val) {
        Node2* newNode = new Node2(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node2* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

// Concatenate two lists into one
Node2* concatenate(Node2* head1, Node2* head2) {
    if (head1 == nullptr) {
        return head2;
    }

    Node2* temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = head2;
    return head1;
}

// Print the elements of a list
void pList(Node2* head) {
    Node2* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    LinkedList list1;
    LinkedList list2;

    cout << "Create List one:" << endl;
    cout << "total number of elements in list1: ";
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "enter the value of list1: ";
        cin >> a[i];
        list1.insertAtEnd(a[i]);
    }

    cout << "\nCreate List two:" << endl;
    cout << "total  number of elements in list 2: ";
    int m;
    cin >> m; 
    int b[m];
    for (int i = 0; i < m; i++) {
        cout << "enter the value of the list2: ";
        cin >> b[i];
        list2.insertAtEnd(b[i]);
    }

    // Concatenate the lists
    Node2* concatenatedHead = concatenate(list1.head, list2.head);

    // Print the concatenated list
    cout << "Concatenated list: ";
    pList(concatenatedHead);

    return 0;
}