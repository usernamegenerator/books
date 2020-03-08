// 4.5 Write an algorithm to find the ‘next’ node (e.g., in-order successor)
// of a given node in a binary search tree where each node has a link to its parent.

#include <iostream>
#include <cassert>
using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
} Node;

Node *insert(Node *root, int data, Node *p)
{
    if (root == NULL)
    {
        root = new Node;
        root->left = NULL;
        root->right = NULL;
        root->parent = p;
        root->data = data;
    }
    else
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data, root);
        }
        else
        {
            root->right = insert(root->right, data, root);
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

Node *findNextNode(Node *root, Node *toFind)
{
    if (toFind == NULL)
        return NULL;
    // 1. if toFind has right node
    // then it's the left most node in the right sub-tree
    // for example, 50 returns 60
    if (toFind->right != NULL)
    {
        Node *subTree = toFind->right;
        while (subTree != NULL && subTree->left != NULL)
        {
            subTree = subTree->left;
        }
        return subTree;
    }
    // else if toFind has no right node
    else
    {
        // 2.1 if the toFind node is the left child of it's parent
        // then parent is the next in order node
        // for example, 20 returns 30
        Node *curParent = toFind->parent;
        if (curParent->left->data == toFind->data)
        {
            return curParent;
        }
        // 2.2 if the toFind node is the right child of it's parent
        // need to go up until a parent node is the left child of its parent
        // for example, 40 returns 50
        else if (curParent->right->data == toFind->data)
        {
            while (curParent != NULL && curParent->parent != NULL)
            {
                if (curParent->parent->left->data == curParent->data)
                {
                    return curParent->parent;
                }
                curParent = curParent->parent;
            }
            return NULL;
        }
        // 2.3 error
        else
        {
            assert(0);
        }
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
    root = insert(root, 50, root);
    root = insert(root, 10, root);
    root = insert(root, 70, root);
    root = insert(root, 60, root);
    root = insert(root, 80, root);
    root = insert(root, 5, root);
    root = insert(root, 30, root);
    root = insert(root, 20, root);
    root = insert(root, 40, root);
    inorder(root);
    cout << endl;
    // cout << root->left->right->parent->data << endl; // 10
    // cout << root->left->right->left->parent->data << endl; // 30

    cout << "[1]  " << root->data <<" returns " << findNextNode(root,root)->data << endl;
    cout << "[2.1] " <<  root->left->right->left->data <<  " returns " << findNextNode(root,root->left->right->left)->data << endl;
    cout << "[2.2] " << root->left->right->right->data << " returns " << findNextNode(root,root->left->right->right)->data << endl;
}