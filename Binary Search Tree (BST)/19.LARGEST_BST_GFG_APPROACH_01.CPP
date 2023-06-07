//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


// what I did ?
// traversed the tree inorder wise and stored the nodes in a vector
// write a function validateBST --> see the function --> this function validates whether a subtree is valid bst or not
// iterate over the vector --> and assuming each element of the vector as a root to the subtree validateBST --> if the subtree is bst --> use countNodes function to update the ans variable
// count Nodes function counts the nodes in a subtree --> see the function


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here

        vector<Node*> bst ; inorder(root, bst) ;

        // now we have all the nodes inorder wise in the vector bst

        int ans = 0 ;

        for(int i= 0; i < bst.size() ; i++){
            auto x = bst[i] ;
            if(isValidBST(x, INT_MIN, INT_MAX)){
                // then we need to count the size of this subtree with root = x ;

                ans = max(ans, countNodes(x)) ;
            }
        }

        return ans ;

    }

    int countNodes(Node* curr){
        if(curr == NULL){return 0 ;}

        return countNodes(curr -> left) + countNodes(curr -> right) + 1 ;
    }

    void inorder(Node* curr, vector<Node*> &bst){

        if(!curr){return ;}

        inorder(curr -> left, bst) ; bst.push_back(curr) ; inorder(curr -> right, bst) ;
    }

    bool isValidBST (Node* curr, int low, int high){
        // basically hm kaise validate krenge bst --> hm har ek node ke lie ek range decide kr denge --> ki uski value low aur high k beech hi aani chaie agar usase bahar gyi to return false
        if(!curr){return true ;} // curr agar NULL hain to wo BST hi hain --> return true

        if(curr -> data <= low or curr -> data >= high){
            return false ;
        }

        return (isValidBST(curr -> left, low, curr -> data) and isValidBST(curr -> right, curr -> data, high)) ;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends