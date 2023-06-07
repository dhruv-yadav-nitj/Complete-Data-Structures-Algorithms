#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* merge (ListNode* list1 , ListNode*list2){
        ListNode* curr1= list1 , *fwd1 = curr1 -> next , *curr2 = list2, *fwd2 ;
        
        /* ye to clear hain ki list1 ka head list2 k head se either cchota hain ya equal hain to is case mein teen baatein ho skti hain, ki
        list1 mein sirf ek element ho --> is case mein fwd NULL hoga --> is case mein sirf list2 ko list1 k aage lga dena hain , 2nd case -->
        ki jo fwd hain wo NULL nhi hain --> jo list2 ka head hain wo list1 k head se badha hain ya equal hain but fwd se cchota hain is case
        mein list1 k head -> next list2 k head mein lgega aur pointers aage badh jaaenge bs aur 3rd case list2 ka head fwd se bhi badha hain
        is case mein dono pointers ka bs aage bdhana hain */

        // case 1
        // if list1 is having only one element
        if(!fwd1){curr1 -> next = curr2 ; return list1 ;}

        while(curr1 != NULL and curr2 != NULL){
        // case 2
            if(curr2 -> val >= curr1 -> val and curr2 -> val < fwd1 -> val){
                fwd2 = curr2 -> next ;
                curr1 -> next = curr2 ; curr2 -> next = fwd1;
                curr1= curr1 -> next ; curr2= fwd2 ;    // is case mein fwd1 to change hi nahi hoga na bcz hmne list1 mein curr aur fwd k beech mein new element ghusaya hain usase curr pr to changes honge but fwd pr koi change nhi hoga
            }
        // case 3
            else{
                
                // aisa ho skta hain ki curr2 , curr1 se aur fwd1 se dono se badha hain --> aise mein curr1 aur fwd1 ko aage badha do ek step
                curr1 = curr1 -> next ; fwd1 = fwd1 -> next ;

                // ab aisa ho skta hain ki 
                if(fwd1 == NULL){
                    curr1 -> next = curr2 ; return list1 ;
                }
            }

        }return list1 ;

    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // code here

        ListNode *head1= list1 , *head2 = list2 ;
        if(!head1){return head2 ;} // agar list1 empty nikal gya to
        if(!head2){return head1 ;} // agar list2 empty nikal gya to

        if(head1 -> val <= head2 -> val){return merge(list1 , list2) ;}
        else{
            return merge(list2 , list1) ;
        }
        
    }
};