/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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

// using BFS traversal

// can be also done using DFS traversal --> using recursion

class Solution{
public:
    int maxDepth(TreeNode *root){
        // code here --> BFS traversal
        queue<TreeNode*> q ;
        int ans  =0 ; if(root ==NULL){return ans ;}
        q.push(root) ;
        while(!q.empty()){
            int size = q.size() ; ans++ ;
            for(int i= 0 ; i < size and !q.empty(); i++){
                TreeNode* temp = q.front() ; q.pop() ;
                if(temp -> left != NULL){q.push(temp-> left) ;}
                if(temp -> right != NULL){q.push(temp-> right) ;}                
            }
        }
        return ans ;
    }

    int maxDepth(TreeNode *root){
        // code here --> DFS traversal
        if(root == NULL){return 0 ;}

        int lheight = maxDepth(root -> left) ;
        int rheight = maxDepth(root-> right) ;

        return 1 + max(lheight , rheight) ;
    }
};

// Time ans Space Complexity : O(N)
// @lc code=end
