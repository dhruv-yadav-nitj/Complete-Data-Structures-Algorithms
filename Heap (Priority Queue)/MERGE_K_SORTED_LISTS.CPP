

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// approach 1 : brute force
// traverse through every node of all the lists --> store them in an array --> sort the array --> convert array into linked list and return

// approach 2: divide and conquer and merge sort technique

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// approach 3: using min heap
// just copy and paste the method applies in merging k sorted array but this time use linked list

class comparator{
public:
    bool operator()(ListNode* a , ListNode* b) {

        return a -> val > b -> val  ;
    }
} ;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // code here

        priority_queue<ListNode* , vector<ListNode*>  , comparator> pq ;

        for(auto x : lists){
            // x is some head node
            
            // dont insert those x's which are pointing to NULL
            if(x != NULL){pq.push(x) ;}
        }

        ListNode* ans = new ListNode(-1) ; ListNode* temp = ans ;

        while(!pq.empty()){
            ListNode* tempHead = pq.top() ; pq.pop() ;

            temp -> next = tempHead ; temp = temp -> next ;
            if(tempHead -> next != NULL){
                pq.push(tempHead -> next ) ;
            }
        }
        return ans -> next ;
    }
};