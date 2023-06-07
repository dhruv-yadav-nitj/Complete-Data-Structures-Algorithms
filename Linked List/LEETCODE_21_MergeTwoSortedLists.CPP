/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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

// very important question --> asked many times in interviews

class Solution {
public:
    static ListNode* solve(ListNode* list1, ListNode* list2){
        ListNode* curr = list1 ; ListNode* fwd = list1-> next ; ListNode* temp = list2; ListNode* temp2;

        // edge case: if single element is present in list1
        if(fwd == NULL){
            curr -> next = temp ;
            return list1 ;
        }

        while(fwd != NULL and temp != NULL){
            if(temp->val >= curr-> val and temp-> val < fwd-> val){
                temp2 = temp-> next ;
                curr-> next = temp ; temp -> next = fwd ; // beech mein ghusa die
                curr = curr-> next ; temp = temp2 ; // aage bdha die
            }
            else{
                curr = fwd ; fwd = fwd-> next ;

                // ab agar list 1 khtm ho gyi to simply list1 ke end mein list2 ghusa do
                if(fwd == NULL){
                    curr-> next = temp ;
                    return list1 ;
                }
            }
        }
        return list1 ;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        // code here

        // first handle the case 1 and case 2 --> written in notebook
        if(list1 == NULL){return list2 ;}
        if(list2 == NULL){return list1 ;}

        // main-code

        if(list1->val <= list2->val){
            return solve(list1, list2) ;
        }
        else{
            return solve(list2, list1) ;
        }
    }
};
// @lc code=end

