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

class Solution{

    TreeNode* doWork(vector<int> postorder, int startPost, int endPost, vector<int> inorder, int startIn, int endIn, unordered_map<int, int> &m){
        // main-recursive-function

        // base case
        if(endPost < startPost or endIn < startIn){return NULL ;}

        int lps, lpe, lis, lie, rps, rpe, ris, rie, numsLeft ;
        
        TreeNode* root = new TreeNode(postorder[endPost]) ;
        int rootIndex = m[root-> val] ; numsLeft = rootIndex - startIn ;

        lis = startIn , lie = rootIndex -1 , lps = startPost ;
        // now since length of part of both the subarrays going for next call is constant
        // lpe - lps = lie - lis

        lpe = (lie - lis) + lps ;

        root -> left = doWork(postorder, lps, lpe, inorder, lis, lie, m) ;

        // for right subtree

        ris = rootIndex + 1 ; rie = endIn ;
        rpe = endPost -1 ; // understandable and observable --> ab iske help se rps nikalega --> using length constant 

        rps = rpe - (rie - ris) ;

        root -> right = doWork(postorder, rps, rpe, inorder, ris, rie, m) ;

        return root ;
    }

public: 
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
        // code here

        unordered_map<int, int> m ; // --> to store the indexes of the elements of inOrder

        for(int i=0 ; i < inorder.size() ; i++){
            m[inorder[i]] = i ;
        }

        TreeNode *ans = doWork(postorder, 0, postorder.size() -1 , inorder, 0, inorder.size() -1, m) ;
        
        return ans ;
    }
};
// @lc code=end
