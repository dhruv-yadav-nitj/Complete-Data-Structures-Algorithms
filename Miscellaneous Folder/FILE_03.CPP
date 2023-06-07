/*
this file contains:
--> Insertion in Linked List at Head, Tail and at Random Position
*/

#include <bits/stdc++.h>
using namespace std;

// An Alternate method to declare the class (using constructor) in order to minimise the memory allocation work
// always try to declare the class in this way as it reduces the lines of codes and also make it easy to understand by reducing the use of * in code
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// traversing and printing the linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node *&head, int new_data)
{
    Node *temp = NULL;
    temp = new Node(new_data);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, int new_data)
{
    Node *temp = NULL;
    temp = new Node(new_data);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
}

void insertAtRandom(Node *&head, int pos, int new_data)
{
    Node *temp = NULL;
    temp = new Node(new_data);

    if (pos == 1)
    {
        insertAtHead(head, new_data);
        return;
    }

    Node *curr = head;
    int count(1);
    while (count < pos - 1)
    {
        curr = curr->next;
        count++;
    }

    if (curr->next == NULL)
    {
        insertAtTail(head, new_data);
        return;
    }

    temp->next = curr->next;
    curr->next = temp;
}

int main(int argc, char const *argv[])
{
    // inserting elements in a Linked List
    // {
    // declaring an empty linked list
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node(10);
    second = new Node(20);
    third = new Node(30);

    // head->data = 10;
    head->next = second;

    // second->data = 20;
    second->next = third;

    // third->data = 30;
    third->next = NULL;

    // print the linked list
    print(head);
    // }

    insertAtHead(head, 90);
    print(head);

    insertAtTail(head, 80);
    print(head);

    insertAtRandom(head, 3, 70);
    print(head);

    return 0;
}
