class Solution {
public:
    vector<int> diStringMatch(string s) {
        //greedy + two pointer
        int n= s.size();
        int l=0,h=n;
        vector<int> ans;
        for(char c:s){
            if(c=='I'){
                ans.push_back(l++);
            }else{
                ans.push_back(h--);
            }
        }
        ans.push_back(l);
        return ans;
    }
};