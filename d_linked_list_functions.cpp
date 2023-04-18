#include <iostream>

using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    // Method to add a node at the beginning of the list
    void addFirst(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }

    // Method to add a node at the end of the list
    void addLast(int data) {
        Node* newNode = new Node(data);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    // Method to add a node at a given position in the list
    void add(int data, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0) {
            addFirst(data);
        }
        else if (pos == size) {
            addLast(data);
        }
        else {
            Node* newNode = new Node(data);
            Node* temp = head;

            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }

            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;

            size++;
        }
    }

    // Method to remove a node at a given position in the list
    void remove(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0) {
            // Removing the head node
            Node* temp = head;
            head = head->next;

            if (head == nullptr) {
                // If the list becomes empty after removing the head node, update the tail pointer accordingly
                tail = nullptr;
            }
            else {
                // If the list still has nodes after removing the head node, update the previous pointer of the new head node
                head->prev = nullptr;
            }

            // Delete the old head node and update the size of the list
            delete temp;
            size--;
        }
        else if (pos == size - 1) {
            // Removing the tail node
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;

            // Delete the old tail node and update the size of the list
            delete temp;
            size--;
        }
        else {
            // Removing a node in the middle of the list
            Node* temp = head;

            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }

            // Update the next and previous pointers of the nodes adjacent to the node being removed
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // Delete the node being removed and update the size of the list
            delete temp;
            size--;
        }
    }

};

