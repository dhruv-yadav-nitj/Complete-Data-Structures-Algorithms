// LeetCode #450
/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // code here 

        if(root == NULL){return NULL ;}

        if(root -> val == key){
            return doWork(root) ;
        }

        TreeNode* ans = root ;
        while(root != NULL)        {
            if(root -> val > key){
                // iska mtlb ki jo key hain wo left subtree mein hi mil skta hain
                if(root -> left != NULL and root -> left -> val == key){
                    root -> left = doWork(root -> left) ; break ;
                }
                else{
                    root = root -> left ;
                }
            }
            else{
                // mtlb ki hme right mein move krna hain
                if(root -> right != NULL and root -> right -> val == key){
                    root -> right = doWork(root -> right); break ;
                }
                else{
                    root = root -> right ;
                }
            }
        }

        return ans ;
    }

    TreeNode* doWork(TreeNode* root){
        // saare arrangements krne waala function
        
        if(root -> left == NULL){
            return root -> right ;
        }
        else if(root -> right == NULL){
            return root -> left ;
        }

        TreeNode* rightChild = root -> right ;
        TreeNode* extremeRight = findExtremeRight(root -> left) ;
        extremeRight -> right = rightChild ; return root -> left ;
    }
    
    TreeNode* findExtremeRight(TreeNode* root){
        // function to find the extreme right of the left subtree
        if(root -> right == NULL){return root ;}
        else{
            return findExtremeRight(root -> right) ;}
    }
};
// @lc code=end

