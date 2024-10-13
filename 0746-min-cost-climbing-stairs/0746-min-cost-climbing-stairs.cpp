class Solution {

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1= cost[0] ,prev2=cost[1],curr= 0 ;
        if(cost.size() == 2){
            return min(prev1,prev2);
        }
        
        for(int i = 2; i<cost.size() ; i++){
            curr =cost[i]+ min(prev1,prev2);
            prev1=prev2;
            prev2 = curr;
        }
        return min(prev2,prev1);
    }
};