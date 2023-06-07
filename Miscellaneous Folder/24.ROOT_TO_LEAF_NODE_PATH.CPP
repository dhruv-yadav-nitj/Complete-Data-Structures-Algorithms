/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    bool isLeaf(TreeNode *node){
        return (node -> left == NULL and node -> right == NULL) ;
    }
    void doWork(vector<string> &ans, string s , TreeNode *root){
        
        if(root == NULL){return ;}

        // base condition
        if(isLeaf(root)){
            s += to_string(root -> val) ; ans.push_back(s) ; return ;
        }

        s += to_string(root -> val) + "->" ; doWork(ans, s, root -> left) ;
        doWork(ans, s, root -> right) ;
    }
public:
    vector<string> binaryTreePaths(TreeNode *root){
        // code here
        vector<string> ans ; if(root == NULL){return ans ;}
        string s = "" ; doWork(ans, s, root) ; return ans ;
    }
};
// @lc code=end
