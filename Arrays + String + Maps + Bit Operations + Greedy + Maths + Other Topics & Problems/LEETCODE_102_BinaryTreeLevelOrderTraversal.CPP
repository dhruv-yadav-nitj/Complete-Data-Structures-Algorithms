/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        // code here
        vector<vector<int>> ans ;
        if(root == NULL){return ans ;} // if the tree is empty then return the empty data str.

        queue<TreeNode*> q ;
        q.push(root) ;
        while(!q.empty()){
            int size = q.size() ; vector<int> currLevel ;
            for(int i=0 ; i < size ; i++){
                TreeNode* currNode = q.front() ;
                q.pop() ;
                if(currNode-> left != NULL){q.push(currNode-> left) ;}
                if(currNode-> right != NULL){q.push(currNode-> right) ;}

                currLevel.push_back(currNode-> val) ;
            }
            ans.push_back(currLevel) ;
        }
        return ans ;
    }
};
// @lc code=end
