#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Microsoft Interview Round Last Question

class Solution
{
public:
    void deleteNode(ListNode *node)
    {

        // just redefine the pointers

        *(node) = *(node->next);
    }
};