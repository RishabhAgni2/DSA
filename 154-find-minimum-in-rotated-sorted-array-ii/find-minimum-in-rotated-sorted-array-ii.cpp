class Solution {
public:
    int findMin(vector<int>& nums) {
        //this hard level search space based question  
        int low = 0;
        int high = nums.size() - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high]){
                // minimum lies in right part
                low = mid + 1;
            }
            else if(nums[mid] < nums[high]){
                // minimum lies in left part including mid
                high = mid;
            }
            else{
                // duplicates case
                high--;
            }
        }
        return nums[low];
    }
};
