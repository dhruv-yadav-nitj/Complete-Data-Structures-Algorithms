/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root){
        // code here
        vector<vector<int>> ans ; int count(1) ;
        if(root == NULL){return ans ;}
        queue<TreeNode*> q ; q.push(root) ;
        while(!q.empty()){
            int size = q.size() ; vector<int> curr ; stack<TreeNode*> s ;
            for(int i= 0; i < size; i++){
                curr.push_back(q.front() -> val) ;
                if(count%2 == 0){
                    if(q.front() -> right!= NULL){s.push(q.front() -> right) ;}
                    if(q.front() -> left!= NULL){s.push(q.front() -> left) ;}
                }
                else{
                    if(q.front() -> left!= NULL){s.push(q.front() -> left) ;}
                    if(q.front() -> right!= NULL){s.push(q.front() -> right) ;}
                }
                q.pop() ;
            }
            while(!s.empty()){
                q.push(s.top()) ; s.pop() ;
            }
            ans.push_back(curr) ;
            count++ ;
        }
        return ans ;
    }
};
// @lc code=end
