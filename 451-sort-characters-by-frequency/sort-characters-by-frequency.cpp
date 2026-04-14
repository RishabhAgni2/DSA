class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        vector<pair<char, int>> v;
        for (auto it : freq) {
            v.push_back(it);
        }
        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { return a.second > b.second; });
        string res="";
        for(auto it:v){
            while(it.second!=0){
                res += it.first;
                it.second--;
            }
        }
        return res;
    }
};