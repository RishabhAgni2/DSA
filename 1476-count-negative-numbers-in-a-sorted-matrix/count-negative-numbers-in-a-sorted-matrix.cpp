class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        int m = grid[0].size();
        for(int i=0;i<grid.size();i++){
            int left = 0,right = m-1;
            int firstneg=m;
            
            while(left<=right){
                int mid = left + (right-left)/2;
                if(grid[i][mid]<0){
                    firstneg = mid;
                    right=mid-1;
                }else{
                    left = mid+1;
                }
            } 
            cnt += (m-firstneg);
        }
        return cnt;
    }
};