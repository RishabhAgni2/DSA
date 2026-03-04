class Solution {
public:
    int lastRemaining(int n) {
        int head=1;//track the last remaining
        int step=1;//distance b/w numbers
        int remaining=n;
        bool left=true;
        while(remaining>1){
            if(left||remaining%2==1){
                head += step;
            }
            remaining /=2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};