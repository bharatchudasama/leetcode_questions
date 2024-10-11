//space optimiztion
class Solution {

public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> front(n);
        vector<int> dp(n);
        for(int j=0 ; j<n ;j++){
            front[j] = arr[n-1][j];
        }
        for(int i  = n-2 ; i>=0 ;i--){
            for(int j=i ; j>=0 ;j--){
                int d=arr[i][j] + front[j];
                int dg=arr[i][j] + front[j+1];
                dp[j] = min(d,dg);
            }
            front = dp;
        }
        return front[0];
    }
};