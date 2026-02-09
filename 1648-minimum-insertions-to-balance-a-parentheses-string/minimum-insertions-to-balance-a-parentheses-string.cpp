class Solution {
public:
    int minInsertions(string s) {
        int need = 0;
        int res=0;
        for(char c:s){
            if(c=='('){
                need += 2;
                if(need%2==1){
                    res++;
                    need--;
                }
            }else{
                need--;
                if(need==-1){
                    res++;
                    need=1;
                }
            }
        }
        return need + res;
    }
};