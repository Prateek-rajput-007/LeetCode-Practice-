class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans=0;
        sort(h.begin(),h.end());
        reverse(h.begin(),h.end());
        for(int i=0;i<h.size();i++){
            if(h[i]>0){
                h[i]=h[i]-i;
                if(h[i]>0){
                    ans+=h[i];
                }
                k--;
            }
            if(k<=0){
                break;
            }
        }
        return ans;
    }
};