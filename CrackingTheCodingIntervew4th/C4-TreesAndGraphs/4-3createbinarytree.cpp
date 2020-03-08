// 4.3 Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
} Node;

Node *addToTree(int *array, int start, int end)
{
    if (start > end)
        return NULL;
    Node *newRoot = new Node;
    int mid = (start + end) / 2;
    newRoot->data = array[mid];
    newRoot->left = addToTree(array, start, mid - 1);
    newRoot->right = addToTree(array, mid + 1, end);
    return newRoot;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *root = addToTree(array, 0, 9);
    inorder(root);
    cout << endl;
}