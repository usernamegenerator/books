// 3.1 Describe how you could use a single array to implement three stacks.

#include <iostream>

using namespace std;

typedef struct Node
{
    int preTop;
    int data;
} Node;

Node stack[300] = {0};

int stackPointer[3] = {-1, -1, -1};
int top = -1;

void push(int data, int stackNum)
{
    int stackIndex = stackNum - 1;
    int preTop = stackPointer[stackIndex];
    top++;
    stack[top].data = data;
    stack[top].preTop = preTop;
    stackPointer[stackIndex] = top;
}

int pop(int stackNum)
{
    int stackIndex = stackNum - 1;
    if(stackPointer[stackIndex] < 0)
        return -1;
    int data = stack[stackPointer[stackIndex]].data;
    stackPointer[stackIndex] = stack[stackPointer[stackIndex]].preTop;
    return data;
}

void print(int stackNum)
{
    int stackIndex = stackNum - 1;
    int stackTop = stackPointer[stackIndex];
    while (stackTop >= 0)
    {
        cout << stack[stackTop].data << " ";
        stackTop = stack[stackTop].preTop;
    }
    cout << endl;
}

int main()
{
    push(1, 1);
    push(11, 2);
    push(101, 3);
    push(2, 1);
    push(12, 2);
    push(102, 3);
    push(3, 1);
    push(13, 2);
    push(103, 3);
    push(4, 1);
    push(14, 2);
    push(104, 3);
    print(1);
    print(2);
    print(3);
    cout << pop(1) << endl;
    print(1);
    cout << pop(1) << endl;
    print(1);
    cout << pop(1) << endl;
    print(1);
    cout << pop(1) << endl;
    print(1);
    print(2);
    print(3);
    print(1);

}