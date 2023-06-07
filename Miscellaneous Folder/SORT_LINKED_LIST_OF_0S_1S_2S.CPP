//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head){


        // approach: 1 --> traversing LL --> counting frequency --> traversing again and replacing the nodes->data
        
        unordered_map<int, int> m;
        // in place of creating map we can actually create 3 variables to store the count of 0s, 1s and 2s.
        Node* temp = head ;
        if(temp == NULL){return NULL ;}
        while(temp != NULL){
            m[temp->data]++ ;
            temp = temp-> next ;
        }
        Node* ans = head ;
        for(int i=0; i<=2 ; i++){
            while(m[i] > 0){
                ans->data =i; m[i]-- ; ans = ans->next ;
            }
        }
        return head ;


        // approach: 2 --> one time traversing

        if(head == NULL or head -> next == NULL){return head ;}

        // make these dummy nodes first --> they are later used to connect linked list together
        Node* zeroDummy = new Node(-1) ; Node* oneDummy = new Node(-1) ; Node* twoDummy = new Node(-1) ;

        // create three more pointers which will actually move forward
        Node* zeroCurr = zeroDummy ; Node* oneCurr = oneDummy ; Node* twoCurr = twoDummy ;

        // create one more pointer which will traverse through the original LL
        Node* curr = head ;

        while(curr != NULL){
            if(curr-> data == 0){
                zeroCurr->next = curr ;
                zeroCurr = zeroCurr->next ;
            }
            else if(curr->data == 1){
                oneCurr -> next = curr ;
                oneCurr = oneCurr->next ;
            }
            else if(curr->data == 2){
                twoCurr -> next = curr ;
                twoCurr = twoCurr->next ;
            }
            curr = curr->next ;
        }

        // connect all the LLs together
        if(oneDummy-> next != NULL){zeroCurr -> next = oneDummy-> next ;}
        else{
            zeroCurr -> next = twoDummy-> next ;
        }

        oneCurr-> next = twoDummy-> next ;
        twoCurr-> next = NULL ;
        // new head
        head = zeroDummy -> next ;

        // delete the useless dummy nodes
        delete(zeroDummy) ; delete(oneDummy) ; delete(twoDummy) ;

        return head ;

    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends