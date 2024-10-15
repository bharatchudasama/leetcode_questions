class Solution {
public:
    long long minimumSteps(string s) {
        long long c= 0 ;
        long long  temp = 0; 
        for(int i = s.size()-1 ; i>=0 ;i--){
            if(s[i] == '1'){c = c + temp; }
            else if(s[i] == '0'){temp++;}

        }
        return c;
    }
};