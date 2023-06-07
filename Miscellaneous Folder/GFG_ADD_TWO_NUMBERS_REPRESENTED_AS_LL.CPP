// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    void reverse(struct Node* &head){
        Node *prev= NULL, *curr = head, *next ;
        while(curr!= NULL){
            next = curr -> next ;
            curr-> next = prev ;
            prev = curr ; curr = next ;
        }
        head = prev; // new head would be the last element
    }

    void push(Node* &head, int data){
        Node* temp = new Node(data) ;
        if(head == NULL){head = temp ;}
        else{
            Node* tail = head ;
            while(tail-> next != NULL){
                tail = tail-> next ;
            }
            tail-> next = temp ;
            temp -> next = NULL ;
        }
    }

    struct Node* add(Node* first, Node* second){
        // main-function for this solution
        int carry =0 ;

        // linked list for returning answer
        Node* ans = NULL ;
        while(first != NULL or second != NULL or carry != 0){
            int val1 = 0, val2 =0;
            if(first != NULL){val1 = first-> data ;}
            if(second!= NULL){val2 = second-> data ;}

            int sum = carry + val1 + val2 ;
            int digit = sum%10 ; carry = sum/10 ;

            push(ans, digit) ;

            if(first != NULL){first = first-> next ;}
            if(second != NULL){second = second-> next ;}
        }
        return ans ;
    }

    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second){
        // code here

        // first reverse the given lists
        reverse(first) ; reverse(second) ;

        Node *ans = add(first, second) ;
        reverse(ans) ; return ans ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}