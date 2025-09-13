class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,int> mp2;

        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                mp[s[i]]++;
            }
            else{
                mp2[s[i]]++;
            }
        }

        int m1=INT_MIN, m2=INT_MIN;

        for(auto it: mp){
            if(m1 < it.second){
                m1 = max(m1, it.second);
            }
        }
         for(auto it: mp2){
            if(m2 < it.second){
                m2 = max(m2, it.second);
            }
        }
        if(m1!=INT_MIN && m2!=INT_MIN){
            return m1+m2;
        }
        else if(m1==INT_MIN){
            return m2;
        }
        return m1;

    }
};