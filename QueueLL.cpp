#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    Node* temp = front;

    cout << "Deleted: " << front->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void peek()
{
    if (front == NULL)
        cout << "Queue is empty" << endl;
    else
        cout << "Front element: " << front->data << endl;
}

void display()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* temp = front;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue: ";
    display();

    peek();

    dequeue();

    cout << "Queue after dequeue: ";
    display();

    return 0;
}

//OUTPUT:

/*

Queue: 10 20 30 
Front element: 10
Deleted: 10
Queue after dequeue: 20 30 

*/