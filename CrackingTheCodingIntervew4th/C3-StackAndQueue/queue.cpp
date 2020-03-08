#include <iostream>

using namespace std;

typedef struct Node{
    Node* next;
    int data;
}Node;

// insert to the head
void enqueue(Node** head, int data){
    if(*head==NULL){
        *head = new Node;
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;
}

// pop from the tail
int dequeue(Node** head)
{
    if(*head==NULL)
    {
        cout << "empty" << endl;
        return -1;
    }

    if((*head)->next == NULL)
    {
        int val = (*head)->data;
        cout << "pop " << val << endl;
        delete (*head);
        (*head) = NULL;
        return val;
    }

    Node *it = (*head);
    Node *pre = NULL;
    while(it->next!=NULL)
    {
        pre = it;
        it=it->next;
    }

    int val = it->data;
    cout << "pop " << val << endl;

    pre->next = NULL;
    delete it;

    return val;
}

void print(Node *head)
{
    if(head==NULL)
    {
        return;
    }

    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main(){
    Node* head = NULL;
    enqueue(&head,1);
    enqueue(&head,2);
    enqueue(&head,3);
    enqueue(&head,4);
    enqueue(&head,5);
    print(head);

    dequeue(&head);
    print(head);
    dequeue(&head);
    print(head);
    dequeue(&head);
    print(head);
    dequeue(&head);
    print(head);
    dequeue(&head);
    print(head);
    dequeue(&head);
}