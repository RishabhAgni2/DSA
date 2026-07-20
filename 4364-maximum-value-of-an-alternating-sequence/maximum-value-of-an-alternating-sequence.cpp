
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long nn = n, ss = s, mm = m;
        long long ans = ss;
        if(n == 1) return ans;

        ans = (long long)(ss+(nn/2)*mm-(nn/2-1));

        return ans;
    }
};