#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// approach #1 : basically we have found the inorder traversal of the bst and then applied two pointers approach to solve the problem --> TC: O(N) and Aux Space: O(N) for storing the inorder traversal

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        // code here

        vector<int> inorder ; getInorder(root , inorder) ;
        
        // since we know that the inorder traversal of bst is sorted
        int low = 0, high = inorder.size() - 1 ;
        while(low < high){
            int sum = inorder[low] + inorder[high] ;
            if(sum == k){return true ;}
            else if(sum < k){low++ ;}
            else{high -- ;}
        }

        return false ;
    }

    void getInorder(TreeNode* curr, vector<int> &inorder){
        if(curr == NULL){return ;}

        getInorder(curr -> left, inorder) ; inorder.push_back(curr -> val)  ; getInorder(curr -> right, inorder) ;
    }
};