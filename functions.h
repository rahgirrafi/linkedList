#pragma once
#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void insert();
void insert(Node** head, int data);
void insert(Node** head, int data, int n);
void printList(Node* head);
void remove(Node** head, int data);
void removeNth(Node** head, int n);
void reverseList(Node** head);

void reverseListRecursive(Node** head);


#endif FUNCTIONS_H
