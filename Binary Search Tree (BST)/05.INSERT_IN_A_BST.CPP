/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 */
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// @lc code=start
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // code here

        // since we have to return any possible solution --> why not choose the most easy one --> find where it can be and insert --> a leaf node would be appropriate

        TreeNode* curr = root ; if(curr == NULL){
            return new TreeNode(val) ;
        }

        // --> left mein tb insert krenge agar to val cchota hain curr -> val 
        while(curr != NULL){
            if(curr -> val < val){
                if(curr -> right != NULL){
                    curr = curr -> right ;
                }
                else{
                    curr -> right = new TreeNode(val) ; return root ;
                }                
            }
            else{
                // means curr -> val > val
                if(curr -> left != NULL){
                    curr = curr -> left ;
                }
                else{
                    curr -> left = new TreeNode(val) ; return root ;
                }
            }
        }
        return root ;        
    }
};
// @lc code=end

