#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
} Node;

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node;
        root->left = NULL;
        root->right = NULL;
        root->data = data;
    }
    else
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// left, current, right
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void bfs(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> *q = new queue<Node *>;
    q->push(root);
    while (!q->empty())
    {
        Node *temp = q->front();
        q->pop();
        cout << temp->data << endl;
        if (temp->left != NULL)
            q->push(temp->left);
        if (temp->right != NULL)
            q->push(temp->right);
    }
    delete q;
}

void dfsStack(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> *s = new stack<Node *>;
    s->push(root);
    while (!s->empty())
    {
        Node *temp = s->top();
        s->pop();
        cout << temp->data << endl;
        if (temp->left != NULL)
            s->push(temp->left);
        if (temp->right != NULL)
            s->push(temp->right);
    }
}

void dfsRecursive(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << endl;
    if (root->right != NULL)
        dfsRecursive(root->right);
    if (root->left != NULL)
        dfsRecursive(root->left);
}

int main()
{
    Node *root = NULL;
    /*
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
*/
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    cout << endl;
    //bfs(root);
    dfsStack(root);
    cout << endl;
    dfsRecursive(root);
}