/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

/* struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; */

class Solution{
    int doWork(TreeNode* root){
        // main-recursive-function

        // Time Complexity: O(n)
        // Space Complexity: O(height of the tree) --> doubt

        if(root == NULL){return 0 ;}

        int left = doWork(root -> left) , right = doWork(root -> right) ;

        return left + right +1 ;
    }
public:
    int countNodes(TreeNode *root){
        // code here

        return doWork(root) ;
    }
};
// @lc code=end
