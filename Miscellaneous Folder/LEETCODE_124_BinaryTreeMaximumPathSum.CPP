/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
private:
    int doWork(TreeNode* node){
        // function to do the sum for the given node
        // base condition
        if(node == NULL){return 0 ;}

        return node-> val + doWork(node -> left) + doWork(node -> right) ;

    }
public:
    int maxPathSum(TreeNode *root){
        // code here
        if(root == NULL){return 0 ;}
        int maxi= root -> val ;
        maxi = max(maxi , doWork(root)) ;
        // if(root -> left == NULL and root -> right == NULL){return maxi ;}
        maxi = max(maxi , doWork(root -> left)) ;
        maxi = max(maxi , doWork(root -> right)) ;

        return maxi ;
    }
};
// @lc code=end
