/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution{
    TreeNode* doWork(TreeNode* root , int node1, int node2){
        // main-recursive-function
        if(root == NULL or root -> val == node1 or root -> val == node2){return root ;}

        TreeNode* left = doWork(root -> left, node1, node2) ; TreeNode* right = doWork(root -> right, node1, node2) ;

        if(left == NULL){return right ;} if(right == NULL){return left ;}

        else{
            // means both left and right are not NULL --> thats the answer
            return root ;
        }
    }
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        // code here
        int node1= p -> val , node2 = q-> val ;
        return doWork(root, node1, node2) ;
    }
};
// @lc code=end
