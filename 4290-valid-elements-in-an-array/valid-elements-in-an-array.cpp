class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2)
            return nums;
        
        vector<int> Lmax(n - 1), Rmax(n - 1);
        Lmax[0] = nums[0];
        Rmax[n - 2] = nums[n - 1];
        for (int i = 1, j = n - 3; i <= n - 2 && j >= 0; i++, j--) {
            Lmax[i] = max(Lmax[i - 1], nums[i]);
            Rmax[j] = max(Rmax[j + 1], nums[j + 1]);
        }

        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > Lmax[i - 1] || nums[i] > Rmax[i])
                ans.push_back(nums[i]);
        }
        ans.push_back(nums[n - 1]);
        return ans;
    }
};