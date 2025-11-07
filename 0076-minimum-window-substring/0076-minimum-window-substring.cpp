class Solution {
public:
    bool solve(vector<int>& have, vector<int>& need) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < need[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();

        if (len1 < len2) {
            return "";
        }

        vector<int> need(256, 0);
        vector<int> arr(256, 0);
        int res = INT_MAX, ansIndex = -1;

        for (int i = 0; i < len2; i++) {
            need[p[i]]++;
        }

        int start = 0, end = 0;

        while (end < len1) {
            arr[s[end]]++;

            while (solve(arr, need)) {  
                int len = end - start + 1;
                if (res > len) {
                    res = len;
                    ansIndex = start;
                }
                arr[s[start]]--;
                start++;
            }
            end++;
        }

        if (ansIndex == -1) {
            return "";
        }

        return s.substr(ansIndex, res);
    }
};
