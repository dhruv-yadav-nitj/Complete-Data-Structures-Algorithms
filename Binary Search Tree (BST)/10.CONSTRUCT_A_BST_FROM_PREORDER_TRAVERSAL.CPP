/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 */

// @lc code=start
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

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // code here

        TreeNode* root = new TreeNode(preorder[0]) ; // the first element would always be the root
        int counter = 0 ;
        doWork(preorder, counter, root) ;
        
    }

    TreeNode* doWork(vector<int>&preorder, int &counter, TreeNode* root){
        // main function

        
    }
};
// @lc code=end

