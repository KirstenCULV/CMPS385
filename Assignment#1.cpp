#include <iostream>
#include <string>
using namespace std;
struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* current = NULL;

void printList() {
    struct node* p = head;
    while (p != NULL) {
        cout << " " << p->data << " ";
        p = p->next;
    }
}

void insertatbegin(int data) {

    struct node* lk = (struct node*)malloc(sizeof(struct node));
    lk->data = data;
    lk->next = head;
    head = lk;
}
void deleteatend() {
    struct node* linkedlist = head;
    while (linkedlist->next->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = NULL;
}
int main() {
    insertatbegin(9);
    insertatbegin(5);
    insertatbegin(3);
    insertatbegin(2);
    insertatbegin(1);
    cout << "Here are some prime numbers: ";

    printList();
    deleteatend();
    cout << "\nWait actually, 9 isn't a prime number: ";
    printList();

}