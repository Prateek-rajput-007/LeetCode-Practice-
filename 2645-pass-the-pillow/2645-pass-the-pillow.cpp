class Solution {
public:
    int passThePillow(int n, int time) {
        vector<int>v1; 
        vector<int>v2;

        int i=1;
        while(i<=n){
            v1.push_back(i++);
        } 

        i=n-1;
        while(i>0){
            v2.push_back(i--);
        }

        vector<int>ans;
        int cnt=1;

        for(int it:v1)ans.push_back(it);
        for(int it:v2)ans.push_back(it);

        while(cnt<=time){

            int i=2;
            while(i<=n){
                ans.push_back(i++);
                cnt++;
            } 

            i=n-1;
            while(i>0){
                ans.push_back(i--);
                cnt++;
            }
        }

        return ans[time];
    }
};
