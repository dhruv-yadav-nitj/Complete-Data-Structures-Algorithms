/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// @lc code=start
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class BSTIterator {
public:
    stack<TreeNode*> temp ;
    BSTIterator(TreeNode* root) {

        pushDeep(root) ;
        
    }
    
    int next() {

        if(temp.empty()){return -1 ;} // though iska jroorat nhi hain but likh de rhe hain for satisfaction --> jroorat kyu nhi hain bcz ques mein saaf saaf diaa hain iske baare mein

        TreeNode* top = temp.top() ; temp.pop() ;

        pushDeep(top -> right) ; // inorder ka yhi charitra hain left root right --> right mein move krna pdhega

        return top -> val ;
    }
    
    bool hasNext() {

        // has next would return false if the stack is empty else return true
        return !temp.empty() ;
        
    }


    // custom function for my need --> this function would basically push all the nodes and then left node and then left node till extreme left nodes in the stack
    void pushDeep(TreeNode* curr){
        while(curr != NULL){
            temp.push(curr) ; curr = curr -> left ;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

