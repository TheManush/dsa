#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Initialize head and tail as nullptr
Node* head = nullptr;
Node* tail = nullptr;

// Function to insert a new node after a given node
void insertAfter(int key, int newData) {
  
    // Initialize curr Pointer to head
    Node* curr = head;

    // Iterate over Linked List to find the key
    while (curr != nullptr) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    // if curr becomes NULL means, given key is not
    // found in linked list
    if (curr == nullptr)
        return;

    // Allocate new node by given data and point
    // the next of newNode to curr's next &
    // point current next to newNode
    Node* newNode = new Node(newData);
    newNode->next = curr->next;
    curr->next = newNode;

    // Update tail if newNode is inserted at the end
    if (newNode->next == nullptr) {
        tail = newNode;
    }
}

void printList() {
    Node* node = head;
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
  
    // Create the linked list 2->3->5->6
    head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);

    // Update tail to the last node
    tail = head->next->next->next;

    int key = 3, newData = 4;

    insertAfter(key, newData);

    printList();

    return 0;
}
