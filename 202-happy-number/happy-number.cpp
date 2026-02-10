class Solution {
private:
    int getnext(int n){
        int sum =0;
        while(n>0){
            int d = n%10;
            sum += d*d;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && !seen.count(n)){
            seen.insert(n);
            n = getnext(n);
        }
        return n==1;
    }
};