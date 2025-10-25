#include <iostream>
using namespace std;

// Node creation
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr; // modern C++
    }
};

// Recursive reverse helper
void reverse(Node*& head, Node* curr, Node* prev) {
    if (curr == nullptr) { // base case
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

// Function to reverse linked list
Node* reverseLinkedList(Node* head) {
    reverse(head, head, nullptr); // call helper
    return head;
}

// Insert at tail
void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print linked list
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int num;
    cout << "Enter data (-1 to end): " << endl;

    while (true) {
        cin >> num;
        if (num == -1) break;
        insertAtTail(head, num);
    }

    cout << "Original list: ";
    print(head);

    head = reverseLinkedList(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
