/*
4.8 You are given a binary tree in which each node contains a value. 
Design an algorithm to print all paths which sum up to that value. 
Note that it can be any path in the tree - it does not have to start at the root.
*/

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

void findSum(Node *root, int sum, vector<int> &v)
{
    if (root == NULL)
        return;

    v.push_back(root->data);

    findSum(root->left, sum, v);
    findSum(root->right, sum, v);

    int total = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        total += v[i];
        if (total == sum)
        {
            for (int j = i; j < v.size(); j++)
            {
                cout << v[j] << " ";
            }
            cout << endl;
        }
    }

    v.pop_back();
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
    Node *rootA = NULL;
    rootA = insert(rootA, 50);
    rootA = insert(rootA, 10);
    rootA = insert(rootA, 70);
    rootA = insert(rootA, 60);
    rootA = insert(rootA, 80);
    rootA = insert(rootA, 5);
    rootA = insert(rootA, 30);
    rootA = insert(rootA, 20);
    rootA = insert(rootA, 40);
    /*
    inorder(rootA);
    cout << endl;
    preorder(rootA);
    cout << endl;
    */
    vector<int> v;
    findSum(rootA, 80, v);
}