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
    bool doWork(TreeNode* root, int node, vector<TreeNode*> &path){
        if(root == NULL){return false ;}

        path.push_back(root) ; if(root -> val == node){return true ;}

        if(doWork(root -> left, node, path) or doWork(root -> right, node , path)){return true ;}

        path.pop_back() ; return false ;
    }
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        // code here

        vector<TreeNode*> path1, path2; int node1 = p->val, node2 = q->val;
        doWork(root , node1, path1) , doWork(root, node2, path2) ;

        int i=0; TreeNode* ans;
        while(i < path1.size() and i < path2.size()){
            if(path1[i] -> val == path2[i] -> val){ans = path1[i];} i++ ;
        }
        return ans ;
    }
};
// @lc code=end
