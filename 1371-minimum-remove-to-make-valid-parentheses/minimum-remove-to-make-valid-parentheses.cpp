class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.size();
        vector<bool> rem(n,false);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    rem[i]=true;
                }
            }
        }
        while(!st.empty()){
            rem[st.top()]=true;
            st.pop();
        }
        string ans = "";
        for(int i=0;i<n;i++){
            if(!rem[i])ans += s[i];
        }
        return ans;
    }
};