class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //need to take of capacity if goes above return false 
        int n= trips.size();
        vector<int> diff(1001,0);
        for(auto &p:trips){
            int passenger=p[0];
            int from = p[1];
            int to = p[2];
            diff[from] += passenger;
            diff[to] -= passenger;
        }
        int curr = 0;
        for(int i=0;i<=1000;i++){
            curr += diff[i];
            if(curr>capacity)return false;
        }
         return true;
    }
};