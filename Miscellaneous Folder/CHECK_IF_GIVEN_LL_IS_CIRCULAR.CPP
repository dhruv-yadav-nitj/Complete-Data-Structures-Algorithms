//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

// Condition 1: when we have no inner loops in LL

bool isCircular(Node *head){
    // since an empty LL is considered circular
    if(head == NULL){return true ;}

    // when only one node --> then we can check if the head-> next == NULL or not
    if(head-> next == NULL){return false ;}

    // now for multiple nodes
    Node* temp = head-> next ;
    while(temp != NULL and temp != head){
        temp = temp-> next ;
    }

    if(temp == NULL){return false ;}
    else{
        return true ;
    }
}

// Condition 2: When we have been given that there are inner loops in LL

// this has been covered in Floyd's Cycle Detection Algorithm