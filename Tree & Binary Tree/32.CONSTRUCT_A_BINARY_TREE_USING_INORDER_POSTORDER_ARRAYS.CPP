/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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

// SEE THE LEETCODE FILE IN PARENT FOLDER ALSO

// STRIVER'S WAY

class Solution{

    TreeNode* doWork(vector<int> postorder, int startPost, int endPost, vector<int> inorder, int startIn, int endIn, unordered_map<int, int> &m){
        // main-recursive-function

        // base case
        if(endPost < startPost or endIn < startIn){return NULL ;}

        TreeNode* root = new TreeNode(postorder[endPost]) ;
        int rootIndex = m[root -> val] ; // this would represent the index of root in inorder array

        int numsLeft = rootIndex - startIn ; // how many numbers are in the left of the root in Inorder array
        
        root -> left = doWork(postorder , startPost, startPost + rootIndex - startIn - 1 , inorder, startIn, rootIndex -1, m) ;

        root -> right =doWork(postorder, startPost + rootIndex - startIn, endPost - 1, inorder, rootIndex+1, endIn, m) ;


        return root ;
    }

public: 
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
        // code here

        unordered_map<int, int> m ; // --> to store the indexes of the elements of inOrder

        for(int i=0 ; i < inorder.size() ; i++){
            m[inorder[i]] = i ;
        }

        TreeNode *ans = doWork(postorder, 0, postorder.size() -1 , inorder, 0, inorder.size()-1, m) ;
        
        return ans ;
    }
};
// @lc code=end
