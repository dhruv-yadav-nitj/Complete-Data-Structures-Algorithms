// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to check whether the list is palindrome.

    // Approach 1: using stack or simply we can use arrays or string as well
    // TC: O(N) and SC: O(N)
    bool isPalindrome(Node *head){
        // Your code here
        stack<int> s ;
        Node* temp = head ;
        if(temp == NULL or temp-> next == NULL){return true ;} // if the LL is empty or has only one element then it is by default palindrome
        while(temp != NULL){
            // insert the element into stack
            s.push(temp->data) ;
            temp = temp-> next ;
        }
        temp = head ;
        // now compare stack top with temp again
        while(!s.empty() and temp != NULL){
            if(s.top() != temp-> data){return false;}
            s.pop() ; temp= temp-> next ;
        }

        return true ;
    }

    // Approach 2: by reversing the next middle half of the LL and comparing with the first half
    // TC: O(N) and Aux Space: O(1)
    Node* getMid(Node * head){
        Node *slow, *fast ;
        slow = head ; fast = head-> next ;
        while(fast != NULL and fast-> next != NULL){
            slow = slow-> next ;
            fast = (fast-> next)-> next ;
        }
        return slow ;
    }

    Node* reverse(Node* head){
        Node *curr = head, *prev = NULL, *next = NULL ;
        while(curr != NULL){
            next = curr-> next ;
            curr-> next = prev ;
            prev = curr; curr=  next ;
        }
        return prev ;
    }
    bool isPalindrome(Node *head){
        // Your code here
        
        // if LL is empty or has only one element
        if(head == NULL or head -> next == NULL){return head ;}

        // get the middle node using the function defined
        Node *middle= getMid(head);

        // is node se hmne reverse krna hain
        Node* temp = middle-> next ;

        // now the reversed part jp hoga wo middle waale node k aage lgega
        middle-> next= reverse(temp) ;

        // compare both halves
        Node *head1 = head, *head2 = middle->next ;
        while(head2 != NULL){
            if(head1-> data != head2-> data){return false;}
            head1 = head1-> next ; head2 = head2-> next ;
        }
        return true ;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends