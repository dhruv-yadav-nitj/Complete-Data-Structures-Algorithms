
// approach #2 : time complexity: O(n)

// in this we have used that property of bst --> ki left mein element root se cchota hi hoga and right mein element root se badha hi hoga

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // code here
        int index = 0;
        return createBST(preorder, index, INT_MAX) ;        
    }

    TreeNode* createBST(vector<int> preorder, int &index, int bound){

        // base condition
        if(index == preorder.size() or preorder[index] > bound){ // agar curr element jyada nikal gya hain bound se then we have to return because yha pr to nhi ho paaega
            return NULL ;
        }

        TreeNode* root = new TreeNode(preorder[index]) ;
        index++ ; // hmne function mein index ko as a reference pass kia hain bcz aisa ho skta hain ki left mein jaae aur kuch changes hi naa ho then hme waapis se usi index pr aana hoga --> isko dry run krke smjho , smjh aa jaaega very easy logic

        root -> left = createBST(preorder, index, root -> val) ;
        root -> right = createBST(preorder, index, bound) ;

        return root ;
    }
};