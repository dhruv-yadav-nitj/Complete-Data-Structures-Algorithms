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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if(head == NULL) return NULL ;

        ListNode* curr = head ; ListNode* prev = NULL ;
        while(left > 1){
            prev = curr ; curr = curr-> next ;
            left-- ; right-- ;
        }
        ListNode* start = prev; ListNode* tail = curr ;
        ListNode* temp= NULL ;
        while (right > 0)
        {
            temp= curr-> next ;
            curr -> next= prev ;
            prev = curr ; curr = temp ; right-- ;
        }

        if(start != NULL){
            start -> next = prev ;
        }
        else{
            head = prev ;
        }

        tail-> next = curr ; return head ;        
    }
};