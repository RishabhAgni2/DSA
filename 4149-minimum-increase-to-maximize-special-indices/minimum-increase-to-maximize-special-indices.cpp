class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();

        // Step 1: odd indices ka cost (prefix)
        vector<long long> odd_pref(n, 0);
        long long totalOdd = 0;

        for (int i = 1; i < n - 1; i += 2) {
            int need = max(nums[i - 1], nums[i + 1]) + 1;
            if (nums[i] < need) {
                totalOdd += (need - nums[i]);
            }
            odd_pref[i] = totalOdd;
        }

        // agar n odd hai → sirf odd pattern possible
        if (n % 2 == 1) return totalOdd;

        // Step 2: even indices ka cost (suffix)
        vector<long long> even_suff(n, 0);
        long long totalEven = 0;

        for (int i = n - 2; i > 0; i -= 2) {
            int need = max(nums[i - 1], nums[i + 1]) + 1;
            if (nums[i] < need) {
                totalEven += (need - nums[i]);
            }
            even_suff[i] = totalEven;
        }

        // Step 3: full odd vs full even
        long long ans = min(totalOdd, totalEven);

        // Step 4: mix try karo (split point)
        for (int i = 2; i < n - 2; i += 2) {
            long long left = odd_pref[i - 1];   // left side odd peaks
            long long right = even_suff[i + 2]; // right side even peaks
            ans = min(ans, left + right);
        }

        return ans;
    }
};