//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));

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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
// User function Template for C++

class Solution{
    void markParents(Node *root, unordered_map<Node*, Node*> &m){
        // function-to-map-the-child-node-with-parent-node
        
        queue<Node*> q ; q.push(root) ;
        while(!q.empty()){
            Node* node = q.front() ; q.pop() ;
            if(node -> left != NULL){
                q.push(node -> left) ; m[node -> left] = node ;
            }
            if(node -> right != NULL){
                q.push(node -> right) ; m[node -> right] = node ;
            }
        }
    }

    Node* searchTree(Node* root, int target){
        // function_to_find_the_node_of_target

        // lets traverse BFS

        queue<Node*> q ; q.push(root);
        while(!q.empty()){
            Node* temp = q.front() ; q.pop();
            if(temp-> data == target){return temp ;}

            if(temp -> left != NULL){
                q.push(temp -> left) ;
                if(temp -> left -> data == target){return temp ->left ;}
            }
            if(temp -> right != NULL){
                q.push(temp -> right) ;
                if(temp -> right -> data == target){return temp ->right ;}
            }
        }

        return NULL ; // if not found --> though that is not possible in this problem
    }
public:
    int minTime(Node *root, int target){
        // Your code goes here

        unordered_map<Node*, Node*> childParent ; markParents(root, childParent) ;
        unordered_map<Node*, bool > isVisited ; // map to mark whether a node is visited or not

        Node* targ = searchTree(root, target) ;

        queue<Node*> q; q.push(targ) ; isVisited[targ]= true ; int time =0 ;
        while(!q.empty()){
            time++ ;
            int size = q.size() ;
            for(int i=0; i < size ; i++){
                Node* temp = q.front() ; q.pop() ;

                if(childParent[temp] and !isVisited[childParent[temp]]){
                    q.push(childParent[temp]) ; isVisited[childParent[temp]]= true ;
                }

                if(temp -> left != NULL and !isVisited[temp ->left]){
                    q.push(temp -> left) ; isVisited[temp ->left]= true ;
                }

                if(temp -> right != NULL and !isVisited[temp ->right]){
                    q.push(temp -> right) ; isVisited[temp ->right] = true ;
                }
            }
        }

        return time-1 ; // but since in the loop it will count the time when this target node was fired and we dont need to count that time so to match the ans we need to minus one
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}

// } Driver Code Ends