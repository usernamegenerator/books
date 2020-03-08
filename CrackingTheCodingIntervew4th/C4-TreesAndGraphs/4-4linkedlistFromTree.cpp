// 4.4 Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth
// (eg, if you have a tree with depth D, you’ll have D linked lists).

#include <iostream>
#include <queue>
#include <vector>
#include <list>
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
        root->data = data;
        root->left = NULL;
        root->right = NULL;
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
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void bfs(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> *nextLevelQ = new queue<Node *>;
    vector<list<Node *>> v;
    // root level
    nextLevelQ->push(root);
    int level = 0;
    v.resize(level + 1);
    v[level].push_back(root);

    for (auto x : v[level])
    {
        cout << x->data << " ";
    }
    cout << endl;

    // root level created at this time
    // the for loop iterate through the current level by
    // record how many elements in current level, and use for loop to finish current level
    // then if current level nodes have child, add the children to the same queue
    // the queue isn't empty. But the for loop only iterates the number of element in current level
    // once the for loop finishes, next time it enters,
    // it enters with all elements in next level and the number of them

    while (!nextLevelQ->empty())
    {
        level++;
        v.resize(level + 1);
        // track how many items at current level
        int thislevelSize = nextLevelQ->size();
        // cout << thislevelSize << endl;
        // only iterate the number of the current levels
        for (int i = 0; i < thislevelSize; i++)
        {
            // push the elements in current level to the linked list
            Node *temp = nextLevelQ->front();
            nextLevelQ->pop();
            v[level].push_back(temp);

            // if it has children, add to the queue
            // but this round of the for loop won't process
            if (temp->left != NULL)
                nextLevelQ->push(temp->left);
            if (temp->right != NULL)
                nextLevelQ->push(temp->right);
        }
        // after exit the for loop
        // this level is done
        cout << "level " << level << endl;
        for (auto x : v[level])
        {
            cout << x->data << " ";
        }
        cout << endl;
    }
}

int main()
{
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    cout << endl;

    bfs(root);
}