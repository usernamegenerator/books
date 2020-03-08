#include <iostream>

using namespace std;

int stack[100]={0};
int topIndex = 0;
void push(int data)
{
    stack[topIndex] = data;
    topIndex++;
}

int pop()
{
    if(topIndex==0)
    {
        cout << "empty " << endl;
        return -1;
    }
    int data = stack[--topIndex];
    cout << "pop " << data << endl;
    return data;
}

int peek()
{
    if(topIndex==0)
    {
        cout << "empty " << endl;
        return -1;
    }

    int data = stack[topIndex-1];
    cout << "peek " << data << endl;
    return data;
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    pop();
    peek();
    pop();
    pop();
    pop();
    pop();
}