/*
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
#include <map>
#include <utility>

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

Node *removeDuplidate(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    map<int, bool> m;
    Node *it = head;
    Node *pre = NULL;
    while (it != NULL)
    {
        // no find
        if (m.find(it->data) == m.end())
        {
            m.insert(pair<int, bool>(it->data, true));
            pre = it;
            it = it->next;
        }
        else //find
        {
            Node* temp;
            temp = it;
            pre->next = it->next;
            it = it->next;
            delete (temp);
        }
    }
    return head;
}

Node *removeDuplicateNoExtraSpace(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *it = head;
    Node *jt = head->next;
    Node *prejt = head;
    while (it != NULL)
    {
        //cout << "it " << it->data << endl;
        jt = it->next;
        while (jt != NULL)
        {
            //cout << " jt " << jt->data << endl;
            // not same
            if (jt->data != it->data)
            {
                prejt = jt;
                jt = jt->next;
            }
            else // same
            {
                Node* temp;
                temp = jt;
                prejt->next = jt->next;
                jt = jt->next;
                //cout << "  same prejt " << prejt->data << endl;
                //cout << "  same jt " << jt->data << endl;
                delete (temp);
            }
        }
        it = it->next;
    }
    return head;
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
    //head = removeDuplidate(head);
    head = removeDuplicateNoExtraSpace(head);
    print(head);
}