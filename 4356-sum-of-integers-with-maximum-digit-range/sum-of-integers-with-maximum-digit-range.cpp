class Solution {
private:
    int largest(int n){
        if(n == 0) return 0;
        int maxi = 0;
        while(n){
            maxi = max(maxi, n % 10);
            n /= 10;
        }
        return maxi;
    }

    int smallest(int n){
        if(n == 0) return 0;
        int mini = 9;
        while(n){
            mini = min(mini, n % 10);
            n /= 10;
        }
        return mini;
    }

public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        int sum = 0;

        // Find maximum digit range
        for(int num : nums){
            int range = largest(num) - smallest(num);
            maxRange = max(maxRange, range);
        }

        // Sum all numbers having maximum digit range
        for(int num : nums){
            int range = largest(num) - smallest(num);
            if(range == maxRange)
                sum += num;
        }

        return sum;
    }
};