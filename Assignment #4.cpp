#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* link;
};

struct Queue {
	struct Node* front, * rear;
};


void enQueue(Queue* q, int value)
{
	struct Node* temp = new Node;
	temp->data = value;
	if (q->front == NULL)
		q->front = temp;
	else
		q->rear->link = temp;

	q->rear = temp;
	q->rear->link = q->front;
}

int deQueue(Queue* q)
{
	if (q->front == NULL) {
		cout << "Queue is empty";
		return INT_MIN;
	}

	int value;
	if (q->front == q->rear) {
		value = q->front->data;
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		struct Node* temp = q->front;
		value = temp->data;
		q->front = q->front->link;
		q->rear->link = q->front;
		free(temp);
	}

	return value;
}

void displayQ(struct Queue* q)
{
	struct Node* temp = q->front;
	cout << endl << "Here are the numbers in line: ";
	while (temp->link != q->front) {
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << temp->data;
}

void getFront(Queue* q)
{
	if (q->front == NULL) {
		cout << "Queue is empty";
		
	}
	else
	{
	
		cout << endl << "Here is the number in front now: ";
		cout << q->front->data;
	}
}

int main()
{
	Queue* q = new Queue;
	q->front = q->rear = NULL;

	enQueue(q, 4);
	enQueue(q, 5);
	enQueue(q, 7);
	enQueue(q, 9);
	enQueue(q, 11);

	displayQ(q);

	cout << endl << "This number was called: " << deQueue(q);
	cout << endl << "This number was called: " << deQueue(q);

	getFront(q);

	return 0;

}