/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    static bool isValid(vector<string> board , int row, int col, int n){
        
        // checking prev upper side diagonals
        int currRow(row) , currCol(col) ;
        while(currRow >= 0 and currCol >= 0){
            if(board[currRow][currCol] == 'Q'){return false ;}
            currRow-- , currCol-- ;
        }

        // checking prev columns
        currCol = col;
        while(currCol >=0){
            if(board[row][currCol] == 'Q'){return false ;}
            currCol-- ;
        }
        
        // checking downward diagonals
        currCol= col , currRow = row ;
        while(currRow < n and currCol >=0){
            if(board[currRow][currCol] == 'Q'){return false ;}
            currRow++ , currCol-- ;
        }
        return true ;
    }

    static void doWork(vector<vector<string>> &ans, vector<string> board, int col){
        
        // base condition --> since we are moving forward by filling each column from the start --> so when we would reach the end of the board i.e., we are on the nth column --> then we would push the string into the ans
        if(col == board.size()){ans.push_back(board) ; return ;}

        for(int i=0 ; i < board.size() ; i++){
            // apan column wise chal rhe
            if(isValid(board, i , col , board.size())){
                board[i][col] = 'Q' ;
                doWork(ans, board, col+1) ;
                board[i][col]= '.' ;
            }
        }

        // khtm
    }

public:
    vector<vector<string>> solveNQueens(int n){
        // code here

        string s(n , '.') ; // this string represents a single row of the board and we initialised every cell with '.'

        vector<string> board(n, s) ; // this would represent the board with n rows of string (which is itself of n size each) --> altogether it would form a board of nxn size

        vector<vector<string>> ans ; // this would contain all the possible configurations of the board such that n-queens would be possible

        doWork(ans, board, 0) ;
        
        return ans ;
    }
};
// @lc code=end
