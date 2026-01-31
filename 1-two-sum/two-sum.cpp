class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //greedy approach
        vector<pair<int,int>> a;//element,index
        for(int i = 0;i<nums.size();i++){
            a.push_back({nums[i],i});
        }
        //sorting the array 'a'
        sort(a.begin(),a.end());
        int i =0,j=a.size()-1;
        //conditions of fullfilling the  Two Sum conditons
        while(i<=j){
            int pairSum = a[i].first + a[j].first;
            if(pairSum==target){
                return {a[i].second,a[j].second};
            }
            if(pairSum > target){
                j--;
            }else {
                i++;
            } 
        }
        return {};
        
    }
};
// unordered_map<int,int> mp; // value -> index
        // for (int i = 0; i < nums.size(); i++) {
        //     int more = target - nums[i];
        //     if (mp.find(more) != mp.end()) {
        //         return {mp[more], i}; // return indices
        //     }
        //     mp[nums[i]] = i;
        // }
        // return {}; // should never reach here for valid input