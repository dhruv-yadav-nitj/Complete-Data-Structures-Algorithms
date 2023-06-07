//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here

        // suppose hmare paas do khiladi hain ek khilar ek time pr do kadam jump maarta hain aur dusra khilaadi ek time pr ek kadam jump maarta hain. to jb 1st player n steps pr hoga tb second player n/2th step pr hoga.  mtlb jb 1st player end of linked list pr hoga tb 2nd player mid of linked list pr hoga

        if (head == NULL or head-> next == NULL)
        {
            // edge case to handlge empty and  single element linked list
            return head-> data  ;
        }

        Node* pro = head-> next ; Node* noob = head ;
        while (pro != NULL)
        {
            pro = pro-> next ;
            if (pro != NULL)
            {
                pro = pro-> next ;
            }
            
            noob = noob-> next ;
        }
        return noob->data ;

        // time comlexity : O(n);
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends