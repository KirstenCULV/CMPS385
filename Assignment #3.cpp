#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int new_data) {
		this->data = new_data;
		this->next = nullptr;
	}
};

class Stack {
	Node* head;

public: 
	Stack() { this->head = nullptr; }
	bool isEmpty() {
		return head == nullptr;
	}

	void push(int new_data) {
		Node* new_node = new Node(new_data);

		if (!new_node) {
			cout << "\nStack Overflow";
		}

		new_node->next = head;
		head = new_node;
	}

	void topAndPop(int new_data) {
		if (this->isEmpty()) {
			cout << "\nStack Overflow" << endl;
		}
		else {
			Node* temp = head;
			head = head->next;
			delete temp;
			Node* new_node = new Node(new_data);
			new_node->next = head;
			head = new_node;

		}

	}

	int peek() {
		if (!isEmpty())
			return head->data;
		else {
			cout << "\nStack is empty";
			return INT_MIN;
		}
	}
};


int main() {
	Stack st;

	st.push(111);
	st.push(222);
	st.push(333);
	st.push(444);
	st.push(555);

	cout << "Top number is " << st.peek() << endl;

	cout << "Replacing top number..." << endl;
	st.topAndPop(777);

	cout << "Top number is now " << st.peek() << endl;

	return 0;
}