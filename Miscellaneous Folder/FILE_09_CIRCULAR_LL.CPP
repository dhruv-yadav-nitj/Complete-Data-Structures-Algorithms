#include <bits/stdc++.h>
using namespace std;

// this file contains: Circular Linked List
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;

    // yrr dekho agar hmlog isme while loop use krenge to ek edge case hain jb single node rhegi to ye print nhi kr paaega phir hm log ko usko alag se print krna pdhega, so why not use do-while loop


    // always remember one thing we should use do-while loop to traverse the circular linked list
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "NULL" << endl;
}

// Error: this function works perfect for any linked list other than empty linked list and I think problem is not in the code but in the declaration of an empty linked list
void insertAtHead(Node *&head, int new_data)
{
    // new_data ko andar ghusaane ka poora taiyaari kr lie
    Node *temp = NULL; temp = new Node(new_data);

    temp->next = head;
    Node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = temp;
    head = temp;
}

void insert(Node *&head, int new_data, int pos)
{
    Node *temp = NULL;
    temp = new Node(new_data);
    if (pos == 1)
    {
        insertAtHead(head, new_data);
        return;
    }
    else
    {
        // valid for tail as well
        int count(1);
        Node *curr = head;
        while (count < pos - 1)
        {
            curr = curr->next;
            count++;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deletion(Node *&head, int pos)
{
    // pos denotes kaun se position ka element delete maarna hain
    if (pos == 1)
    {
        Node *temp = head;
        Node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        head = head->next;
        curr->next = head;
        delete temp;
    }
    else
    {
        Node* curr = head; Node* prev = NULL ;
        int count(1) ;
        while (count < pos)
        {
            prev = curr ;curr = curr-> next ;
            count++ ;
        }
        prev-> next = curr-> next ; delete curr ;        
    }
    
}

int main(int argc, char const *argv[])
{
    // forming linked list
    Node *head = NULL; Node *second = NULL; Node *third = NULL;
    head = new Node(1); second = new Node(2); third = new Node(3);
    head->next = second; second->next = third; third->next = head;

    print(head);

    insertAtHead(head, 4);
    print(head);

    // case to be re-considered :- suppose we have an empty linked list
    // Node* empty = NULL; insertAtHead(empty , 10) ; print(empty) ;

    insert(head, 5, 1) ; print(head) ; // using insert function to insert at head
    insert(head, 6, 4) ; print(head) ; // using insert fx to insert at some random
    insert(head, 7, 7) ; print(head); // using insert fx to insert at tail

    deletion(head, 1) ; print(head);
    deletion(head, 5); print(head) ;
    deletion(head, 5); print(head) ;
    
    insert(head, 7, 5) ; print(head);

    return 0;
}
