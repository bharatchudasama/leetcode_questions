//T.C. O(N(LOGN))
//S.C O(N)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1 , 0 );
        for(int i = 1 ; i< n+1 ; i++){
            if( i ==1 || i==2){
                ans[i] = 1;
                // cout<<" ans["<<i<<"] : "<<ans[i]<<endl;
                continue;
                }
            int temp = i,rem;
            rem = temp % 2; 
            int c = 0; 
            while(temp > 0){
                // cout<<"temp : "<<temp << " rem: "<< rem ;
                if(temp == 1 ){c++;break;}
                else if(rem == 1){c++;}
                temp  = temp /2;
                rem = temp %2;
                // cout<<endl;
            }
            ans[i] = c;
            // cout<<" c: "<<c<<" i: "<<i<<" ans["<<i<<"] : "<<ans[i]<<endl;
        } 
        return ans;

    }
};