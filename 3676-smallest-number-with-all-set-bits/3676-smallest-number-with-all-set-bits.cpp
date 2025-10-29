class Solution {
public:
    int smallestNumber(int n) {
        
        string s="";
        int count=0;
        while(n > 0){
            count++;
            n=n/2;
        }

        int x=0;
        for(int i=0;i<count;i++){
            x+=pow(2,i);
        }
        return x;
    }
};