#include <iostream>
using namespace std;
// creation of a Node
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Recursive reverse helper
void reverse(Node *&head, Node *curr, Node *prev)
{
    // Base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

// Function to call reverse
Node *reverseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    reverse(head, curr, prev);
    return head;
}

// Function to insert at tail
void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print linked list
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int num;
    cout << "Enter data (-1 to end): " << endl;

    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        insertAtTail(head, num);
    }

    cout << "Original list: ";
    print(head);

    head = reverseLinkedList(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}