/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode *root){
        // code here
        if(root == NULL){return 0 ;}

        queue<pair<TreeNode*, long long>> q ; int ans = 0;
        q.push({root, 0}) ;
        while(!q.empty()){
            int size = q.size() ;  int leftMost, rightMost ;
            int currMin = q.front().second;
            for(int i=0; i < size ; i++){
                int currID = q.front().second - currMin ; TreeNode* node = q.front().first ; q.pop() ;
                if(i == 0){leftMost = currID ;}
                if(i == size - 1){rightMost = currID ;}

                if(node -> left != NULL){q.push({node -> left, (long long)currID* 2 + 1}) ;}
                if(node -> right != NULL){q.push({node -> right , (long long)currID * 2 + 2}) ;}
            }
            ans = max(ans, rightMost - leftMost + 1) ;
        }
        return ans ;
    }
};
// @lc code=end
