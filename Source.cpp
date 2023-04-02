#include <iostream>
using namespace std;

//creates a block of memory with two parts: data part, address of the next block part.
struct Node {
	int data;
	Node* next;
};


Node* head{ NULL };//head pointer will point to the first Node
Node* n{ NULL }; // n will be used to creat new node
Node* temp{ NULL };//temp will be used to connect the previous node to the newly creatted node


void insert();//function to insert data in node
void printList();//function to print the elements of the node

int main()
{

	insert();
	printList();



}

void insert() {
	int x, l;
	cin >> l;
//creating the first node//
	
	n = new Node; // create the first block of memory and comman n to point to it
	head = n; //head pointer will point to whatever n is pointing to. In this case the first node. This will not change.
	temp = n;//temp pointer will point to whatever n is pointing to. In this case the first node. This will change every time.
	cin >> n->data; //insert data to the first node.
	
//finished creating the first node//

//creat and insert data to the next nodes//

	for (size_t i = 0; i < l-1; i++)
	{
	n = new Node;

	cin >> x;

	n->data = x;
	temp->next = n;// using the previously saved temp, next pointer of the previous block will point to whatever n is pointing. In this case the newly created block.
	temp = n; // temp will point to the newly created block.
	}
}

void printList() {

	Node* t = head;

	while (t->next != NULL) {
		cout << t->data << ' ';
		t = t->next;
	}

}
