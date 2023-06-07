/*
 * @lc app=leetcode id=2236 lang=cpp
 *
 * [2236] Root Equals Sum of Children
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
public:
    bool checkTree(TreeNode *root){
        // code here
        return (root-> val == (root -> left -> val + root -> right -> val)) ;
    }
};
// @lc code=end
