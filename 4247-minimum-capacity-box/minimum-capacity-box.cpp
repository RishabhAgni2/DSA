class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();
        int mindiff = INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            //diff = capacity[i]-itemSize;
            if(capacity[i]>=itemSize){
                int diff = capacity[i]-itemSize;
                if(diff<mindiff){
                    ans =i;
                    mindiff = diff;
                }
            }
        }
        return ans;
    }
};