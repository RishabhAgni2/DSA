class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> mp;
        int limit = cbrt(n);
        
        for(int a =0;a<=limit;a++){
            int a3 = a*a*a;
            for(int b= a;b<=limit;b++){
                 int sum = a3 + b*b*b;
                 if(sum>n)break;
                 mp[sum]++;
            }
            
        }
        vector<int> ans;
        for(auto &it:mp){
            if(it.second >=2){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};