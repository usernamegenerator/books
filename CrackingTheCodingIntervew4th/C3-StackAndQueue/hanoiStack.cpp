/*
3.4 In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower. 
The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints:
(A) Only one disk can be moved at a time.
(B) A disk is slid off the top of one rod onto the next rod.
(C) A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to the last using Stacks.
*/
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
    if(temp==NULL)
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

void pop_push(stack *source, stack *destination)
{
    int data = source->pop();
    destination->push(data);
    cout << "move " << data << " from " << source->getName() << " to " << destination->getName() << endl;
}
/*
move 1 from A to C
move 2 from A to B
move 1 from C to B
move 3 from A to C
move 1 from B to A
move 2 from B to C
move 1 from A to C
*/
void hanoi(int n, stack *from, stack *helper, stack *to)
{    
    if (n == 1)
    {
        pop_push(from, to);
    }
    else
    {
        hanoi(n - 1, from, to, helper);
        pop_push(from, to);
        hanoi(n - 1, helper, from, to);
    }
}

int main()
{
    /*
    stack s('X');
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    s.print();
    */


    stack from('A');
    stack helper('B');
    stack to('C');
    from.push(3);
    from.push(2);
    from.push(1);
    hanoi(3, &from, &helper, &to);
    
}