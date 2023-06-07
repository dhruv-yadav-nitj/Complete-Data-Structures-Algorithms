#include <bits/stdc++.h>
using namespace std;

// Topics Covered in this File:
/*
1. Creating Linked List
2. Traversing Linked List (Printing the elements in Linked List)
3. Insertion in Linked List - At Head, At Tail, At Random Position
*/

class Node
{
public:
    // let say this node stores some data in the form of int
    int data;

    // node also stores the address to the next node
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// insert at Head
// So to insert at head we need to change the null pointer of the new node and change the head to the new element
void InsertAtHead(Node *&head, int d)
{
    // function to insert an element at the head of the linked list
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    // function to insert the element at tail position
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtRandom(Node *&tail, Node *&head, int pos, int d)
{
    if (pos == 1)
    {
        // condition to insert at Start
        InsertAtHead(head, d);
        return;
    }

    Node *nodeToBeInserted = new Node(d);

    Node *temp = head;
    int count(1);
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    // condition to insert at Tail
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    nodeToBeInserted->next = temp->next;
    temp->next = nodeToBeInserted;
}

// function to traverse a linked list
void printLinkedList(Node *head)
{
    // function to print the Linked List
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Node *node1 = new Node(10);
    cout << "DATA: " << node1->data << " "
         << "Next Node at: " << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    cout << "Head is: " << head << endl; // this line would printing the address of the head

    InsertAtHead(head, 12);
    cout << "LL after inserting 12 at Head: " << endl;
    printLinkedList(head);

    cout << "LL after inserting 17 at Head: " << endl;
    InsertAtHead(head, 17);
    printLinkedList(head);

    InsertAtTail(tail, 69);
    cout << "LL after inserting 69 at Tail: " << endl;
    printLinkedList(head);

    insertAtRandom(tail, head, 5, 8);
    cout << "LL after inserting 8 at Pos = 3: " << endl;
    printLinkedList(head);

    return 0;
}