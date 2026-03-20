class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int &it:nums){
            freq[it]++;
        }
        vector<int> vals;
        for(auto &p:freq){
            vals.push_back(p.first);
        }
        sort(vals.begin(),vals.end());
        int n = vals.size();
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
            if(freq[vals[i]]!=freq[vals[j]]){
                return {vals[i],vals[j]};
            }
           }
        }
        return {-1,-1};
    }
};