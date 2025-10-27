class Solution {
public:
    long long removeZeros(long long n) {
           string str=to_string(n);
        long long ans=0;
        for(auto ch : str) {
            if(ch!='0') {
                ans=ans*10+(ch-'0');
            }
        }
        return ans;
    }
};