/*
2.2 Implement an algorithm to find the nth to last element of a singly linked list.
*/

#include <iostream>

using namespace std;

typedef struct Node{
    Node* next;
    int data;
}Node;

Node* insert(Node* head, int i){
    if(head==NULL)
    {
        head = new Node;
        head->next = NULL;
        head->data = i;
        return head;
    }

    Node* newNode = new Node;
    newNode->next = head;
    newNode->data = i;
    head= newNode;
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

int getNthFromLast(Node* head, int N)
{
    //assume N < size of the list, and > N
    Node* p1 = head;
    Node* p2 = head;
    while(N--)
    {
        p2 = p2->next;
    }
    while(p2!=NULL)
    {
        p2=p2->next;
        p1=p1->next;
    }
    return p1->data;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 3);
    head = insert(head, 6);
    head = insert(head, 2);
    head = insert(head, 6);
    head = insert(head, 1);
    head = insert(head, 6);
    head = insert(head, 0);
    print(head);
    cout << getNthFromLast(head,1) << endl;
    cout << getNthFromLast(head,2) << endl;
    cout << getNthFromLast(head,3) << endl;
    cout << getNthFromLast(head,4) << endl;
    cout << getNthFromLast(head,5) << endl;
    cout << getNthFromLast(head,6) << endl;
    cout << getNthFromLast(head,7) << endl;
    
}