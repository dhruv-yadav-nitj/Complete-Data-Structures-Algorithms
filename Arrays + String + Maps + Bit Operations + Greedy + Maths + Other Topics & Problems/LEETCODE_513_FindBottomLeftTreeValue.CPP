/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode *root){
        // code here
        queue<pair<TreeNode*, int>> q ; map<int, int> m ;
        q.push({root , 0}) ;
        while(!q.empty()){
            auto x = q.front() ; q.pop() ;
            TreeNode* node = x.first ; int horiz = x.second ;
            if(m.find(horiz) == m.end()){
                m[horiz]= node -> val ;
            }
            if(node -> left != NULL){q.push(make_pair(node -> left , horiz+1)) ;}
            if(node -> right != NULL){q.push(make_pair(node -> right , horiz+1)) ;}
        }
        int ans ;
        for (auto &&i : m){
            ans = i.second ;
        }

        return ans ;
        
    }
};
// @lc code=end
