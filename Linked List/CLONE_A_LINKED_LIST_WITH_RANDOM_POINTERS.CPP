// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node{
    int data; Node *next; Node *arb;
    Node(int x){
        data = x; next = NULL; arb = NULL;
    }
};

// } Driver Code Ends
class Solution{
public:

// this solution is having TC: O(N) and Aux Space: O(N) for hash map
    Node *copyList(Node *head){
        
        // notice that we are having a node with data, next pointer and an arbitrary pointer
        Node *temp, *dup ;
        unordered_map<Node*, Node*> m ;
        temp = head; dup = new Node(temp-> data) ;
        m[temp] = dup ;

        while(temp-> next != NULL){
            dup -> next = new Node(temp-> next -> data) ; // basically hm yha kr rhe hain na ki , ek node bana rhe hain jiski value hain temp-> next ki val aur isi k saath hm use dup k next mein appoint kr de rhe hain
            temp = temp -> next ;
            dup = dup -> next ;
            m[temp] = dup ;
        }
        dup-> next = NULL ; // terminate the duplicate wala LL
        temp = head ;

        while(temp != NULL){
            m[temp]-> arb = m[temp-> arb] ;
            temp= temp-> next ;
        }
        return m[head] ;
    }
};