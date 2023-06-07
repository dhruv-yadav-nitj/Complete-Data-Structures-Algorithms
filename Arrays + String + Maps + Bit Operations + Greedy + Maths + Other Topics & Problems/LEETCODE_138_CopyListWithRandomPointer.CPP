/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val; Node *next; Node *random;

    Node(int _val){
        val = _val; next = NULL; random = NULL;
    }
};

class Solution{
public:
    Node *copyRandomList(Node *head){
        // code here
        if(head == NULL){return NULL ;}
        Node* temp = head; // pointer for iterating the original LL
        Node* dup ; // duplicate linked list which would be our copy of the original LL
        dup = new Node(temp->val);
        Node* ans ; ans = dup ; // it would be returned at last
        unordered_map<Node*, Node*> m ; m[temp] = dup ;
        while(temp -> next != NULL){
            dup-> next = new Node(temp-> next -> val) ;
            temp = temp -> next ; dup = dup-> next ;
            m[temp]= dup ; // mapping the head node with dup node
        }
        temp = head ;
        while(temp != NULL){
            m[temp]-> random = m[temp-> random] ; // connecting the new nodes in the new duplicate list
            temp = temp-> next ;
        }

        // Time Complexity: O(N)
        // Aux Space: O(N)

        return ans ;
    }
};
// @lc code=end
