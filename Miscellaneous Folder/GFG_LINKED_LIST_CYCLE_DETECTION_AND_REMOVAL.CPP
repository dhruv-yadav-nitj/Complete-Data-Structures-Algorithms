#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct Node {
    int data ; Node* next ;
    Node (int data){
        this-> data = data ; next = NULL ;
    }
};

class Solution{
public:
        //Function to remove a loop in the linked list.
    void removeLoop(Node* head){
        // code here
        // just remove the loop without losing any nodes

        // no need to worry if the linked list is empty or has only one node
        if(!head or !(head-> next)){return ;}

        // step 1 : loop detection
        Node*slow = head, *fast = head ;

        while(fast and fast-> next){

            // move slow one step at a time and fast two steps at a time
            slow = slow -> next ; fast = fast -> next -> next ;

            // if at any time slow equals fast then loop is present --> remember to write this line after the first one bcz if u write this line before moving the pointers --> TLE would hit ya
            if(slow == fast ){
                break ;
            }
        }

        if(slow != fast){
            return ; // no loop present --> loop exited because it got terminated due to presence of NULL pointer
        }

        // else

        // step 2 : removal of loop

        slow = head ;
        if(slow == fast){
            while(fast ->next != slow){
                fast = fast -> next ;
            }
        }
        else{
            while(slow -> next != fast -> next){
                slow = slow -> next ; fast = fast -> next ;
            }
        }

        fast -> next = NULL ;
    }
};