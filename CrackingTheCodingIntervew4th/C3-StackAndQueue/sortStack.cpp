// 3.6 Write a program to sort a stack in ascending order.
// You should not make any assumptions about how the stack is implemented.
// The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.

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
    int peek();
    bool isEmpty();
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

int stack::peek()
{
    return head->data;
}
bool stack::isEmpty()
{
    if (getSize() == 0)
        return true;
    return false;
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

// use a extra interger, and an extra stack
// take the element from the stack, compare it to the top element in the other stack
// if it's greater, then pop the other stack and push to the stack, until the other stack top is geater than the element
// if it's less, then push to the other stack.

stack* sort(stack *A)
{
    stack *B = new stack('B');

    while (!A->isEmpty())
    {
        int temp = A->pop();

        while (!B->isEmpty() && temp > B->peek()) // can't push
        {
            A->push(B->pop());
        }
        B->push(temp);
    }
    return B;
}

int main()
{
    stack* A = new stack('A');
    A->push(1);
    A->push(8);
    A->push(2);
    A->push(4);
    A->push(3);
    A->push(7);
    A->print();

    stack* B = sort(A);
    B->print();
}
