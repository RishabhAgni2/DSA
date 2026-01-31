class NumArray {
    vector<int> prefix;//i declare this to store prefix sum 
public:
    NumArray(vector<int>& nums) {
        //logic
        int n = nums.size();
        prefix.resize(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */