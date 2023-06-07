/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 */

// @lc code=start


// https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

// there are three approaches --> O(N2), O(NLogN) and O(N)

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


// approach #1 : use preorder to first find inorder by sorting the preorder --> and then use the method construct a binary tree using preorder and inorder traversal given

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // code here

        vector<int> inorder = preorder ; sort(inorder.begin(), inorder.end()) ;

        // sort krne mein O(nlogn) jaaega

        unordered_map<int, int> m ;
        for(int i =0 ; i < inorder.size() ; i++){
            m[inorder[i]] =  i;
        }

        TreeNode* ans = constructBST(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, m) ;

        return ans ;
        
    }

    // below function k lie O(n) time jaaega

    // unordered_map k lie O(n) space jaaega

    // net Time Complexity : O(nlogn) + O(n) = O(nlogn)
    // net aux space: O(n)

    TreeNode* constructBST(vector<int> inorder, int inSt, int inEnd, vector<int> preorder, int preSt, int preEnd, unordered_map<int, int> m){

        // code here

        if(preSt > preEnd or inSt > inEnd){return NULL ;}

        TreeNode* root = new TreeNode(preorder[preSt]) ; // a node is always the first element of preOrder


        int rootPos = m[root -> val] ;

        int numsLeft = rootPos - inSt ;

        root -> left = constructBST(inorder, inSt, rootPos - 1 , preorder, preSt + 1 , preSt + numsLeft, m) ;

        root -> right = constructBST(inorder, rootPos+1 , inEnd, preorder, preSt + numsLeft + 1 , preEnd, m) ;

        return root ;
    }
};
// @lc code=end

