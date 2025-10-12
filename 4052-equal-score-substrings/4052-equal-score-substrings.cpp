class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.length();
        
        for (int i = 0; i < n-1; i++) {
            int sum1 = 0, sum2 = 0;

            // for 1st sub-string
            for (int j = 0; j <= i; j++) sum1 += (s[j]-'a'+1);
            // for 2nd sub-string
            for (int j = i+1; j < n; j++) sum2 += (s[j]-'a'+1);
            if (sum1 == sum2) return true;
        }
        return false;
    }
};