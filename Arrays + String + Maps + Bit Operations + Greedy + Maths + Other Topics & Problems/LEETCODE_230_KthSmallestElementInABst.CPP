/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &store){
        if(root == NULL){return ;}

        inorder(root -> left, store) ;
        store.push_back(root -> val) ; inorder(root -> right, store) ;
    }
    int kthSmallest(TreeNode* root, int k) {
        // code here

        // intuition --> inorder traversal --> left root right
        vector<int> store ;

        inorder(root , store) ;

        return store[k - 1] ; // and for largest kth element return store[n-k]

        // this ques can be done in constant extra space O(1) --> for that we need to use morris traversal for iterative inorder traversal of the tree and a counter variable --> done in the the folder
    }
};
// @lc code=end

