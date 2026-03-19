class Solution {
private:
   long long fact(int n){
    if(n==0||n==1){
        return 1;
    }
     return n*fact(n-1);
   }
public:
    bool isDigitorialPermutation(int n) {
        vector<int> freqN(10,0);
        int temp=n;
        while(temp>0){
            freqN[temp%10]++;
            temp /= 10;
        }
        vector<int> sumN(10,0);
        temp = n;
        int sum =0;
        while(temp>0){
             sum += fact(temp%10);
             temp /= 10;
        }
        int temp1 = sum;
        while(temp1>0){
            sumN[temp1%10]++;
            temp1 /= 10;
        }
        return freqN==sumN;
    }
};