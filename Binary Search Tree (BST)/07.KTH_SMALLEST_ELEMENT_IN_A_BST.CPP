/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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


// approach #1 : basically traverse using inorder traversal --> why inorder traversal --> bcz inorder traversal of bst gives sorted form of the bst. then store every element of the tree in a vector and then return the kth element of the vector

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &nodes){
        if(!root){return ;}

        inorder(root -> left , nodes) ;
        nodes.push_back(root -> val) ; inorder(root -> right , nodes) ;
    }
    int kthSmallest(TreeNode* root, int k) {
        // code here

        vector<int> nodes ; inorder(root, nodes) ;
        return nodes[k-1] ;
    }
};

// approach #2: we can also not store every element but we can only return the kth element of the inorder traversal of bst --> in the above approach we used recursive approach of the inorder but now let use iterative form of inorder traversal --> bcz then it would be easy to return kth element

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // code here

        // using morris traversal

        // yha pr ek variable lekar bhi kiaa jaa skta hain but pata nhi hm kr rhe to code kha gaand mara jaa rha pata hi chal rha even after successful dry run

        vector<int> ans ;
        TreeNode* curr = root ;
        while(curr != NULL){

            if(curr -> left == NULL){
                
                // agar to curr node ka left NULL hain iska mtlb ki ye jo curr node hain ye root to isko daal do ans mein aur then move to right child
                ans.push_back(curr -> val) ;
                curr = curr -> right ;
            }
            else{

                // agar to left child present hain curr node ka then we need to first travel to right most child of this subtree and phir wha se hme link baithana hoga us left subtree k right most child ka with curr node --> jo ki root hain is subtree ka and agar phle se linked hain to phir usko remove krna hoga

                TreeNode* prev = curr -> left ;
                while(prev -> right != NULL and prev -> right != curr){
                    prev = prev -> right ;
                }

                if(prev -> right == NULL){prev -> right = curr ; curr = curr -> left ;} // link baitha diya hmne aur uske baad to hme curr k left child mein move krna hoga to bhi kr diaa

                else{
                    prev -> right = NULL ; // iska mtlb ki link phla se tha so ab hme link ko cur krna hoga plus curr ko right mein move krna hoga aur saath hi curr ko ans mein push kr dena hoga --> is point pr left subtree khtm ho chuka hain curr node ka
                    ans.push_back(curr -> val) ;
                    curr = curr -> right ;

                    // is point ka importance tbhi smjh aaega jb aap above given tree pr dry run kroge
                }
            }
        }

        return ans[k-1] ;
    }
};

// @lc code=end

