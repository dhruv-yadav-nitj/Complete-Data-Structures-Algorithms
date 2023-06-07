//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

int findCeil(Node *root, int input);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin >> ws, s);
        int x;
        cin >> x;
        Node *root = buildTree(s);
        cout << findCeil(root, x) << endl;
    }
    return 1;
}

int findCeil(Node *root, int input){
    if (root == NULL)
        return -1;

    // Your code here
    Node* node = root; int temp = -1; // initiating from -1 bcz aisa ho skta hain ki pure tree mein input ho hi na aur saare elements usase cchote ho then is case mein -1 hi return krna hain

    // agar to input wla node present hain then whi node return maar denge warna jo root node rha hoga us node ka wo return maar denge --> bcz left < node < right --> isase pata chalta hain ki smallest val larger than input would be node
    while(node != NULL and node -> data != input){
        if(node -> data > input){
            temp = node -> data ; node = node -> left ;
        }
        else{node = node -> right ;}
    }

    if(node == NULL){return temp;} // agar node NULL mil gya hain iska mtlb ki pure tree mein input hain hi nahi then is case mein last element jo input se badha rha hoga (jo hmne temp mein store kia hain) wo return krna hain
    else{
        node -> data ; // is case mein aane ka mtlb ki input is present in tree --> return input or node -> data
    }
}