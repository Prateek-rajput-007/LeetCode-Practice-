class Solution {
public:
    int numberOfSubstringsWithFrequencyLessThanK( string s,int k){
        int n=s.size();
        int l=0;
        int r=0;
        int count=0;
        unordered_map<int,int>mpp;

        while(r<n){
            mpp[s[r]]++;

            while(mpp[s[r]]==k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }

            count+=r-l+1;
            r++;
        }

        return count;
    }
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        int totalSubstrings=(n*(n+1))/2;

        //total - number of substrings with frequency < k
        int ans=numberOfSubstringsWithFrequencyLessThanK( s, k);
        return totalSubstrings-ans;
    }
};