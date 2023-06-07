
// This file contains:
// Doubly Linked List

#include <bits/stdc++.h>
using namespace std ;

class Node{
public:
// doubly linked list contains three type of data in its pocket: a data, a pointer to the previous node and a pointer to the next node
    int data ; Node* prev; Node* next ;
    Node(int data)
    {
        this-> data = data;
        this-> prev = NULL ;
        this-> next = NULL ;
    }
};

// printing is as same as the Singly Linked List
void print(Node* head)
{
    Node* temp = head; 
    while (temp!= NULL)
    {
        cout << temp-> data << " -> " ;
        temp = temp-> next ;
    }cout << "NULL" << endl;
}

void insertAtHead(Node* &head, int new_data)
{
    // function to insert the element at start of the linked list
    Node* temp = NULL ; temp = new Node(new_data); temp-> prev = NULL ;
    temp-> next = head ; head -> prev = temp ;
    head = temp ;
}

// ek cheej yaad rkhe ki jha pr head change krne ka jroorat hain wha & pass kre (obviously) and jha head change krna ka jroorat nhi hain wha sirf head pass kre

void insertTail(Node* head, int new_data)
{
    // function to insert the element at the last of the linked list
    Node* temp = head;
    while (temp-> next != NULL)
    {
        temp = temp-> next ;
    }
    Node* curr= NULL ; curr = new Node(new_data) ;
    temp -> next = curr ; curr-> prev = temp ;
}

void insertRandom (Node* &head, int pos, int new_data)
{
    if (pos == 1)
    {
        insertAtHead(head, new_data);return ;
    }
    else
    {
        Node* curr = head;  int count(1); Node* previous =  NULL ; Node* temp = NULL; temp = new Node(new_data) ;
        while (count < pos)
        {
            previous = curr ; curr = curr->next ;
            count++ ;
        }
        previous-> next= temp ; temp->prev = previous ; temp-> next = curr ; curr-> prev = temp;        
    }   
}

// function to delete the node
void deletion(Node* &head, int pos)
{
    Node* curr = head ; Node* prev = NULL ;
    if (pos == 1)
    {
        Node* temp = head;
        head = head-> next ; 
        delete temp ;
    }
    else
    {
        int count(1);
        while (count < pos)
        {
            prev = curr ; curr = curr->next ; count++;
        }
        if (curr-> next == NULL)
        {
            prev-> next = NULL ;
            delete curr ;
        }
        else
        {
            prev-> next = curr-> next ;
            (curr-> next)->prev = prev ; delete curr ;
        }        
    }
}

int main(int argc, char const *argv[])
{
    // assiging Linked List
    Node* head = NULL ; Node* second = NULL ; Node* third = NULL ; Node* tail = NULL ;
    head = new Node(1) ; second = new Node(2) ; third = new Node(3) ; tail= new Node(4);
    head-> next = second ; second -> next = third ; third-> next = tail;

    print(head) ;

    insertAtHead(head, 5); print(head);
    insertAtHead(head, 6); print(head);
    insertAtHead(head, 7); print(head);
    insertAtHead(head, 8); print(head);

    insertTail(head, 9) ; print(head);

    insertRandom(head, 7, 100) ; print(head);

    deletion(head, 7) ; print(head);


    return 0;
}
