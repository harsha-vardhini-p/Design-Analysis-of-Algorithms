#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node* temp = top;
    cout << "Deleted: " << top->data << endl;

    top = top->next;
    delete temp;
}

void peek()
{
    if (top == NULL)
        cout << "Stack is empty" << endl;
    else
        cout << "Top element: " << top->data << endl;
}

void display()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* temp = top;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    cout << "Stack: ";
    display();

    peek();

    pop();

    cout << "Stack after pop: ";
    display();

    return 0;
}

//OUTPUT

/*

Stack: 40 30 20 10 
Top element: 40
Deleted: 40
Stack after pop: 30 20 10 
    
*/