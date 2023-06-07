//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

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
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root){
        // Your code here
        
        vector<int> ans ; if(root == NULL){return ans ;}
        queue<pair<int, Node*>> q ; map<int, int> m ;
        // q --> line no., node value and m --> line no., node value
        q.push({0, root}) ;
        while(!q.empty()){
            auto fuck = q.front() ; q.pop() ;
            if(m.find(fuck.first) == m.end()){
                // agar to is line no. ka koi bhi node abhi tk present nhi hain tb to ghusao warna fuck off
                m[fuck.first] = fuck.second-> data ;
            }

            int vertical = fuck.first ;
            if(fuck.second -> left != NULL){q.push({vertical - 1 , fuck.second-> left}) ;}
            if(fuck.second -> right != NULL){q.push({vertical + 1 , fuck.second-> right}) ;}
        }

        for (auto &&temp : m){

            ans.push_back(temp.second) ;
        }

        return ans ;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends