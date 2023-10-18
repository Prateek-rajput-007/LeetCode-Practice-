class Solution {
public:
    int passThePillow(int n, int time) {
        int index=1;
        int cnt=1;
        while(time--){

          if(index==1)
              cnt=1;
            if(index==n)
                cnt=-1;
            
          index+=cnt;

 }
        return index;
    }
};