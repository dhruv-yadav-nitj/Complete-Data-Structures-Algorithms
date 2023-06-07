//{ Driver Code Starts
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

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    if (head == NULL or head-> next == NULL)
    {
        return NULL ;
    }
    
    Node* prev = NULL; Node* curr = head ; Node* pro = head-> next ;
    while (pro != NULL)
    {
        pro = pro-> next ;
        if (pro != NULL)
        {
            pro = pro-> next ;
        }
        prev= curr ; curr = curr-> next ;        
    }

    prev-> next = curr-> next;  curr-> next= NULL ; delete  curr ;  
    return head ;
}