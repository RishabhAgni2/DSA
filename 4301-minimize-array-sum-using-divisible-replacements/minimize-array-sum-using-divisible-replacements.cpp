using ll = long long;

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        ll res = 0;
        vector<int> arr;
        sort(nums.begin(), nums.end());

        for(int &e: nums){
            if(arr.empty()){
                arr.push_back(e);
                res += e;
                continue;
            }

            bool flag = 1;
            int val = e;
            for(const auto& a: arr){
                if(e % a == 0){
                    val = a;
                    flag = 0;
                    break;
                }
            }
            if(flag) arr.push_back(e);
            res += val;
        }

        return res;
    }
};