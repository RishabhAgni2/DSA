class Solution {
public:
    void sortColors(vector<int>& nums) {
        //put l and m on first element 
        int l=0,m=0;
        //h at last element 
        int h=nums.size()-1;

        while(m<=h){
            //here if nums[m] == 0 we swap {nums[m],nums[l]}since i need to put '0' first;
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            //here if we get nums[m]==1 than we do nothing moves our pointer m++
            else if(nums[m]==1){
                m++;
            }
            // if in starting we get the nums[m] ==2 than we swap with nums[h]and moves back the h--
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
        
    }
};