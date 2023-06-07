/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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

    // this solution is based on Morris Traversal --> so if you dont remember it better to revise morris traversal first

    // https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/

    void flatten(TreeNode *root){
        // code here

        TreeNode* curr = root ;
        while(curr != NULL){

            if(curr -> left != NULL){
                TreeNode* temp = curr -> left ;

                while(temp -> right != NULL){temp = temp -> right ;}

                temp -> right = curr -> right ;
                curr -> right = curr ->left ; curr -> left = NULL ;
            }

            curr = curr -> right ;

        }
    }
};
// @lc code=end
