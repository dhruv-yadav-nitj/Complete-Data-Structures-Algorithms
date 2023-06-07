/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leetcode pr shayad free(address) kaam nhi krta --> was giving error when i used it previously

class Solution{
public:

    // iterative approach --> TC: O(n) and SC: O(1)
    ListNode* deleteDuplicates(ListNode* head){
        if(head == NULL){return head ;} // if LL is empty return as it is
        ListNode* temp = head ;
        while(temp-> next != NULL){
            if(temp->val == (temp->next) ->val){
                ListNode* del = temp->next ;
                temp->next = (temp->next)->next ;
                delete(del) ;
            }
            else{
                temp = temp->next ;
            }
        }
        return head ;
    }

    // recursive approach: TC: O(n) and SC: O(n)
    ListNode* deleteDuplicates(ListNode* head){
        // base case
        if(head == NULL){return NULL ;}
        
        if(head -> next != NULL){
            if(head ->val == (head->next)->val){
                ListNode* temp = head->next ;
                head -> next = (head->next)->next ;
                delete(temp) ;
                deleteDuplicates(head) ;
            }
            else{
                deleteDuplicates(head->next) ;
            }
        }
        return head ;
    }
};
// @lc code=end

