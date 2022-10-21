// Question ->
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// 1. Insert a character
// 2. Delete a character
// 3. Replace a character
#include<bits/stdc++.h>
using namespace std;

int edit_distance(string &w1, string &w2, int i, int j, vector<vector<int>> &dp) {
        if(i == 0) 
        return j;
        if(j == 0) 
        return i;

        if(dp[i - 1][j - 1] != -1) 
        return dp[i - 1][j - 1];

        if(w1[i - 1] == w2[j - 1]) 
        return dp[i - 1][j - 1] = edit_distance(w1, w2, i - 1, j - 1, dp);
        else 
        return dp[i - 1][j - 1] = min(1 + edit_distance(w1, w2, i - 1, j, dp), min(1 + edit_distance(w1, w2, i - 1, j - 1, dp), 1 + edit_distance(w1, w2, i, j - 1, dp)));
    }
int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));

        return edit_distance(word1, word2, word1.size(), word2.size(), dp);
}

int main() {

    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1, word2);
    return 0;
}