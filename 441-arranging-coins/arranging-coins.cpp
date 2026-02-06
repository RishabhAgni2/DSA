class Solution {
public:
    int arrangeCoins(int n) {
        //-->binary search 
        long long l = 0, h = n;

        while(l <= h){
            long long mid = l + (h - l) / 2;
            long long coins = mid * (mid + 1) / 2;

            if(coins == n) return mid;
            else if(coins < n) l = mid + 1;
            else h = mid - 1;
        }
        return h; 
    }
};
