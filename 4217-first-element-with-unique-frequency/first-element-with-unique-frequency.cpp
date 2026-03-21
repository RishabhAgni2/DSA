class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        unordered_map<int,int> cntFreq;
        for(auto &p:freq){
            cntFreq[p.second]++;
        }
        for(int x:nums){
            if(cntFreq[freq[x]]==1){
                return x;
            }
        }
        return -1;
    }
};