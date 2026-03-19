class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int one =0,two=0;
        bool first = true;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                first = !first;
            }
            if((i+1)%6==0){
                first = !first;
            }
            if(first){
                one += nums[i];
            }else{
                two += nums[i];
            }
        }
       return (int)(one-two);
    }
};