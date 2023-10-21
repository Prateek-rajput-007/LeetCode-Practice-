class Solution {
public:
    bool checkPerfectNumber(int num) {
        int n=num,sum=0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                sum+=i;
            }
        }
        if(sum==n){
            return 1;
        }
        return 0;
    }
};