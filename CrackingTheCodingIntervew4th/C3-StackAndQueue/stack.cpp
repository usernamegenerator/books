#include <iostream>

using namespace std;

typedef struct Node{
    Node* next;
    int data;
}Node;

void push(int data, Node** head)
{
    if(*head==NULL){
        *head = new Node;
        (*head)->next = NULL;
        (*head)->data = data;
        return;
    }

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void print(Node* head)
{
    Node * it = head;
    while(it!=NULL)
    {
        cout << it->data << " ";
        it = it->next;
    }
    cout << endl;
}


int pop(Node** head)
{
    if(*head == NULL){
        cout << "empty stack" << endl;
        return -1;
    }
        
    Node* temp = *head;
    *head = (*head)->next;
    cout << "pop " << temp->data << endl;
    int val = temp->data;
    delete temp;
    return val;
}

int main()
{
    Node * head = NULL;
    push(1,&head);
    push(2,&head);
    push(3,&head);
    push(4,&head);
    print(head);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);

    push(1,&head);
    push(2,&head);
    push(3,&head);
    push(4,&head);
    print(head);

}