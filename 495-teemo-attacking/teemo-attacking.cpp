class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //take care overlapping thing
        int n = timeSeries.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            int gap = timeSeries[i+1]-timeSeries[i];
            ans += min(gap,duration);
        }
        ans += duration;
        return ans;
    }
};