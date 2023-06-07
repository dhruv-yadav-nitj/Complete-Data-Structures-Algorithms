#include <bits/stdc++.h>
using namespace std;

// this file contains:
// representation of a linked list
// traversing the linked list

// representation of Linked List
class Node
{
public:
    // data part
    int data;
    Node *next;
};

// traversing the linked list (printing the linked list)
void printLL(Node *pos)
{
    while (pos != NULL)
    {
        cout << pos->data << " ";
        pos = pos->next;
    }
    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Node *second = NULL;
    Node *tail = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    tail = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = tail;

    tail->data = 3;
    tail->next = NULL;

    // printing and traversing the Linked List
    printLL(head);

    return 0;
}
