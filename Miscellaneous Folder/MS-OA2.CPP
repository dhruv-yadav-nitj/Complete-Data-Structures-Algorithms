#include <bits/stdc++.h>
using namespace std;

/* 
Problem : 

There is a string S of length N consisting of lowercase English letters (the letters are numbered from 1 to N). We are going to Insert M '$' characters into the string in the order described by the contents of array C. The K-th '$' character (for K from 0 to M-1) is inserted after the C[K]-th letter in S. (the '$' character is not considered a letter). For example, given S = "aabcba" and C= [1,3,2], we will insert three '$' characters into S, thus obtaining following strings: "asabcba"-"asabscba" "asasbscba".

What is the minimum number of steps after which we can stop, such that there is at least one's character between every two occurrences of the same letter?

In the example above, after the first insertion there are no characters between the two letters 'b' (3rd and 5th letters in S), but after the second insertion there is a 's' between every two occurrences of every letter, so the answer is 2

Write a function:

int solution(string &S, vector<int>&C); that, given a strings of length N and an array C of length M, returns an integer- the number of insertions after which there will be a '$' character between every two occurrences of the same letter. If the condition is not met after all the insertions have been made, return -1.
*/