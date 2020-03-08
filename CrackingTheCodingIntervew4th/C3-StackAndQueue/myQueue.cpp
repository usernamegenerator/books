// 3.5 Implement a MyQueue class which implements a queue using two stacks.

// let one stack to be the in stack
// let the other stack to be the out stack
// enqueue 
// always push to in stack
// dequeue
// if there is elements in out stack
// just pop the out stack
// if there is no elements in out stack, and there is elements in the in stack
// pop the element in in stack and push it to out stack, one by one, until in stack is empty

#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node *next;
} Node;

class stack
{
private:
    int size;
    Node *head;
    char name;

public:
    stack(char);
    void push(int data);
    int pop();
    void print();
    char getName();
    int getSize();
};

stack::stack(char x)
{
    head = NULL;
    name = x;
    size = 0;
}

char stack::getName()
{
    return name;
}
int stack::getSize()
{
    return size;
}
void stack::push(int data)
{
    if (head == NULL)
    {
        head = new Node;
        head->data = data;
        head->next = NULL;
    }
    else
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    size++;
}

int stack::pop()
{
    if (head == NULL)
    {
        return -1;
    }
    Node *temp = head;
    int data = temp->data;
    head = temp->next;
    delete temp;
    size--;
    return data;
}

void stack::print()
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << " empty " << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class queue
{
private:
    stack *in;
    stack *out;
    int size;

public:
    queue();
    void enqueue(int data);
    int dequeue();
    int getSize();
};

queue::queue()
{
    in = new stack('i');
    out = new stack('o');
    size = 0;
}
int queue::getSize()
{
    return size;
}

void queue::enqueue(int data)
{
    in->push(data);
    size++;
}

int queue::dequeue()
{
    int data = -1;
    if (out->getSize() == 0 && in->getSize() == 0)
    {
        return -1;
    }
    if (out->getSize() == 0)
    {
        while (in->getSize() != 0)
        {
            out->push(in->pop());
        }
        data = out->pop();
        return data;
    }
    else
    {
        data = out->pop();
        return data;
    }
}

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    cout << q.dequeue() << endl;
    q.enqueue(13);
    q.enqueue(14);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

}