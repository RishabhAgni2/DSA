class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> states(101,0);
        for(int x:bulbs){
            states[x] ^= 1;
        }
        vector<int> ans;
        for(int i =0;i<101;i++){
            if(states[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};