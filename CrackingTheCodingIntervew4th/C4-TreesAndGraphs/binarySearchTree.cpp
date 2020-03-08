// Implement a tree / find a node / delete a node

#include <iostream>
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

// current, left, right
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// left, right, current
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
/*

https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

1) Node to be deleted is leaf: Simply remove from the tree.

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80
2) Node to be deleted has only one child: Copy the child to the node and delete the child

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80
3) Node to be deleted has two children: Find inorder successor of the node. 
Copy contents of the inorder successor to the node and delete the inorder successor.
Note that inorder predecessor can also be used.

              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80

*/
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else // root is the node to delete
    {
        // 0. check root if NULL
        if (root == NULL)
        {
            return root;
        }
        // 1. the node has no children
        // delete the node, done
        if (root->left == NULL && root->right == NULL)
        {
            Node *temp = root;
            root = NULL;
            delete temp;
            return root;
        }
        //2. the node has only one child
        // copy the child to the node, and delete the child
        else if (root->left != NULL && root->right == NULL)
        {
            root->data = root->left->data;
            Node *temp = root->left;
            delete temp;
            root->left = NULL;
            return root;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            root->data = root->right->data;
            Node *temp = root->right;
            delete temp;
            root->right = NULL;
            return root;
        }
        //3. the node has two children
        // copy the left most child in the right subtree under node to the node, delete that child
        else
        {
            Node *it = root->right; 
            // has to use pre to point to NULL to delete next left from the tree
            // if only delete it, then it only free up the memory
            // the tree's structure still pointing to that piece of memory;
            Node* pre = NULL; 
            while (it != NULL && it->left != NULL)
            {
                pre = it;
                it = it->left;
            }
            root->data = it->data;
            delete it;
            it = NULL;
            pre->left = NULL;
            return root;
        }
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
    /*
    Inorder traversal of the given tree
    20 30 40 50 60 70 80
    */
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl <<  "============" << endl;
    root = deleteNode(root, 20);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    /*
    Delete 20
    Inorder traversal of the modified tree
    30 40 50 60 70 80
    */
    cout << endl <<  "============" << endl;

/*
    root = insert(root,20);
    inorder(root);
    cout << endl;
*/  
    root = deleteNode(root, 30);  
    inorder(root);
    /*
    Delete 30
    Inorder traversal of the modified tree
    40 50 60 70 80
    */
    //cout << endl;
    cout << endl;
    root = deleteNode(root, 50);  
    inorder(root); 
    /*
    Inorder traversal of the modified tree
    40 60 70 80
    */
}