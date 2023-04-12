#include "functions.h"
#include <iostream>
// FUBCTION DECLARATIONS

// Insert a new node with the given data at the beginning of the linked list
void insert(Node** head, int data) { //Dereferences the head pointer while taking parameter input

	Node* newNode = new Node; //created a node
	newNode->data = data; //sets data of that node
	newNode->next = *head; //sets the next to current head. Note that current head will become the second node after this line
	*head = newNode; //make the new node the latest head
}

//insert at n-th position
void insert(Node** head, int data, int n) {

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	// If the linked list is empty or the new node should be inserted at the head
	if (*head == nullptr || n == 0) {
		newNode->next = *head;
		//head becomes the second element if lis not empty
		*head = newNode;
		//newnode becomes head if list empty
		return;
	}

	Node* current = *head;

	// Traverse the linked list to the nth position
	for (int i = 1; i < n && current->next != nullptr; i++) {
		current = current->next;
	}

	// Insert the new node at the nth position
	newNode->next = current->next;
	current->next = newNode;
}




// Remove the first node with the given data from the linked list
void remove(Node** head, int data) {
	Node* current = *head; // creates a node and turns it to head
	Node* prev = nullptr;

	while (current != nullptr && current->data != data) {
		//current is not nullptr, and data isn't matching.so the node has more than 1 element.

		prev = current; // current node will become previous node
		current = current->next; //next node will become current node
	}

	if (current == nullptr) {
		//linked list is empty
		return;
	}

	if (prev == nullptr) {
		//This can true only if the program didin't enter the while loop. SO only one element
		//if list has only one element nothing changes as head itself is the current now
		*head = current->next;
	}
	else {
		//if the data matches previous collects the address current is pointing to so that connection remains inact after deleting the current. at this time both current next and prev next is equal.
		prev->next = current->next;
	}
	//deletes the newly created current if list has one data and data didn't match
	//deletes the current node if data matched.
	delete current;
}

void removeNth(Node** head, int n) {
	Node* current = *head;
	Node* prev = nullptr;

	// Traverse to the nth node
	for (int i = 1; i < n && current != nullptr; i++) {
		prev = current;
		current = current->next;
	}

	if (current == nullptr) {
		return; // n is greater than the number of nodes in the list
	}

	if (prev == nullptr) {
		*head = current->next; // n is 1, so update the head node
	}
	else {
		prev->next = current->next; // link the previous node to the next node
	}

	delete current; // free the memory occupied by the removed node
}

void reverseList(Node** head) {
	Node* prev = nullptr;
	Node* current = *head;
	Node* next = nullptr;

	while (current != nullptr) {
		next = current->next; // Save the next node
		current->next = prev; // Reverse the link to the previous node
		prev = current; // Move the previous pointer forward
		current = next; // Move the current pointer forward
	}

	*head = prev; // Update the head node to the last node (which is now the first node)
}

void reverseListRecursive(Node** head) {
	// base case: empty list or only one node
	if (*head == nullptr || (*head)->next == nullptr) {
		return;
	}

	Node* rest = (*head)->next;
	reverseListRecursive(&rest);

	// reverse the positions of the current node and the next node
	(*head)->next->next = *head;
	(*head)->next = nullptr;

	// update the head of the reversed list
	*head = rest;
}

void printList(Node* head) {
	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

