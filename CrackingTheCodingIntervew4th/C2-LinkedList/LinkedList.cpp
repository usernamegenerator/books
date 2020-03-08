#include <iostream>
#include <cassert>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    this->head = NULL;
}

int LinkedList::size()
{
    if (head == NULL)
        return 0;
    Node *it = head;
    int size = 0;
    while (it != NULL)
    {
        size++;
        it = it->next;
    }
    return size;
}

void LinkedList::print()
{
    Node *thisHead = this->head;
    if (thisHead == NULL)
    {
        cout << "NULL" << endl;
    }
    while (thisHead != NULL)
    {
        cout << thisHead->data << " ";
        thisHead = thisHead->next;
    }
    cout << endl;
}

void LinkedList::addFirst(int i)
{
    Node *newNode = new Node;
    newNode->data = i;
    newNode->next = this->head;
    this->head = newNode;
}

void LinkedList::addLast(int i)
{
    if (head == NULL)
    {
        head = new Node;
        head->data = i;
        head->next = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node;
    newNode->data = i;
    newNode->next = NULL;
    temp->next = newNode;
}

void LinkedList::deleteFirst()
{
    assert(this->head != NULL);
    Node *temp = this->head;
    this->head = this->head->next;
    delete (temp);
}

void LinkedList::deleteLast()
{
    assert(head != NULL);
    if (head->next == NULL)
    {
        Node *temp = head;
        head = NULL;
        delete (temp);
        return;
    }

    Node *pre = head;
    Node *cur = head;
    while (cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = NULL;
    delete (cur);
}

void LinkedList::reverse()
{
    if (head == NULL || head->next == NULL)
        return;
    Node *pre = NULL;
    Node *cur = head;
    Node *nextNode = head;
    while (cur != NULL)
    {
        nextNode = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextNode;
    }
    head = pre;
}

int main()
{
    LinkedList *ll = new LinkedList();
    ll->addLast(0);
    ll->addFirst(1);
    // cout << ll->size() << endl;
    ll->addFirst(2);
    // cout << ll->size() << endl;
    ll->addFirst(3);
    ll->addLast(-1);
    // cout << ll->size() << endl;
    ll->print();
    // ll->deleteFirst();
    // ll->deleteFirst();
    // ll->deleteFirst();
    // ll->deleteLast();
    // cout << ll->size() << endl;
    // ll->deleteLast();
    // cout << ll->size() << endl;
    // ll->deleteLast();

    //cout << ll->size() << endl;
    ll->reverse();
    ll->print();
    return 0;
}