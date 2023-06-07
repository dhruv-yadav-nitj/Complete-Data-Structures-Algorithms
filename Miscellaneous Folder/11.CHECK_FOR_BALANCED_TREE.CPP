#include <bits/stdc++.h>
using namespace std ;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    int maxDepth(TreeNode* root){
        if(root == NULL){return 0 ;}

        int left = maxDepth(root -> left) ;
        int right = maxDepth(root -> right) ;

        return 1 + max(left , right) ;
    }
    bool isBalanced(TreeNode *root){
        // code here
        if(root == NULL){return true ;} // since an empty tree would always be balanced

        int left = maxDepth(root -> left) ;
        int right = maxDepth(root -> right) ;
        
        if(abs(left - right) > 1){return false ;}

        // phir hmne aage bhi to check krna hain
        if(isBalanced(root -> left) == false ){return false ;} // agar left child balanced nhi hain to
        if(isBalanced(root-> right) == false){return false ;} // agar right child balanced nhi hain to


        return true ;
    }
};