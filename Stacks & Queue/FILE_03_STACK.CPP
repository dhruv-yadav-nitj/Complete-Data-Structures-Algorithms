// this file contains: stack implementaion using Linked List

#include <bits/stdc++.h>
using namespace std ;

class Node{
public:
    int data ; Node* next ;
    Node(int new_data)
    {
        this-> data = new_data ; this-> next= NULL ;
    }
} ;

class Stack
{
public:
    int size ; Node* head ;
    Stack()
    {
        this-> head = NULL ; this-> size = 0 ;
    }

    void push(int data)
    {
        if(head== NULL){
            Node* node = NULL ; node = new Node(data) ;
            head= node ;
        }
        else{
            Node* node = NULL; node =new Node(data); 
            node-> next = head ; head =node; 
        }
    }

    int peek(){
        if(head== NULL){cout << "Stack Empty" << endl ; return -1 ;}
        else{
            return head -> data ;
        }
    }

    void pop(){
        size-- ; Node* temp = head ; head = head-> next ; temp-> next = NULL ; delete temp ;
    }

    bool isEmpty(){
        return (head == NULL) ;
    }
};

int main(int argc, char const *argv[])
{
    Stack s1 ; s1.push(3) ; s1.push(2) ; s1.push(1) ;
    cout << s1.peek() << endl;
    s1.pop() ; cout << s1.peek() << endl;

    if(s1.isEmpty()){cout << "Stack is Empty" << endl;} else{cout << "NO" << endl;}
    return 0;
}
