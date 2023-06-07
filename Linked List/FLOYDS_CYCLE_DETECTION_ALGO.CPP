// Floyd's Cycle Detection Algorithm
// Application of Floyd's Cycle Detection Algorithms --> Detect and Remove Loop in Linked List

// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// https://leetcode.com/problems/reverse-linked-list-ii/description/

#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data; Node* next;
    Node(int val){
        data = val; next = NULL;
    }
};

class Solution{
public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head){

        // first check if the loop is present or not

        // if the LL is empty or has only one node
        if(head == NULL or head-> next == NULL){
            return  ;
        }

        Node* slow= head; Node* fast = head ;
        while(slow != NULL and fast != NULL and fast-> next != NULL){
            slow = slow -> next ; fast = (fast->next)-> next ;
            // move slow one pos at a time and fast two pos at a time

            // if at any time slow == fast --> break
            if(slow == fast){break ;}
        }

        if(slow != fast){return ;} // this means loop exited due to NULL ptr --> which means no loop present

        // now since we have make assured that there is a loop in the LL, lets find the looping point of the loop --> by starting the slow from head
        slow = head ;

        // since it may happen that slow and fast meet at head as in the case of 1-> 2-> 3->4->5 and 5-> 1 so at this point slow and fast would meet at head point
        if(slow == fast){
            while(fast-> next != slow){
                fast = fast -> next ;
            }
        }

        else{
            while(slow -> next != fast-> next){
                slow = slow-> next ; fast = fast-> next ;
            }
        }

        // now we find the looping point
        fast -> next = NULL ;
    }
};

// Types of ques that can be asked based on this:

// Type 1: Detect if their is any internal loop in the given LL or not
// Type 2: return the starting index of the internal loop --> Leetcode Linked List 2
// Type 3: Detect and remove the loop --> GfG Practice Detect and Remove the Loop