typedef struct Node
{
    int data;
    Node *next;
} Node;

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    int size();
    void print();
    void addFirst(int i);
    void addLast(int i);
    void deleteFirst();
    void deleteLast();
    void reverse();
};