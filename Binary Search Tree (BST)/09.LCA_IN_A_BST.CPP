/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// @lc code=start
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    TreeNode* doWork(TreeNode* root, int p, int q){
        // recursive fx

        int curr= root -> val ;
        if(curr < p and curr < q){return doWork(root -> right, p,  q) ;} // move right
        else if(curr > p and curr > q){return doWork(root -> left, p, q) ;} // move left

        return root ; // cant move left or right --> we have to split --> then this node is the ans
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // code here

        return doWork(root, p -> val , q-> val) ;
        
    }
};
// @lc code=end

