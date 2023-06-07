
// iterative approach

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool isSymmetric(TreeNode* root){
        // code here
        if(root == NULL){return true ;}

        // tree with single node
        if(root -> left == NULL and root -> right == NULL){return true ;}

        // ho skta hain tree ka left NULL or right kuch node ho or vice versa
        if(root -> left == NULL or root -> right == NULL){return false ;}

        queue<TreeNode*> q ; q.push(root) ; q.push(root) ;

        while(!q.empty()){
            TreeNode *lNode = q.front() ; q.pop() ;
            TreeNode *rNode = q.front() ; q.pop() ;

            if(lNode -> val != rNode-> val){return false ;}

            // agar dono hi null nhi hain tb queue mein daal do
            if(lNode -> left != NULL and rNode -> right != NULL){q.push(lNode-> left) ; q.push(rNode -> right) ;}
            else if((lNode -> left == NULL and rNode -> right != NULL) or (lNode -> left != NULL and rNode -> right == NULL)){return false ;}
            // but agar ek NULL hain aur dusra NULL nhi hain then return false
            // and if dono hi NULL hain tb to kuch krna hi nahi hain

            // similar as above
            if(lNode -> right != NULL and rNode -> left != NULL){q.push(lNode-> right) ; q.push(rNode -> left) ;}
            else if((lNode -> right == NULL and rNode -> left != NULL) or (lNode -> right != NULL and rNode -> left == NULL)){return false ;}
        }
        return true ;
    }
};