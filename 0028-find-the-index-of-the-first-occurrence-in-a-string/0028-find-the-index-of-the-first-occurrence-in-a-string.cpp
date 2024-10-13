class Solution {
public:
    int strStr(string str1, string str2) {
        int j = 0 ;
        for(int i  = 0 ; i<str1.size()+1 ; i++){
            // cout<<i<<" "<<j<<endl;
            // cout<<"str1 : "<<str1[i]<<" str2 : "<<str2[j]<<endl; 
            if(str1[i] == str2[j]){
                
                if (j==str2.size()-1){return i-j ; }
                j++;
            }
            else{
                i= i-j;
                j=0;
            }
        }
        return -1;
    }
};