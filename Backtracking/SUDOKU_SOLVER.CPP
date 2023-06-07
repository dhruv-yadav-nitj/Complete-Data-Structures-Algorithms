/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool isValid (vector<vector<char>> board, int row, int col, char k){
        // function to check if the digit k can be inserted at the given position or not

        // so we would check in the row , in the column and in the box --> so we can either use three different loops for the purpose or we can adjust all the three conditions in a single loop

        for(int i=0 ; i < board.size() ; i++){
            if(board[i][col] == k){return false ;} // ye to hogya same column wala cond.
            if(board[row][i] == k){return false ;} // ye hogya same row wla condition

            // isko dhyaan rkhe --> rat le ye formula
            if(board[(row/3)*3 + i/3][(col/3)* 3 + (i%3)] == k){return false ;}
        }

        return true ;
    }
    bool doWork(vector<vector<char>> &board){
        // main-recursion-function

        // yrr hm na recursion end tbhi krenge jb saare unfilled elements shi tarike se fill ho chuke ho --> agar ek bhi cell khaali pdha hain mtlb hme kuch krna chaiye

        for(int i=0 ; i < board.size() ; i++){
            for(int j=0 ; j < board[i].size() ; j++){
                if(board[i][j] == '.'){
                    // agar ye block free hain tbhi ghuso isme
                    
                    // aur is block mein 1 se lekar 9 tk saare numbers try krke dekh lo
                    for(char k = '1' ; k <= '9'; k++){
                        if(isValid(board, i, j , k)){
                            board[i][j] = k ;

                            if(doWork(board)){return true ;}
                            else{
                                
                                // agr ye configuration lekar solution nhi mil rha means is digit ko remove krna pdhega
                                board[i][j] = '.' ;
                            }
                        }
                    }

                    // yrr dekho hmne na is position pr 1 se lekar 9 tk saare digits try kr lie but agar abhi tk return true nhi kia hoga iska mtlb phle ke steps mein kahi pr galat digit place hua hain so iska configuration nhi baith rha so return false
                    return false ;
                }
            }
        }

        // agar sb kuch krne k baad saare configuration baith gye shi iska mtlb true return kr de --> is line tk code aa gya mtlb sudoku solve ho chuka hain
        return true ;
    }
public:
    void solveSudoku(vector<vector<char>> &board){

        // code here
        doWork(board) ;
    }
};
// @lc code=end
