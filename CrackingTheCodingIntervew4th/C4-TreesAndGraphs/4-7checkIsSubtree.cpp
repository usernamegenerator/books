//4.7 You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes.
// Create an algorithm to decide if T2 is a subtree of T1.

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

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorderSave(Node *root, vector<int> *v)
{
    if (root != NULL)
    {
        inorderSave(root->left, v);
        //cout << root->data << " ";
        v->push_back(root->data);
        inorderSave(root->right, v);
    }
}

void preorderSave(Node *root, vector<int> *v)
{
    if (root != NULL)
    {
        //cout << root->data << " ";
        v->push_back(root->data);
        preorderSave(root->left,v);
        preorderSave(root->right,v);
    }
}

// check if B is a subset of A
bool isSubset(vector<int> A, vector<int> B)
{
    for (int i = 0; i < A.size(); i++)
    {
        int j;

        for (j = 0; j < B.size(); j++)
        {
            if (A[i + j] != B[j])
            {
                break;
            }
        }
        if (j == B.size())
            return true;
    }
    return false;
}

// if rootB is subtree of rootA
bool isSubtree(Node *rootA, Node *rootB)
{
    // NULL tree is subtree of any tree;
    if (rootB == NULL && rootA != NULL)
    {
        return true;
    }
    vector<int> inorderA;
    inorderSave(rootA, &inorderA);
    vector<int> inorderB;
    inorderSave(rootB, &inorderB);
    vector<int> preorderA;
    preorderSave(rootA,&preorderA);
    vector<int> preorderB;
    preorderSave(rootB,&preorderB);
    for (auto i : inorderA)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : inorderB)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : preorderA)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : preorderB)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "isSubset(inorderA, inorderB) " << isSubset(inorderA, inorderB) << endl;
    cout << "isSubset(preorderA, preorderB) " << isSubset(preorderA, preorderB) << endl;

    if (isSubset(inorderA, inorderB) && isSubset(preorderA, preorderB))
    {
        return true;
    }
    else
    {
        return false;
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
    Node *rootB = NULL;
    rootB = insert(rootB, 10);
    rootB = insert(rootB, 5);
    rootB = insert(rootB, 30);
    rootB = insert(rootB, 20);
    rootB = insert(rootB, 40);
    /*
    inorder(rootB);
    cout << endl;
    preorder(rootB);
    cout << endl;
    */
    //vector<int> v = inorderSave(rootA);
    /*
    for(auto i: v)
    {
        cout << i << endl;
    }
    */
    cout << isSubtree(rootA, rootB) << endl;
}