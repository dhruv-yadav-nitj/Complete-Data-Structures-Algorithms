
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {

        // first make a copy of the given node
        ListNode *temp = node->next;

        // now lets edit the address the given node is pointing to and make it to the next node's address, such that the node prev to the given node now points to the next node of the given node instead of pointing to the given node
        *node = *(node->next);

        // now lets delete the given node
        delete temp;
    }
};