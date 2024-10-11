class Solution {
private:
    int f(int i ,int j , int n, vector<vector<int>>& dp , vector<vector<int>>& arr){
        if(i==n-1){return arr[i][j];}
        if(dp[i][j]!=-1){return dp[i][j];}
        int d = arr[i][j] + f(i+1,j,n,dp,arr);
        int dg = arr[i][j] + f(i+1,j+1,n,dp,arr);
        return dp[i][j] = min(d,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); 
        return f(0,0,n,dp,triangle);
    }
};