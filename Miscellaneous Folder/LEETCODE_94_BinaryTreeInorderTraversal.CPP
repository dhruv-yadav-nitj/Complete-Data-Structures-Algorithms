/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root){
        // code here
        vector<int> ans ;
        if(root == NULL){return ans ;} // if empty then return empty
        stack<TreeNode*> s ;
        TreeNode* node = root ;
        while(true){
            if(node != NULL){
                s.push(node) ;
                node = node -> left ;
            }
            else{
                if(s.empty()){break ;}
                node = s.top() ; s.pop() ;
                ans.push_back(node -> val) ;
                node = node -> right ;
            }
        }
        return ans ;
    }
};
// @lc code=end
