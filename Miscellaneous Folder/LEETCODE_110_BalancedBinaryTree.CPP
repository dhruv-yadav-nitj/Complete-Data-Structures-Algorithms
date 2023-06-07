/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int calcHeight (TreeNode *node){
        // function to calculate the height of a node --> max depth of that subtree
        if(node == NULL){return 0 ;}

        int lHeight = calcHeight(node -> left) ;
        int rHeight = calcHeight(node -> right) ;

        return 1 + max(lHeight , rHeight);
    }

    bool isBalanced(TreeNode *root){
        // code here

        // base condition
        if(root == NULL){return true ;} // think of an empty tree --> which is always balanced

        int lDep = calcHeight(root -> left) ;
        int rDep = calcHeight(root -> right) ;

        if(abs(lDep - rDep) > 1){return false ;} // not a balanced binary tree

        bool left = isBalanced(root -> left) ; bool right = isBalanced(root -> right) ;

        if(left == false or right == false){return false ;}

        return true ;
    }
};
// @lc code=end
