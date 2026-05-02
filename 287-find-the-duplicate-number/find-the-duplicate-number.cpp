class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1; // n

        while (low < high) {
            int mid = low + (high - low) / 2;

            int count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }

            if (count > mid) {
                // duplicate is in left half
                high = mid;
            } else {
                // duplicate is in right half
                low = mid + 1;
            }
        }

        return low;
    }
    
};