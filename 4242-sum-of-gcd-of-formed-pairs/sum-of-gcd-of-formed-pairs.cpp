class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        //building the prefixGcd---
        int mx=0;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            prefixGcd[i]=__gcd(mx,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans =0;
        int l=0,r=n-1;
        while(l<r){
            ans += __gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};