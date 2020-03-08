// 4.6 Design an algorithm and write code to find the first common ancestor
// of two nodes in a binary tree. Avoid storing additional nodes in a data structure.
// NOTE: This is not necessarily a binary search tree.

#include <iostream>
#include <vector>
using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

bool findpath(Node *root, Node *A, vector<Node *> *path)
{
    if (root == NULL)
        return false;

    path->push_back(root);

    if (root->data == A->data)
        return true;

    if (
        (root->left != NULL && findpath(root->left, A, path)) ||
        (root->right != NULL && findpath(root->right, A, path)))
    {
        return true;
    }

    path->pop_back();
    return false;
}

Node *LCAwithVector(Node *root, Node *A, Node *B, vector<Node *> *pathA, vector<Node *> *pathB)
{
    findpath(root, A, pathA);
    findpath(root, B, pathB);

    for (auto i : *pathA)
    {
        cout << i->data << " ";
    }
    cout << endl;
    for (auto i : *pathB)
    {
        cout << i->data << " ";
    }
    cout << endl;

    int i;
    for (i = 0; i < pathA->size() && i < pathB->size(); i++)
    {
        if ((*pathA)[i]->data != (*pathB)[i]->data)
            break;
    }
    return (*pathA)[i - 1];
}

Node *findLCA(Node *root, Node *A, Node *B)
{
    if (root == NULL)
        return NULL;

    // if root equals to A or B, means root is the LCA
    if (root->data == A->data || root->data == B->data)
    {
        return root;
    }

    // otherwise, look for left and right
    Node *left = findLCA(root->left, A, B);
    Node *right = findLCA(root->right, A, B);

    //if both results returns true
    // means it's splited by the root and the root the LCA
    if (left != NULL && right != NULL)
    {
        return root;
    }

    // otherwise, it's in either left or right, keeps checking
    if (left != NULL)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int main()
{
    /* Let us create following BST 
                 50 
             /       \ 
            /         \ 
           /           \ 
          10           70 
        /    \        /   \ 
       5     30      60   80 
            /  \   
           20   40
       */
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    inorder(root);
    cout << endl;

    vector<Node *> pathA;
    vector<Node *> pathB;
    Node *temp = LCAwithVector(root, root->left->left, root->left->right->right, &pathA, &pathB); //5 and 40, return 10
    cout << temp->data << endl;
    
    temp = findLCA(root, root->left->left, root->left->right->right);
    cout << temp->data << endl;
}