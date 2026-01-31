class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //frequency check is the logic
        unordered_map<int,int> fr;
        vector<int> ans;
        for(auto num:nums1){
            fr[num]++;
        }
        for(auto num:nums2){
            if(fr[num]>0){
                ans.push_back(num);
                fr[num]--;
            }
        }
        return ans;
    }
};