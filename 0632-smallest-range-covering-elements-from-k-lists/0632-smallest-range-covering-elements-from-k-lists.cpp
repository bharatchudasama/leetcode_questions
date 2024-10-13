//approach 1 
// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int k = nums.size();
//         vector<int> vec(k, 0);
//         vector<int> result = {-1000000, 1000000};
//         while (true) {
//             int minele = INT_MAX;
//             int maxele = INT_MIN;
//             int minindex = 0;
//             for (int i = 0; i < k; i++) {
//                 int listindex = i;
//                 int eleindex = vec[i];
//                 int element = nums[listindex][eleindex];
//                 if (element < minele) {
//                     minele = element;
//                     minindex = listindex;
//                 }
//                 maxele = max(maxele, element);
//             }
//             if (maxele - minele < result[1] - result[0]) {
//                 result[1] = maxele;
//                 result[0] = minele;
//             }
//             int nextindex = vec[minindex]+1;
//             if (nextindex >= nums[minindex].size()) {
//                 break;
//             }
//             vec[minindex] = nextindex;
//         }
//         return result;
//     }
// };

//approach 2 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        //{element, listIdx, idx} //vector<int>{a, b, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx     = curr[2];

            if(maxEl - minEl < resultRange[1] -  resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //decrease the rangen fro minimums ide
            if(idx+1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][idx+1];
                pq.push({nextElement, listIdx, idx+1});
                maxEl = max(maxEl, nextElement);
            } else {
                break;
            }
        }

        return resultRange;
    }
};
