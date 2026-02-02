class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //this is harder version of indexing concept
        int n = nums.size();
        //place numbers at correct positions 
        for(int i=0;i<n;i++){
            while(nums[i]>=1&&nums[i]<=n&&nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        //find the first missing number;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};