class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        long long res = 0 ;
        for(int i = 0 ; i<k; i++){
            long long temp = pq.top();
            res = res + temp;
            pq.pop();
            int rem = temp % 3;
            if(rem > 0){temp = 1 + (temp / 3);}
            else{temp = temp /3;}
            pq.push(temp);
        }
        return res;
    }
};