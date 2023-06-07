/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution{
    void indexingParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &m){

        // function to map all the child with their parents

        queue<TreeNode*> q; q.push(root) ;
        while(!q.empty()){
            TreeNode* node = q.front() ; q.pop() ;
            if(node -> left != NULL){q.push(node -> left) ;m[node -> left] = node ;}
            if(node -> right != NULL){q.push(node -> right) ;m[node -> right] = node ;}
        }
    }
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k){
        // code here
        unordered_map<TreeNode*, TreeNode*> childParent ; // map to store the child, parent relationship
        indexingParent(root, childParent);

        unordered_map<TreeNode*, bool> isVisited ; // The default value of the bool type is false .
        queue<TreeNode*> q ; q.push(target) ; int distance = 0 ; isVisited[target] = true ;

        while(!q.empty()){
            if(distance >= k){break ;} // that is we have moved k distance away from node and the nodes left in the queue are the answers

            int size= q.size() ;
            for(int i = 0 ; i < size; i++){
                TreeNode* currNode = q.front() ; q.pop() ;

                if(childParent[currNode] != NULL and !isVisited[childParent[currNode]]){
                    q.push(childParent[currNode]) ; isVisited[childParent[currNode]] = true ;
                }

                if(currNode -> left != NULL and !isVisited[currNode -> left]){
                    q.push(currNode-> left) ; isVisited[currNode-> left] = true ;
                }

                if(currNode -> right != NULL and !isVisited[currNode-> right]){
                    q.push(currNode-> right) ; isVisited[currNode-> right] = true ;
                }
            }

            distance ++ ; // means we have moved a unit distance away from the target node

        }

        vector<int> ans ;
        while(!q.empty()){
            ans.push_back(q.front() -> val) ; q.pop() ;
        }
        return ans ;
    }
};
// @lc code=end
