#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    ListNode* duplicate(ListNode* head){
        // function to duplicate the LL
        ListNode* curr = head ; // to iterate over the original LL
        ListNode* newHead = NULL ; // head of the duplicate LL
        ListNode* tail = NULL ; // points the last node in duplicate LL
        while(curr != NULL){
            if(newHead == NULL){
                newHead  = new ListNode(curr->val) ; newHead -> next = NULL ;
                tail = newHead ;
            }
            else{
                ListNode* temp = NULL ; temp = new ListNode(curr -> val) ;
                tail-> next = temp ; tail = tail-> next ; tail-> next = NULL ;
            }
            curr = curr -> next ;
        }
        return newHead ;
    }

    void reverseList(ListNode* &head)
    {
        ListNode* curr = head; ListNode* prev =NULL ; ListNode* fwd = curr->next ; 
        while (curr != NULL)
        {
            fwd =curr-> next ;
            curr-> next = prev ; prev= curr ; curr= fwd ;
        }
        head = prev;
    }

public:
    bool isPalindrome(ListNode *head){
        // code here
        if(head == NULL or head -> next == NULL){return true ;}
        ListNode* newHead = duplicate(head) ; reverseList(head) ;

        while(head != NULL){
            if(head->val != newHead-> val){return false ;}
            head = head-> next ; newHead = newHead -> next ;
        }
        return true ;
    }
};