//{ Driver Code Starts
#include<iostream>
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

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

//Function to merge two sorted linked list.

Node* solve(Node* list1, Node* list2){
    // merge function
    
    Node* curr = list1; Node* fwd = curr-> next ; Node* temp= list2; Node* temp2 ;
    // suppose if list1 is having only one element then simply
    if(fwd == NULL){
        curr -> next = temp ;
        return list1 ;
    }

    while(fwd != NULL and temp !=NULL){
        if(curr->data <= temp-> data and temp-> data < fwd-> data){
            temp2 = temp-> next ;
            curr-> next = temp ; temp-> next= fwd ;
            curr = curr-> next ; temp = temp2 ;
        }
        else{
            curr = fwd ;fwd = fwd-> next ;
            if(fwd==NULL){
                curr-> next = temp ;
                return list1 ;
            }
        }
    }
    return list1 ;
}

Node* sortedMerge(Node* head1, Node* head2){
    
    // case 1: LL1 is empty --> simply return LL2
    if(head1 == NULL){return head2 ;}
    // case 2: LL2 is empty --> return LL1
    if(head2==NULL){return head1 ;}

    if(head1->data < head2->data){
        return solve(head1, head2 );
    }
    else{
        return solve(head2, head1) ;
    }
}