#include <bits/stdc++.h>
using namespace std;

// isko yaad krne k alawa aur kuch solution to dikh nhi rha

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
    vector<int> preorderTraversal(TreeNode *root){
        // code here
        vector<int> ansPre, ansIn, ansPost ;
        if(root == NULL){return ansPre ;}

        stack<pair<TreeNode*, int>> s ; s.push({root , 1}) ;
        while(!s.empty()){
            auto x = s.top() ; s.pop() ;

            // pre mein to sbse phle root ghusana pdhta hain
            if(x.second == 1){
                ansPre.push_back(x.first->val) ;
                x.second++ ; s.push(x) ;

                if(x.first -> left != NULL){
                    s.push({x.first-> left , 1}) ;
                }
            }

            // in wla part --> increase 2 to 3 and also push the right
            else if(x.second == 2){
                ansIn.push_back(x.first-> val) ;
                x.second++ ; s.push(x) ;

                if(x.first -> right != NULL){
                    s.push({x.first-> right , 1}) ;
                }
            }

            // agar 3 hain mtlb post mein jaana hain aur ab isko waapis increment bhi nahi krna hain
            else{
                ansPost.push_back(x.first -> val) ;
            }
        }

        return ansPre ;
    }
};