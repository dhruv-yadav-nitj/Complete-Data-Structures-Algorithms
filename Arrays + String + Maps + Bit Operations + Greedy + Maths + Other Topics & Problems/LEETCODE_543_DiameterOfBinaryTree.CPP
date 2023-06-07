/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution{
    int depth(TreeNode* node){
        // function to find the depth of node
        if(node == NULL){return 0 ;}

        int l = depth(node -> left) , r = depth(node -> right) ;
        return 1 + max(l, r) ;
    }
    int doWork(TreeNode *node, int &maxi){
        // main-function
        if(node == NULL){return 0 ;}
        int left = depth(node-> left) ;
        int right = depth(node -> right) ;

        maxi = max(maxi , left + right) ;

        doWork(node -> left , maxi) ;
        doWork(node -> right , maxi) ;

        return maxi ;
    }
public:
    int diameterOfBinaryTree(TreeNode *root){
        // code here
        int maxi = 0 ; return doWork(root , maxi) ;
    }
};
// @lc code=end
