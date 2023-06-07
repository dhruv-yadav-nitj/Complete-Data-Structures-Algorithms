/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };

#include <bits/stdc++.h>
using namespace std ;

// approach 1: using hashtable
// use a set to store the addresses of the temp (since the address would be unique to a particular node) and if the s.count(temp)==1 means a particular node came again which means there's a loop in LL itself

// for better approach : use floyd's cycle detection algorithm

class Solution {
public:
    bool hasCycle(ListNode *head){
        set<ListNode*> s ;
        ListNode* temp = head ;
        while(temp != NULL and s.count(temp)==0){
            s.insert(temp) ;
            temp = temp-> next ;
        }
        if(temp == NULL){return false ;}
        else{
            return true ;
        }
    }
};
// @lc code=end

