#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// ---LENGKAPI DI SINI ---
void exchangeHeadAndTail(Node* head_ref) {
    if (!head_ref || head_ref->next == head_ref) return;

    Node* tail = head_ref->prev;

    int temp = head_ref->data;
    head_ref->data = tail->data;
    tail->data = temp;
}
// ---SELESAI ---

void printList(Node* head_ref) {
    if (!head_ref) return;
    Node* curr = head_ref;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head_ref);
    cout << endl;
}

void insertEnd(Node*& head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (!head_ref) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    Node* tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    tail->next = newNode;
    head_ref->prev = newNode;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    return 0;
}



