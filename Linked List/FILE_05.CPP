
// this file contains:
// Deletion in Linked List
// now deletion k lie either hme koi position bol dia jaaega ki is position pr jaakr delete kro ya bol bol dega koi value aur bolega ki is value ka koi occurence delete kro

// also position can be head, tail or any randome position of the linked list

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data; 
    Node* next ;

    // constructor
    Node (int data)
    {
        this-> data = data;
        this-> next = NULL ;
    }
};

// function to print the linked list
void print(Node* pos)
{
    while (pos != NULL)
    {
        cout << pos->data << " -> " ;
        pos = pos-> next ;
    }cout << "NULL"  << endl;
}

// function to perform deletion
void deletion(int pos, Node* &head)
{
    if (pos == 1)
    {
        // iska mtlb head ko delete krna pdhega
        Node *temp = head; 
        head = head-> next ;

        temp -> next = NULL ;
        delete temp ;
    }
    else
    {
        int count = 1 ; Node* prev = NULL ; Node* curr = head ;
        while (count < pos)
        {
            prev = curr ;
            curr = curr-> next;
            count++ ;
        }

        prev-> next = curr-> next ;
        curr -> next = NULL ;
        delete curr;
    }    
}

int main(int argc, char const *argv[])
{

    // initialising and declaring linked list
    Node* head= NULL ; Node* second = NULL ; Node* third = NULL ; Node* fourth = NULL ;
    head = new Node(1) ; second = new Node(2) ; third = new Node(3) ; fourth = new Node(4) ;
    head -> next = second ; second -> next = third ; third -> next = fourth ;

    print(head) ;

    deletion(2, head) ;
    print(head) ;

    deletion(2, head); print(head);

    deletion(1, head); print(head);

    return 0;
}