
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *deleteMiddle(ListNode *head)
    {

        int n(0);
        ListNode *temp = head;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        int mid = n / 2;

        if (n == 0 or n == 1)
        {
            return NULL;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;
        int count(0);

        while (count < mid)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        free(curr);

        return head;
    }
};