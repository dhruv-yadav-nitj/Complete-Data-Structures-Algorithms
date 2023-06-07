/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

// Time Complexity : O(N)
// Aux Space: O(N) --> when its a skew tree

class Solution{
    bool doWork(TreeNode *l, TreeNode *r){
        // base conditions
        if(l == NULL or r == NULL){return l == r ;} // ho skta hain either left or right or both of them become null at any point
        if(l -> val != r-> val){return false ;} // if both of them are not NULL --> then we need to compare their values

        if(!doWork(l -> left , r -> right)){return false ;} // for the left one go to right and for the right one go to left --> agar isi time false ho gya return false --> else the final value depend on vice versa statement
        else{
            return doWork(l -> right , r -> left) ; // vice versa
        }
    }
public:
    bool isSymmetric(TreeNode *root){
        // code here
        if(root == NULL or (root -> left == NULL and root -> right == NULL)){return true ;}
        return doWork(root -> left, root -> right) ;
    }
};
// @lc code=end
