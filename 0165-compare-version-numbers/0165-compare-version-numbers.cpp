class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            int digit1 = 0, digit2 = 0;
            while (i < n && version1[i] != '.') digit1 = digit1 * 10 + (version1[i++] - '0');
            while (j < m && version2[j] != '.') digit2 = digit2 * 10 + (version2[j++] - '0');
            if (digit1 < digit2) return -1;
            if (digit1 > digit2) return 1;
            i++; j++;
        }
        return 0;
    }
};