#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data; struct Node *next;
    Node(int x){
        data = x; next = NULL;}
};

// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Approach 1: using two while loops --> TC: O(n2)
// Approach 2: first sort the LL and then use the remove duplicates from sorted LL --> TC: O(nlogn)
// Approach 3: use hasmaps

class Solution{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head){
        unordered_map<int, bool> isVisited;
        if(head == NULL or head-> next == NULL){return head ;}
        Node* temp = head ; Node* prev = NULL ;
        while(temp != NULL){
            if(!isVisited[temp-> data]){
                isVisited[temp->data] = true ;
                prev = temp ; temp = temp-> next ;
            }
            else{
                prev-> next = (temp->next ) ;
                delete(temp) ;
                temp = prev->next ;
            }
        }
        return head ;

        // all test cases passed in one go , woohoo
    }
};