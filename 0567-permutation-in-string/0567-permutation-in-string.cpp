class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int n=s1.length(),m=s2.length();
        if(n>m){
            return false;
        }
        int i=0,j=0;
        while(i<n){
            freq1[s1[i]-'a']+=1;
            i++;
        }
        i=0;
        while(j<m){
            freq2[s2[j]-'a']++;
            if(j-i+1>n){
                freq2[s2[i]-'a']--;
                i++;
            }
            if(freq1==freq2){
                return true;
            }
            j++;
        }
        return false;
    }

};