#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data;
    struct Node* next;
};

bool isSorted(struct Node* head){
    // to check if the LL is sorted in descending order or not
    if(head == NULL or head-> next == NULL){
        return true ;
        // since empty LL or LL with single element is always sorted
    }

    Node* temp= head ;
    while(temp -> next != NULL){
        if(temp->data < (temp-> next)-> data){
            return false; 
        }
        temp = temp -> next ;
    }
    return true ;
}