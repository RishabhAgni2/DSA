class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // take care seats
        vector<int> diff(n+2,0);
        for(auto &p:bookings){
            int first = p[0];
            int last = p[1];
            int seats = p[2];
            diff[first] += seats;
            diff[last+1] -= seats;

        }
        int curr=0;
        vector<int> ans(n);
        for(int i=1;i<=n;i++){
            curr += diff[i];
            ans[i-1]=curr;
        }
        return ans;
    }
};