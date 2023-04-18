#include <iostream>
#include "linked_list_functions.h"
using namespace std;

//creates a block of memory with two parts: data part, address of the next block part.


int main()
{
	Node* head = nullptr;// by default everything is set to null so that when thi nde goes behind gradually, the last node contains a null next

	insert(&head, 2);


	printList(head);

	remove(&head, 1);

	printList(head);


}
