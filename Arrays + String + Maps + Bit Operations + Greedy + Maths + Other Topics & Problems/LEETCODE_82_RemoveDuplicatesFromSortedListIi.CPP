/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head){
        // code here
        // if the LL is empty or has only one element then return as it is
        if(head == NULL or head->next == NULL){return head ;}

        // first we need to fix the head
        bool check = false; 
        if(head->val == (head->next)->val){check = true ;}
        while(check){
            while(head != NULL and head->next!= NULL and head->val == (head->next)->val){
                ListNode* temp = head ; head= head->next ; delete(temp) ;
            }
            ListNode* temp = head ; head= head->next ; delete(temp) ;
            check= false; 
            if(head != NULL and head->next!= NULL and (head->val == (head->next)->val)){
                check = true ;
            }
        }

        // now we have head and its working fine as checked using custom TCs
        if(head == NULL or head->next == NULL){return head ;}

        ListNode* prev = head ; ListNode* curr = (head->next) ;
        while(curr != NULL and curr->next != NULL){
            if(curr->val != (curr->next)->val){
                prev = curr ; curr = curr->next ;
            }
            else{
                while(curr != NULL and curr->next != NULL and curr->val == curr->next->val){
                    curr = curr->next ;
                }
                curr = curr->next ;
                prev ->next = curr ;
            }
        }
        return head ;
    }
};
// @lc code=end

