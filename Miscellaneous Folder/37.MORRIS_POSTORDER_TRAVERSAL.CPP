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

// to understand do a dry run on the following tree
// 1 2 3 4 5 NULL NULL NULL NULL NULL 6

class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root){

        // code here

        vector<int> ans ; if(root == NULL){return ans ;}
        TreeNode* curr = root ;
        while(curr != NULL){

            if(curr -> right == NULL){
                ans.push_back(curr -> val) ; curr = curr -> left ;
            }

            else{

                TreeNode* temp = curr -> right ;

                while(temp -> left != NULL and temp -> left != curr){
                    temp = temp -> left ;
                }

                if(temp -> left == NULL){
                    temp -> left = curr ; ans.push_back(curr -> val) ; curr = curr -> right ;
                }

                else{
                    temp -> left = NULL ; curr = curr -> left ;
                }

            }

        }

        reverse(ans.begin() , ans.end()) ; return ans ;

    }
};