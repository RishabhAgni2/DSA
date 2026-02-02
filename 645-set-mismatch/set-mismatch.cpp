class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //This is combination of missing and duplicates 
        int dup = -1;
        int mis = -1;
        for(int i=0;i<nums.size();i++){
            int idx = abs(nums[i])-1;
            if(nums[idx]<0){
                dup = abs(nums[i]);
            }else{
                nums[idx]=-nums[idx];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                mis = i+1;
            }
        }
        return {dup,mis};
    }
};