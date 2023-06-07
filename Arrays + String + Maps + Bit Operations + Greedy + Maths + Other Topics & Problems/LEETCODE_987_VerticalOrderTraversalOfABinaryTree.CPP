/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode *root){
        // code here
        queue<pair<TreeNode* , pair<int, int>>> fuck; // node , <vertical, horizontal>
        map<int, map<int, multiset<int>>> deep ; // <vertical , <horizontal, multiset<nodes>>

        vector<vector<int>> ans ; if(root == NULL){return ans ;}
        fuck.push({root , {0 , 0}}) ;

        while(!fuck.empty()){
            auto sax  = fuck.front() ; int size = fuck.size() ; fuck.pop() ;
            TreeNode* node = sax.first ;
            int vertical = sax.second.first , horizontal = sax.second.second ;

            // ab isko deep daal do
            deep[vertical][horizontal].insert(node -> val) ;

            // ab baari hain ki left aur right daal do
            if(node -> left != NULL){
                fuck.push({node -> left , {vertical-1 , horizontal + 1}}) ;
            }
            if(node -> right){
                fuck.push({node -> right, {vertical+1 , horizontal +1}}) ;
            }
        }

        for (auto &&cum : deep){
            vector<int> hole ;
            for (auto &&i : cum.second){
                hole.insert(hole.end() , i.second.begin() , i.second.end()) ;
            }
            ans.push_back(hole) ;
        }
        return ans ;
    }
};
// @lc code=end
