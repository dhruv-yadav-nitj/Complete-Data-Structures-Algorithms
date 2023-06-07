/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
public:

// using two stacks
    // vector<int> postorderTraversal(TreeNode *root){
    //     // code here
    //     vector<int> ans ;
    //     if(root == NULL){return ans ;}
    //     stack<TreeNode*> s1 , s2 ;
    //     s1.push(root) ;
    //     while(!s1.empty()){
    //         TreeNode* temp = s1.top() ; s1.pop() ;
    //         if(temp -> left != NULL){s1.push(temp-> left) ;} 
    //         if(temp -> right != NULL){s1.push(temp-> right) ;}

    //         s2.push(temp) ; 
    //     }
    //     while(!s2.empty()){
    //         ans.push_back(s2.top()->val) ; s2.pop() ;
    //     }
    //     return ans ;
    // }

// using one stack
    vector<int> postorderTraversal(TreeNode *root){
        // code here
        vector<int> ans ;
        if(root == NULL){return ans ;}
        stack<TreeNode*> s ;
        TreeNode* curr = root ;
        while(curr != NULL or !s.empty()){
            // bahut dimaag lgega
            if(curr != NULL){
                s.push(curr); curr = curr -> left ;
            }

            else{
                TreeNode* temp = s.top() -> right ;
                if(temp == NULL){
                    temp = s.top() ; s.pop() ;
                    ans.push_back(temp -> val) ;
                    while(!s.empty() and temp == s.top() -> right){
                        temp = s.top() ; s.pop() ;
                        ans.push_back(temp -> val) ;
                    }
                }
                else{
                    curr = temp ;
                }
            }
        }
        return ans ;
    }
};
// @lc code=end
