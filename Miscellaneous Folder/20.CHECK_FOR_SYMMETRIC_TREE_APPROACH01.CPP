
// recursive approach

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
    bool doWork(TreeNode *l, TreeNode *r){

        // base condition
        if(l == NULL or r == NULL){return l == r ;}
        if(l -> val != r -> val){return false ;}

        // agar left ka left aur right ka right same hain tb --> left ka right aur right ka left compare kro
        if(doWork(l -> left, r -> right)){
            return doWork(l -> right, r -> left) ;
        }
        else{return false ;}
    }
public:
    bool isSymmetric(TreeNode *root){
        // code here
        if(root == NULL or (root -> left == NULL and root -> right == NULL)){return true ;}
        return doWork(root -> left, root -> right);
    }
};