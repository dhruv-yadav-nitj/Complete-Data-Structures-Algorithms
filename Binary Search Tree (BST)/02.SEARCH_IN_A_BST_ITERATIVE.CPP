#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode *searchBST(TreeNode *root, int val){

        TreeNode* node = root ;
        while(node != NULL and node -> val != val){
            if(node -> val > val){
                node  = node -> left ;
            }
            else{node = node -> right ;}
        }
        return root ;
    }
};