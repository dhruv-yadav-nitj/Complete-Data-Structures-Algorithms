/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

// asked in : adobe | airbnb | amazon | bloomberg | microsoft

/* struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution{
public:
    static void push(ListNode* &head, int data){
        ListNode* temp = new ListNode(data) ;
        if(head == NULL){
            head = temp ;
        }
        else{
            ListNode* temp = new ListNode(data) ;
            ListNode* tail = head ;
            while(tail-> next != NULL){
                tail = tail-> next ;
            }

            tail -> next = temp ; temp -> next = NULL ;            
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        // code here
        ListNode *ans = NULL; int carry(0) ;
        while(l1 != NULL or l2 != NULL or carry != 0){
            int val1 = 0, val2=0 ;
            if(l1 != NULL){val1 = l1->val ;}
            if(l2 != NULL){val2 = l2-> val ;}

            int sum = carry + val1 + val2 ;
            int digit = sum%10 ; carry = sum/10 ;

            push(ans, digit) ;

            if(l1 != NULL){l1 = l1 -> next ;}
            if(l2 != NULL){l2 = l2-> next ;}
        }

        return ans ;
    }
};
// @lc code=end

