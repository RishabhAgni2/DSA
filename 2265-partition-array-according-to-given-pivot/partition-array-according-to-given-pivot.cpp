class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l,e,g;
        for(int num:nums){
            if(num<pivot)l.push_back(num);
            else if(num==pivot)e.push_back(num);
            else g.push_back(num);
        }
        vector<int> ans;
        ans.insert(ans.end(),l.begin(),l.end());
        ans.insert(ans.end(),e.begin(),e.end());
        ans.insert(ans.end(),g.begin(),g.end());
        return ans;
    }
};