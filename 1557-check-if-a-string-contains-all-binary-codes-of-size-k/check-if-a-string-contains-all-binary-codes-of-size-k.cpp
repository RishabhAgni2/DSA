class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k;  // 2^k
        unordered_set<string> seen;

        for (int i = 0; i + k <= s.size(); i++) {
            seen.insert(s.substr(i, k));
            if (seen.size() == need) return true;
        }

        return false;
    }
};