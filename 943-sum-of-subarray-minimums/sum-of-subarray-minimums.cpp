class Solution {
private: 
    vector<int> findnse(vector<int>&arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int>&arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        long long total =0;
        const int MOD = 1e9 +7;
        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            total = (total + (left*right*1LL*arr[i])%MOD)%MOD;
        }
        return total;
    }
};