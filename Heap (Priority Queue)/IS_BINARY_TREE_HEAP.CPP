//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

class Solution{
public:

    bool isCBT (struct Node* tree){
        // function to check if the given tree is CBT or not

        // how can we check if a tree is a CBT or not --> use BFS --> simple approach would be to check whether the NULL Node encountered is the last node of the Binary Tree. If the null node encountered in the binary tree is the last node then it is a complete binary tree and if there exists a valid node even after encountering a null node then the tree is not a complete binary tree.

        if(!tree){return true ;} // an empty tree is a CBT

        queue<Node*> q ; q.push(tree) ;
        bool flag = false ; // false means we have not encountered a NULL node till now

        while(!q.empty()){

            Node* temp = q.front() ; q.pop() ;

            if(temp == NULL){

                // tb hm left aur right nhi kr skte
                flag = true ; // hmne phle NULL encounter kr liaa
            }
            else{
                
                // since ek CBT mein NULL sbse last node hona chaiye aur NULL k baad tree khtm hona tha
                // agar flag = true hain --> iska mtlb ki NULL last node nhi tha
                if(flag){return false ;}

                q.push(temp -> left) ; q.push(temp -> right) ;
            }

        }

        return true ;
    }

    bool isMaxHeap (struct Node* tree) {

        // hm log na BFS use krke har ek node pr jaakr check kr skte hain ki wo apne child nodes se bada to hain na
        
        if(tree ==NULL){return true ;} // empty tree

        queue<Node*> q ; q.push(tree) ;
        while(!q.empty()){
            
            Node* temp = q.front() ; q.pop() ;

            if(temp -> left!= NULL and temp -> data < temp -> left -> data){return false ;}
            else if(temp -> right!= NULL and temp -> data < temp -> right -> data){return false ;}
            else{
                if(!temp -> left){q.push(temp -> left) ;}
                if(!temp -> right){q.push(temp -> right) ;}
            }
        }

        return true ;

    }

    bool isHeap(struct Node *tree){
        
        // code here

        // kisi tree ko max heap hone k lie --> do condition hain --> wo ek CBT hona chaiye and wo max Heap ko property ko follow krna chaiye  --> dono hi kaam k lie separate function likh die hain

        return (isCBT(tree) and isMaxHeap(tree)) ;

    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends