/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
#include <bits/stdc++.h>
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
    vector<int> preorderTraversal(TreeNode *root){
        // code here
        vector<int> ans ;
        if(root == NULL){return ans ;} // if the tree is empty then return empty
        stack<TreeNode*> s ;
        s.push(root) ;
        while(!s.empty()){
            TreeNode* curr = s.top() ;
            s.pop() ;
            if(curr -> right != NULL){s.push(curr -> right) ;}
            if(curr -> left != NULL){s.push(curr -> left ) ;}
            ans.push_back(curr -> val) ;
        }
        return ans ;
    }
};
// @lc code=end
