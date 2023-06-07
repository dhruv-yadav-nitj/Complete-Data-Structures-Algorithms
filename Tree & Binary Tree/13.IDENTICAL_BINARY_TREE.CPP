/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode *p, TreeNode *q){

        // code here
        if((p != NULL and q!= NULL and p-> val == q-> val)){
            if(isSameTree(p -> left , q-> left)){
                return isSameTree(p-> right , q-> right) ;
            }
            else{
                return false ;
            }
        }
        else if(p == NULL and q == NULL){return true ;}
        else{return false ;}
    }
};
// @lc code=end
