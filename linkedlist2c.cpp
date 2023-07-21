//Always insert elements at one end, and delete elements from the other end 
#include <iostream>
using namespace std;

// Node class
class Node3{
public:
    int val;
    Node3* next;

    Node3(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Insert an element at the end of the queue
void insert_element(Node3** head, Node3* element) {
    if (*head == nullptr) {
        *head = element;
    } else {
        Node3* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = element;
    }
}

// Delete the first element from the queue and return it
Node3* delete_q(Node3** head) {
    if (*head == nullptr) {
        cout << "Queue is empty." << endl;
        return nullptr;
    }

    Node3* temp = *head;
    *head = (*head)->next;
    temp->next = nullptr;
    return temp;
}

int main() {
    Node3* head = nullptr;

    // Insert elements into the queue
    insert_element(&head, new Node3(75)); 
    cout<<"Inserted Element:"<<"75"<<endl;

    insert_element(&head, new Node3(99)); 
    cout<<"Inserted Element:"<<"99"<<endl;

    insert_element(&head, new Node3(36)); 
    cout<<"Inserted Element:"<<"36"<<endl;

     insert_element(&head, new Node3(45)); 
    cout<<"Inserted Element:"<<"45"<<endl;

     insert_element(&head, new Node3(78)); 
    cout<<"Inserted Element:"<<"78"<<endl;

    cout<<"\n"<<endl;

    // Delete elements from the queue and print them

    Node3* deletedNode1 = delete_q(&head);
    if (deletedNode1 != nullptr) {
        cout << "Deleted element: " << deletedNode1->val << endl;
        delete deletedNode1;
    }
    // Node* deletedNode2 = delete_q(&head);
    // if (deletedNode2 != nullptr) {
    //     cout << "Deleted element: " << deletedNode2->value << endl;
    //     delete deletedNode2;
    // }

    // Node* deletedNode3 = delete_q(&head);
    // if (deletedNode3 != nullptr) {
    //     cout << "Deleted element: " << deletedNode3->value << endl;
    //     delete deletedNode3;
    // }

    // Try to delete an element from an empty queue
    // Node* deletedNode4 = delete_q(&head);
    // if (deletedNode4 != nullptr) {
    //     cout << "Deleted element: " << deletedNode4->value << endl;
    //     delete deletedNode4;
    // }



    return 0;
}