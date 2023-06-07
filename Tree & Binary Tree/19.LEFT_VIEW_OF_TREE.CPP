//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> leftView(struct Node *root);

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> vec = leftView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root){
    // Your code here
    vector<int> ans ; if(root == NULL){return ans ;}
    queue<pair<int, Node*>> q ; map<int, int> m ;
    // q --> {horizontal_level, Node*}  and m --> {horizontal_level , Node-> value}

    q.push(make_pair(0, root)) ; // root is at horizontal level 0
    while(!q.empty()){
        auto x = q.front() ; int horizontal = x.first ; q.pop() ;

        // if we have not stored any node for the current horizontal level then update the map
        if(m.count(horizontal) == 0){
            m[horizontal] = x.second-> data ;
        }

        // if left node is present --> then store it in queue by increasing the current horizontal level
        if(x.second -> left != NULL){
            q.push(make_pair(horizontal+1 , x.second -> left)) ;
        }

        // if right node is present --> then store it in queue by increasing the current horizontal level
        if(x.second -> right != NULL){
            q.push(make_pair(horizontal+1 , x.second -> right)) ;
        }
    }

    // now we have only one element stored in the map for each horizontal level and its the first element from left
    for (auto &&i : m){
        ans.push_back(i.second) ;
    }
    return ans ;    
}
