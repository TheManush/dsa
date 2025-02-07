#include <iostream>
#include <unordered_map>

using namespace std;


struct DL{

    struct Node{
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node* head = NULL;
    Node* tail = NULL;
    Node* mid = NULL;
    unordered_map<int, Node*> nodeMap;
     
    void insertAtStart(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            mid = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            if(nodeMap.size() % 2 == 0) mid = mid->prev;
        }
        nodeMap[data] = newNode;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            mid = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            if(nodeMap.size() % 2 == 1) mid = mid->next;
        }
        nodeMap[data] = newNode;
    }

    void deleteFromMiddle() {
        if (mid == NULL) return; // List is empty

        Node* temp = mid;
        if (mid->prev)  
        {
            mid->prev->next = mid->next;
        }
        if (mid->next)  {

            mid->next->prev = mid->prev;
        }

        if (nodeMap.size() % 2 == 0)
        {
            mid = mid->next;
        }
        else
        {
            mid = mid->prev;
        }

        nodeMap.erase(temp->data);
        delete temp;
    }
    void printList(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }




};

#include <iostream>
#include <unordered_map>
using namespace std;

struct DL {
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid = nullptr;
    int size = 0; // Track the number of nodes in the list
    unordered_map<int, Node*> nodeMap; // Map to store nodes for quick access

    // Insert a node at the start of the list
    void insertAtStart(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            mid = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            // Update mid pointer if necessary
            if (size % 2 == 0) {
                mid = mid->prev;
            }
        }
        size++;
        nodeMap[data] = newNode; // Add the new node to the map
    }

    // Insert a node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            mid = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            // Update mid pointer if necessary
            if (size % 2 == 1) {
                mid = mid->next;
            }
        }
        size++;
        nodeMap[data] = newNode; // Add the new node to the map
    }

    // Delete the middle node of the list
    void deleteFromMiddle() {
        if (mid == nullptr) return; // List is empty

        Node* temp = mid;
        if (mid->prev) {
            mid->prev->next = mid->next;
        }
        if (mid->next) {
            mid->next->prev = mid->prev;
        }

        // Update head and tail if necessary
        if (mid == head) {
            head = mid->next;
        }
        if (mid == tail) {
            tail = mid->prev;
        }

        // Update mid pointer
        if (size % 2 == 0) {
            mid = mid->next;
        } else {
            mid = mid->prev;
        }

        nodeMap.erase(temp->data); // Remove the deleted node from the map
        delete temp; // Free memory
        size--;
    }

    // Print the list from head to tail
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    Node* middle;
    int count;

public:
    LinkedList() {
        head = tail = middle = nullptr;
        count = 0;
    }

    // Insert at the front (O(1))
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = middle = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;

        // Update middle
        if (count % 2 == 0) {
            middle = middle->prev;
        }
    }

    // Insert at the end (O(1))
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = middle = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;

        // Update middle
        if (count % 2 == 1) {
            middle = middle->next;
        }
    }

    // Delete the middle node in O(1)
    void deleteMiddle() {
        if (!middle) return;

        Node* target = middle;
        
        if (head == tail) { // If there's only one node
            head = tail = middle = nullptr;
        } else if (middle == head) { // If middle is the head
            head = head->next;
            head->prev = nullptr;
            middle = head;
        } else if (middle == tail) { // If middle is the tail
            tail = tail->prev;
            tail->next = nullptr;
            middle = tail;
        } else { // If middle is somewhere in between
            middle->prev->next = middle->next;
            middle->next->prev = middle->prev;
        }

        count--;

        // Update the middle pointer
        if (count == 0) {
            middle = nullptr;
        } else if (count % 2 == 0) {
            middle = middle->prev;
        } else {
            middle = middle->next;
        }

        delete target;
    }

    // Print the list
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Print the middle element
    void printMiddle() {
        if (middle) {
            std::cout << "Middle element: " << middle->data << std::endl;
        } else {
            std::cout << "List is empty.\n";
        }
    }
};
