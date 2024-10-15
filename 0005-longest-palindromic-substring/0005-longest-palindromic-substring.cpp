class Solution {
public:
    
    bool pallindrome(int i , int j ,string& s,vector<vector<int>>& dp){
        if(i>=j){
            return 1 ;}
        if(dp[i][j] != -1){return dp[i][j];}
        if(s[i] == s[j]){
            return dp[i][j] = pallindrome(i+1,j-1,s,dp);
        }
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int maxlen= 0 ;
        int n = s.size() ;
        int sp = 0;
        vector<vector<int>> dp(n , vector<int> (n,-1));
        for(int i = 0 ; i<n ;i++){
            for(int j  = 0 ; j<n ; j++){
                if(pallindrome(i,j,s,dp)){
                    if(maxlen < j-i+1 ){
                        maxlen = j - i +1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};