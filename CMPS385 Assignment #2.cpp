#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next, *prev;

	Node(int new_data) {
		data = new_data;
		next = prev = NULL;
	}
};

Node *insertAtFront(Node *head,
	int new_data) {

	Node *new_node = new
		Node(new_data);

	new_node->next = head;

	if (head != NULL)
		head->prev = new_node;

	return new_node;
}

Node* deleteAtEnd(Node* head) {

	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		delete head;
		return NULL;
	}

	Node* curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	if (curr->prev != NULL) {
		curr->prev->next = NULL;
	}

	delete curr;

	return head;
}


void printList(Node* head) {

	Node* curr = head;
	while (curr != NULL) {
		cout << " " << curr->data;
		curr = curr->next;
	}
	cout << endl;
}

int main() {

	Node* head = new Node(14);
	head->next = new Node(21);
	head->next->prev = head;
	head->next->next = new Node(28);
	head->next->next->prev = head->next;

	cout << "7 is my favorite number, here are 3 fun numbers divisible by 7:";
	printList(head);

	cout << "Wait, I forgot the most important one!:";
	int data = 7;
	head = insertAtFront(head, data);

	head = deleteAtEnd(head);

	printList(head);

	return 0;

}