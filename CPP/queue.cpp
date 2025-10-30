#include <iostream>
using namespace std;

#define SIZE 5  // maximum size of queue

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == SIZE - 1)
            cout << "Queue is full (Overflow)\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << value << " enqueued to queue\n";
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear)
            cout << "Queue is empty (Underflow)\n";
        else {
            cout << arr[front] << " dequeued from queue\n";
            front++;
        }
    }

    // Display queue
    void display() {
        if (front == -1 || front > rear)
            cout << "Queue is empty\n";
        else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.display();

    return 0;
}
