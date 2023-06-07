#include <bits/stdc++.h>
using namespace std ;

// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=1

// this ques on leetcode is a li'l bit different from here. read carefully

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

Node* kReverse(Node* head, int k){
    // code here
    // for approach and intuition see the notes

    // base condition
    if(head == NULL){return NULL ;}

    Node* curr = head; Node* prev= NULL ; Node* next= NULL ;
    int count(0) ;
    while(curr != NULL and count < k){
        next = curr -> next ;
        curr-> next = prev ;
        prev = curr ; curr = next ;
        count++ ;
    }

    if(next != NULL){
        head -> next = kReverse(next, k) ;
    }

    return prev ;
    // why prev --> do a dry run and you would understand
}