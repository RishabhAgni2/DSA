class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prev = 0, cnt = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cnt++;
            else {
                prev = cnt;
                cnt = 1;
            }
            if (cnt <= prev) res++;
        }
        return res;
    }
};