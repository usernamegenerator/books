/*
4.1 Implement a function to check if a tree is balanced. 
For the purposes of this question, a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one.
*/

#include <iostream>
#include <algorithm>
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

int maxHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
}

int minHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + min(minHeight(root->left), minHeight(root->right));
}

bool isBalanced(Node *root)
{
    if (maxHeight(root) - minHeight(root) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
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

int main()
{
    Node *root = NULL;
    /*
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 3);
    */

    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    //create the inbalance;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 3);
    
    inorder(root);

    cout << endl;

    cout << isBalanced(root) << endl;
}