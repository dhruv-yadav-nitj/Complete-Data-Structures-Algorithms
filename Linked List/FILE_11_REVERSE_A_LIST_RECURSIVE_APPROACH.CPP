#include <bits/stdc++.h>
using namespace std ;

class Node{
public:
    int data ; Node* next = NULL ;
    Node(int data)
    {
        this-> data = data; this-> next = next ;
    }
};

// https://leetcode.com/problems/reverse-linked-list/submissions/858076362/

void reverse(Node* &head, Node* curr, Node* prev)
{
    // recursive approach to reverse a singly linked list

    // base condition
    if (curr == NULL)
    {
        head = prev ; return ;
    }

    Node* fwd = curr-> next ; // ab jo fwd hain na wo as a curr pass hoga aur jo curr hain na wo as a prev pass hoga
    reverse(head, fwd, curr) ;

    curr-> next = prev ;    
}

void push(Node* &head, int dat)
{
    Node* temp = NULL ;temp = new Node(dat) ;
    temp-> next= head ; head = temp ;
}

void print(Node* head)
{
    while (head != NULL)
    {
        cout << head-> data << " -> " ;
        head= head-> next ;
    }cout << "NULL" << endl ;
    
}

int main(int argc, char const *argv[])
{
    cout << "Original Linked List: " ;
    Node* head= NULL ; push(head, 1) ; push(head, 2) ; push(head, 3) ; push(head, 4); print(head);

    cout << "Reverse Linked List: " ; reverse(head, head, NULL) ; print(head) ;

    return 0;
}
