class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int N=fruits.size();
        unordered_map<int, int>mp;
        int start=0;
        int end=0;        
        int ans = 0;
        while(end<N){
            mp[fruits[end]]++;
            if(mp.size()<=2){
                ans = max(ans, end-start+1);
            }else if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[start]]--;
                    if(mp[fruits[start]]==0){
                        mp.erase(fruits[start]);
                    }
                    start++;
                }                
            }
            end++;
        }        
        return ans;
    }
};