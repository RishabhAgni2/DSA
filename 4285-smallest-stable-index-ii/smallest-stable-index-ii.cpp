class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
       vector<int> mini(n);
        int mint = INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<mint)mint=nums[i];
            mini[i] = mint;
        }
        int mxt = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]>mxt)mxt = nums[i];
            if(mxt-mini[i]<=k)return i;

        }
        return -1;
    }
};