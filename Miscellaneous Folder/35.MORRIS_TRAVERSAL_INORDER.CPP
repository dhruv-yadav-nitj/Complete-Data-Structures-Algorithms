#include <bits/stdc++.h>
using namespace std;

// Morris Traversal mein time complexity to O(N) hoti hain but Space Complexity O(1) hoti hain --> because we r not using any stack or queue or any other data structure

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// best way to understand the below code is to have a dry run on the following tree:
// 1 2 3 4 5 NULL NULL NULL NULL NULL 6

class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root){
        // code here

        // inorder traversal using MORRIS Traversal

        vector<int> ans ;
        TreeNode* curr = root ; if(curr == NULL){return ans ;}
        while(curr != NULL){

            if(curr -> left == NULL){
                
                // agar to curr node ka left NULL hain iska mtlb ki ye jo curr node hain ye root to isko daal do ans mein aur then move to right child
                ans.push_back(curr -> val) ;
                curr = curr -> right ;
            }
            else{

                // agar to left child present hain curr node ka then we need to first travel to right most child of this subtree and phir wha se hme link baithana hoga us left subtree k right most child ka with curr node --> jo ki root hain is subtree ka and agar phle se linked hain to phir usko remove krna hoga

                TreeNode* prev = curr -> left ;
                while(prev -> right != NULL and prev -> right != curr){
                    prev = prev -> right ;
                }

                if(prev -> right == NULL){prev -> right = curr ; curr = curr -> left ;} // link baitha diya hmne aur uske baad to hme curr k left child mein move krna hoga to bhi kr diaa

                else{
                    prev -> right = NULL ; // iska mtlb ki link phla se tha so ab hme link ko cur krna hoga plus curr ko right mein move krna hoga aur saath hi curr ko ans mein push kr dena hoga --> is point pr left subtree khtm ho chuka hain curr node ka
                    ans.push_back(curr -> val) ;
                    curr = curr -> right ;

                    // is point ka importance tbhi smjh aaega jb aap above given tree pr dry run kroge
                }
            }
        }

        return ans ;
    }
};