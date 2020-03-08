/*
3.2 How would you design a stack which, in addition to push and pop,
also has a function min which returns the minimum element? 
Push, pop and min should all operate in O(1) time.
*/

// add an min element in the Node struct, tracking the current min under this Node;

#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    int min;
} Node;

Node *stack;
int stackTop = -1;

void push(int data)
{
    int currentMin;
    if (stackTop == -1)
    {
        currentMin = 0xFFFF;
    }
    else
    {
        currentMin = stack[stackTop].min;
    }
    if (data < currentMin)
    {
        currentMin = data;
    }
    stackTop++;
    stack[stackTop].data = data;
    stack[stackTop].min = currentMin;
}

int pop()
{
    if(stackTop==-1)
        return -1;
    int data = stack[stackTop].data;
    stackTop--;
    return data;
}

int min()
{
    if(stackTop==-1)
        return 0xFFFF;
    return stack[stackTop].min;
}

void print()
{
    int tempTop = stackTop;
    while(tempTop>=0)
    {
        cout << stack[tempTop].data << " ";
        tempTop--;
    }
    cout << endl;
}

void printWithMin()
{
    int tempTop = stackTop;
    while(tempTop>=0)
    {
        cout << stack[tempTop].data << " " << stack[tempTop].min << endl;
        tempTop--;
    }
    cout << endl;
}

int main()
{
    stack = new Node[300];
    push(6);
    push(7);
    push(5);
    push(8);
    push(3);
    print();
    printWithMin();
    cout << min() << endl;
    cout << endl;
    cout << endl;
    cout << "pop " << pop() << endl;
    cout << min() << endl;
    cout << "pop " << pop() << endl;
    cout << "pop " << pop() << endl;
    cout << min() << endl;

    
}