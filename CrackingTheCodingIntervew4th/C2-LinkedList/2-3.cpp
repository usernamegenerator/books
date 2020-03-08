/*
Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
*/


#include <iostream>
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

void removeNode(Node* n)
{
    n->data = n->next->data;
    n->next = n->next->next;
    delete(n->next);
    return;
}

int main(){
    Node *head = NULL;
    head = insert(head, 3);
    head = insert(head, 6);
    head = insert(head, 2);
    head = insert(head, 6);
    head = insert(head, 1);
    head = insert(head, 6);
    head = insert(head, 0);
    print(head);
    removeNode(head->next->next);
    print(head);
}