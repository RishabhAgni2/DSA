class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int num:s){
            if(s.find(num-1)==s.end()){
                int longest = 1;
                int current = num;
                while(s.find(current+1)!=s.end()){
                    longest++;
                    current = current + 1;
                }
                ans = max(ans,longest);
            }
        }
        return ans;
    }
};