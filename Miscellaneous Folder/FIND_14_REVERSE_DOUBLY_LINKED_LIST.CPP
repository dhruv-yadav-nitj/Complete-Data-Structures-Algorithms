#include <bits/stdc++.h>
using namespace std ;

class Node{
public:
    int data ; Node* next ; Node* prev ;

    Node(int data)
    {
        this-> data = data ; this-> next = NULL ; this-> prev = NULL ;
    }
};

void print(Node* head)
{
    cout << "NULL -> " ;
    while (head != NULL)
    {
        cout << head-> data << " <-> " ; head = head-> next ;
    }cout << "NULL" << endl;    
}

void push(Node* & head, int dat)
{
    Node* temp = NULL; temp = new Node(dat);
    temp -> prev = NULL ; temp -> next = head ; head =temp ; head-> prev = NULL ;
}

void reverse(Node* &head, Node* curr, Node* prev, Node* fwd)
{
    // iterative approach
    if (head == NULL or head-> next == NULL)
    {
        return ;
    }
    
    while (curr->next != NULL)
    {
        curr-> next = prev; curr-> prev = fwd ; prev = curr ; curr =fwd ; fwd = fwd-> next ;
    }
    // we are handling this case separetely bcz , agar hm log isko bhi loop k andar rkh denge aur condition likh denge curr != NULL ; then kya hoga ki jo fwd hoga wo NULL-> next likhna pdhega jo ki invalid hain NULL ka next kuch nhi hota.
    curr-> next = prev ; curr-> prev = NULL ; head = curr ;
}

Node* recursion(Node* node)
{
    // if list is empty then it is the only thing we can do
    if(node == NULL) {return NULL ;}
    else
    {
        Node* temp = node-> next ;
        node-> next = node-> prev ;
        node-> prev = temp ;

        if (node-> prev == NULL)
        {
            // notice that ki hmne uppar node-> prev ko change kr dia hain ab ye NULL tbhi point krega jb ye last element pr rhega aur hmara head hoga 
            // base condition
            return node ;
        }
        return recursion(node-> prev) ; 
    }
}

int main(int argc, char const *argv[])
{
    cout << "Original Linked List: " ;
    Node* head= NULL ; push(head, 1); push(head, 2); push(head, 3) ; push(head, 4); print(head);

    cout << "Reversed Linked List: " ;
    reverse(head, head, NULL, head-> next) ; print(head);

    // lets try out with a linked list having a single element only
    Node* doubly= NULL ; doubly = new Node(100) ; print(doubly) ; reverse(doubly, doubly, NULL, NULL) ; print(doubly) ;

    // recursive try
    head = recursion(head) ; print(head) ;
    
    return 0;
}