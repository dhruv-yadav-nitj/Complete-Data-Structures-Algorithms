/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        
        // if the LL is empty or has only one node
        if(head == NULL or head-> next == NULL){
            return NULL ;
        }

        ListNode* slow = head ; ListNode* fast = head ;
        while(slow != NULL and fast != NULL and fast-> next!= NULL){
            
            // move the slow ptr one at a time and fast ptr two pos at a time
            slow = slow -> next ;
            fast = (fast-> next) -> next ;

            if(slow == fast){break ;}
        }

        if(slow != fast){
            // it means that loop exited due to some NULL ptr
            // which means there's no loop inside the LL
            return NULL ;
        }

        // but since there's a loop inside the LL we are here
        slow = head ;
        while(slow != fast){
            slow = slow -> next ;
            fast= fast-> next ;
        }
        return slow ;
    }
};
// @lc code=end