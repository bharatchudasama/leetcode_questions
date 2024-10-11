class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(auto s: str){
            if(s=='[' || s=='{' || s=='('){
                st.push(char(s));
            }
            else if(!st.empty() && s==']' && st.top() == '['){
                st.pop();
            }
            else if(!st.empty() && s==')' && st.top() == '('){
                st.pop();
            }
            else if(!st.empty() && s=='}' && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s);
            }
                
        }
        return st.empty();
    }
};