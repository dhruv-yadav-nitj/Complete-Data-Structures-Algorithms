#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if(head == NULL){return NULL ;} // when empty linked list
        if(head-> next == NULL or (head-> next)-> next == NULL){
            return head ;
        } // when the size of ll is 1 or 2 we need not do anything

        // when size if greater than or equal to 3
        ListNode* oddHead = head; ListNode* evenHead = head-> next ; ListNode*odd = head ; ListNode* even = head-> next ; ListNode* curr = (head-> next)-> next ;
        while(curr != NULL){
            odd-> next = curr ; 
            odd = odd-> next ;
            even -> next = curr-> next ;
            if(even-> next != NULL){
                even = even -> next ;
            }
            if(curr-> next == NULL){
                break ;
            }
            curr = (curr-> next)-> next ;
        }
        odd-> next = evenHead ; head= oddHead ; even-> next = NULL ;

        return head;
    }
};