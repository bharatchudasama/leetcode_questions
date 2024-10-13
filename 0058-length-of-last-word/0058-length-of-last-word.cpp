class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        
        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Now, count the length of the last word
        int c = 0;
        while (i >= 0 && s[i] != ' ') {
            c++;
            i--;
        }
        
        return c;
    }
};
