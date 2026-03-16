class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> freq;
        for(int i:nums1)freq[i]++;
        for(int i:nums2)freq[i]++;
        //ckeck the possiblity does the answer can be possible
        for(auto &x:freq){
            if(x.second%2!=0)return -1;
        }
        unordered_map<int,int> count1;
        for(int i:nums1)count1[i]++;
        int swaps=0;
        for(auto &p:freq){
            int val = p.first;
            int total = p.second;
            int needed=total/2;
            if(count1[val]>needed){
                swaps += count1[val]-needed;
            }
        }
        return swaps;
    }
};