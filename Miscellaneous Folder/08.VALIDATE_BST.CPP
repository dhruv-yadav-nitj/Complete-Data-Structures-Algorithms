/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Approach: basically we need to provide every node with some range --> ek aisa range jisme us node ki value lie krni chaie for the tree to be BST --> so initially we would take that range to be INT_MIN and INT_MAX --> and agar left mein chale to upper bound change ho jaage --> curr -> val would be new upper bound and agar right mein chale to lower bound change hoga --> curr -> val would be new lower bound

class Solution {
public:

    bool doWork(TreeNode* root, long left, long right){

        if(root == NULL){return true ;}

        if(root -> val <= left or root -> val >= right){
            return false ;
        }
        else{
            return (doWork(root -> left, left, root -> val) and doWork(root -> right, root -> val, right)) ;
        }
    }

    bool isValidBST(TreeNode* root) {

        // code here

        return doWork(root, LONG_MIN, LONG_MAX) ;
        
    }
};
// @lc code=end

