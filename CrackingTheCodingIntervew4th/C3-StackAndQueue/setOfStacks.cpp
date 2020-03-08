/*3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks, 
and should create a new stack once the previous one exceeds capacity.
SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack 
(that is, pop() should return the same values as it would if there were just a single stack).

FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/

#include <iostream>
#include <cassert>
using namespace std;

class setOfStacks
{
private:
    int thresholdofSubStack;
    int totalNumOfSubStacks;
    int curStack;
    int curTop;
    int **stacks;
    bool isAllFull();
    bool isEmpty();
    bool isCurFull(int subStackNum);
    void printSubStack(int subStackNum);

public:
    setOfStacks(int threhold, int num);
    void push(int data);
    int pop();
    void print();
    int peek();
};

setOfStacks::setOfStacks(int threhold, int num)
{
    this->thresholdofSubStack = threhold;
    this->totalNumOfSubStacks = num;
    curStack = 0;
    curTop = -1;
    stacks = new int *[totalNumOfSubStacks];
    for (int i = 0; i < totalNumOfSubStacks; i++)
    {
        stacks[i] = new int[thresholdofSubStack];
    }
}

void setOfStacks::push(int data)
{
    if (isAllFull())
    {
        cout << "all full, can't push" << endl;
        return;
    }
    if (curTop < thresholdofSubStack - 1)
    {
        curTop++;
        stacks[curStack][curTop] = data;
    }
    else if (curStack < totalNumOfSubStacks - 1)
    {
        curStack++;
        curTop = 0;
        stacks[curStack][curTop] = data;
    }
    else
    {
        cout << "assert stack " << curStack << " at " << curTop << endl;
        assert(0);
    }
    cout << "push " << data << " to stack " << curStack << " at " << curTop << endl;
}

void setOfStacks::print()
{
    if(isEmpty())
        return;
    cout << "========" << endl;
    for (int s = 0; s <= curStack; s++)
    {
        cout << "stack " << s << ": " << endl;
        if (s != curStack)
        {
            int tempTop = thresholdofSubStack - 1;
            while (tempTop >= 0)
            {
                cout << stacks[s][tempTop] << " ";
                tempTop--;
            }
            cout << " end of stack " << s << endl;
        }
        else
        {
            int tempTop = curTop;
            while (tempTop >= 0)
            {
                cout << stacks[s][tempTop] << " ";
                tempTop--;
            }
            cout << " end of stack " << s << endl;
        }
    }
    cout << "========" << endl;
}

int setOfStacks::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    // cout << "curStack " << curStack << " curTop " << curTop << endl;
    int data = stacks[curStack][curTop];
    curTop--;
    if (curTop == -1)
    {
        curStack--;
        curTop=thresholdofSubStack-1;
    }
    return data;
}

int setOfStacks::peek()
{
    if (isEmpty())
    {
        return -1;
    }
    cout << "peek " << stacks[curStack][curTop] <<  " stack " << curStack << " at " << curTop << endl;
    return stacks[curStack][curTop];
}

bool setOfStacks::isAllFull()
{
    if (curStack == totalNumOfSubStacks - 1 && curTop == thresholdofSubStack - 1)
        return true;
    return false;
}

bool setOfStacks::isEmpty()
{
    if (curStack == 0 && curTop == -1)
    {
        cout << "stack empty" << endl;
        return true;
    }
    return false;
}

int main()
{

    setOfStacks *ss = new setOfStacks(5, 3);
    ss->push(1);
    ss->push(2);
    ss->push(3);
    ss->push(4);
    ss->push(5);

    ss->push(6);
    ss->push(7);
    ss->push(8);
    ss->push(9);
    ss->push(10);

    ss->push(11);
    ss->push(12);
    ss->push(13);
    ss->push(14);
    ss->push(15);

    ss->push(99);

    ss->print();

    ss->pop();
    ss->pop();
    ss->pop();
    ss->pop();
    ss->pop();

    ss->pop();
    ss->pop();
    ss->pop();
    ss->pop();
    ss->pop();

    ss->pop();
    ss->pop();
    ss->pop();
    ss->pop();
    ss->push(99);
    ss->pop();
    
    ss->print();
}