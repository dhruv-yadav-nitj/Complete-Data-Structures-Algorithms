#include <bits/stdc++.h>
using namespace std ;

class Node{
public:
    int data ; Node* left ; Node* right ;
    Node(int data){
        this->data = data ;
        this->left = NULL ; this->right= NULL ;
    }
};

int main(int argc, char const *argv[])
{
    Node* root = new Node(1) ;
    root-> left = new Node(2) ; root -> right = new Node(3) ; 
    root-> left -> left = new Node(4) ; root -> left -> right = new Node(5) ;

    cout << root -> left -> right -> data << endl ; // to verify whether the tree is created correctly or not
    return 0;
}
