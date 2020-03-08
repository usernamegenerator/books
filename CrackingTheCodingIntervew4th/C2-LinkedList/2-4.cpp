/*
You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
_
________________________________________________________________
*/

#include <iostream>
#include <cmath>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

Node *insert(Node *head, int i)
{
    if (head == NULL)
    {
        head = new Node;
        head->data = i;
        head->next = NULL;
        return head;
    }
    Node *newNode = new Node;
    newNode->data = i;
    newNode->next = head;
    head = newNode;
    return head;
}

void print(Node *head)
{
    Node *it = head;
    while (it != NULL)
    {
        cout << it->data << " ";
        it = it->next;
    }
    cout << endl;
}

int size(Node *head)
{
    int n = 0;
    while (head != NULL)
    {
        n++;
        head = head->next;
    }
    return n;
}

Node *add(Node *head1, Node *head2)
{
    Node *newHead = NULL;
    Node *phead1 = head1;
    Node *phead2 = head2;
    bool carry = 0;
    while (phead1 != NULL)
    {
        int res = phead1->data + phead2->data + carry;
        if (res >= 10)
        {
            res = res % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        newHead = insert(newHead, res);
        phead1 = phead1->next;
        phead2 = phead2->next;
    }
    if (carry == 1)
    {
        newHead = insert(newHead, 1);
    }

    return newHead;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *res = NULL;
    head1 = insert(head1, 5);
    head1 = insert(head1, 1);
    head1 = insert(head1, 3);
    print(head1);
    head2 = insert(head2, 2);
    head2 = insert(head2, 9);
    head2 = insert(head2, 5);
    print(head2);

    res = add(head1, head2);
    print(res);
}