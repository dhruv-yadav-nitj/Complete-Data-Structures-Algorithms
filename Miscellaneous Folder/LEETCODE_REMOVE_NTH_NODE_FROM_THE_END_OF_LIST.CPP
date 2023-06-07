#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getSize (ListNode* head){


        if(!head){return 0 ;}

        int count=0;
        while(head != NULL){
            count++ ; head = head ->next ;
        }
        return count ;
    }

    ListNode* removeNode (ListNode* &head , int k){

        if(k ==1){

            // means we have to remove first node
            ListNode* newHead = head -> next ; head -> next = NULL ; return newHead ;
        }

        ListNode* curr = head , *prev = NULL ;

        int cnt = 1 ;
        while(cnt < k and curr != NULL){
            prev = curr ; curr = curr -> next ; cnt++ ;
        }

        prev -> next = curr -> next ; curr -> next == NULL ;
        
        return head ;

    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int size = getSize(head) ; int k = size - n + 1 ;
        // now we have to remove kth node from start
        return removeNode(head, k) ;
    }
};