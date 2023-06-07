/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    static ListNode* findMid(ListNode* head){
        // function to find mid
        ListNode *slow = head, *fast = head-> next ;
        while(fast != NULL and fast-> next!= NULL){
            slow = slow-> next ; fast = fast->next-> next ;
        }

        // Examples:
        // LL1: 1-> 2-> 3 in this case mid would be Node 2
        // LL2: 1-> 2-> 3-> 4 in this case mid would be Node 2

        // we have to reverse the LL from Node 3 and 4 onwards

        return slow ;
    }

    static ListNode* reverse(ListNode *head){
        // normally reverse the LL
        ListNode *prev = NULL , *curr = head, *next ;
        while(curr != NULL){
            next = curr-> next ;
            curr-> next = prev ; prev = curr ; curr = next ;
        }
        return prev ;
    }

    bool isPalindrome(ListNode* head){
        // code here
        // case 1: empty or single element LL are always palindrome
        if(head == NULL or head-> next == NULL){return true ;}

        // we would be doing this ques in O(N) time and O(1) aux space

        // Step1: find mid
        // Step2: reverse the second half of the LL
        // step3: match the first half with second half

        ListNode* mid = findMid(head) ;

        // is node se hme reverse krna hain yaani ki mid k agle node se
        ListNode* temp = mid-> next ;

        // so we have to basically connect the reversed second half to the middle node
        mid -> next = reverse(temp) ;

        // so now lets compare the first half with second half
        ListNode *head1 = head, *head2 = mid-> next ;

        while(head2 != NULL){
            if(head1-> val != head2-> val){return false;}
            head1 = head1-> next ; head2 = head2-> next ;
        }
        return true ;
    }
};
// @lc code=end

