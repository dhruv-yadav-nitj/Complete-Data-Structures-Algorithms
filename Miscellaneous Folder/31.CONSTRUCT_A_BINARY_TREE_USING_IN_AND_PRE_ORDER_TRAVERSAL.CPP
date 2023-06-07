/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

    // LeetCode was giving TLE when map was passed as it is but when we passed it as reference it got Accepted
    // Since, everytime the function gets called it creates a new map with same name at another memory location with same values. So these operations take time and space which is alot, thats why TLE.

    TreeNode *doWork(vector<int> preorder, int preStart, int preEnd, vector<int> inOrder, int inStart, int inEnd, unordered_map<int, int> &m){
        // main-recursive-function

        // base condition
        if(preEnd < preStart or inEnd < inStart){return NULL ;}


        TreeNode* root = new TreeNode(preorder[preStart]) ; // ye to hmne curr subtree k hisaab se root node bana dia

        int rootPositionIn = m[root -> val] ; // this would now serve as the end of left subtree

        int numsLeft = rootPositionIn - inStart ; // how many numbers are on the left of the root in INORDER ARRAY

        root -> left = doWork(preorder, preStart + 1, preStart + numsLeft , inOrder, inStart, rootPositionIn - 1, m) ;

        root -> right = doWork(preorder, preStart + numsLeft + 1 , preEnd, inOrder, rootPositionIn + 1 , inEnd, m) ;

        return root ;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        // code here
        unordered_map<int, int> storeIn ;
        for(int i=0 ; i < inorder.size() ; i++){
            storeIn[inorder[i]] = i ;
        }

        TreeNode* ans = doWork(preorder, 0, preorder.size() -1, inorder, 0, inorder.size()-1, storeIn) ;

        return ans ;
    }
};
// @lc code=end
