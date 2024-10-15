class Solution {
public:
    int f(string& text1, string& text2 , int  i ,int j ,vector<vector<int>> &dp){
        if(i < 0 || j< 0){return 0;}
        if(dp[i][j] != -1){return dp[i][j];}
        if( text1[i] == text2[j]){return dp[i][j] = 1 + f(text1,text2,i-1,j-1,dp);}
        else
         return dp[i][j] = max(f(text1,text2,i-1,j,dp),f(text1,text2,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1)); 
        return f(text1,text2,n-1,m-1,dp);
    }
// int lcsUtil(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
//     if (ind1 < 0 || ind2 < 0)return 0;
//     if (dp[ind1][ind2] != -1)return dp[ind1][ind2];
//     if (s1[ind1] == s2[ind2])return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
//     else
//         return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
// }

// // Function to calculate the length of the Longest Common Subsequence
// int longestCommonSubsequence(string s1, string s2) {
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n, vector<int>(m, -1)); // Create a DP table
//     return lcsUtil(s1, s2, n - 1, m - 1, dp);
// }
};