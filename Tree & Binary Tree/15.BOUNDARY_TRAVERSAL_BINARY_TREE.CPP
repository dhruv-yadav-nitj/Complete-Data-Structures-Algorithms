//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Time and Space Complexity:  O(N)

class Solution{
private:
    bool isLeaf (Node* node){
        // ek cheej dekh lo node NULL nhi hain tbhi yha tk pahuch paaya hain , basically hmne node NULL ho wo possiblity phle hi main code mein counter kr li hain --> see the red dots
        return (node -> left == NULL and node -> right == NULL) ;
    }

    void addLeaf (Node* curr , vector<int> &ans){
        if(isLeaf(curr)){ans.push_back(curr -> data) ; return ;}

        if(curr -> left != NULL){addLeaf(curr -> left , ans) ;}
        if(curr -> right != NULL){
            addLeaf(curr -> right, ans) ;
        }
    }
public:
    vector <int> boundary(Node *root){
        //Your code here

        vector<int> ans ;

        // step 1: adding the left boundary
        if(root == NULL){return ans ;}

        // root node ko to phle ghusao
        if(!isLeaf(root)){ans.push_back(root -> data) ;}


        // next step : ab left boundary ko ghusao
        Node* curr = root -> left ;
        while(curr != NULL){
            if(!isLeaf(curr)){ans.push_back(curr -> data) ;}

            if(curr -> left != NULL){curr = curr -> left ;}
            else{curr = curr -> right ;}
        }

        // next step: ab leaf nodes ko ghusao
        addLeaf(root , ans) ;

        // next step : ab right boundary ko ghusao
        Node *temp = root-> right ;
        stack<int> s ;
        while(temp != NULL){
            if(!isLeaf(temp)){
                s.push(temp -> data) ;
            }

            if(temp -> right != NULL){temp = temp -> right ;}
            else{temp = temp -> left ;}
        }

        // insert all the elements in stack in the ans vector
        while(!s.empty()){
            ans.push_back(s.top()) ; s.pop() ;
        }

        return ans ;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends