/*
2.5 Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, 
so as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
*/
#include <iostream>
#include <set>
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

Node *findloop(Node *head)
{
    Node *temp = head;
    set<Node*> s;
    while (true)
    {
        // no find
        if(s.find(temp)==s.end()){
            s.insert(temp);
        }
        else //find
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 5);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);
    print(head);
    Node *temp = head;
    while (temp->data != 3)
    {
        temp = temp->next;
    }

    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;

    //print(head);

    cout << findloop(head)->data << endl;


    return 0;
}