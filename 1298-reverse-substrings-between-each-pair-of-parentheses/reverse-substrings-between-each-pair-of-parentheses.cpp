class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
       
        for (char c : s) {
             string res="";
            if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                st.pop(); // to remove'('
                for (char ch : res) {
                    st.push(ch);
                }
                
            }else{
                st.push(c);
            }
           
        }
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};