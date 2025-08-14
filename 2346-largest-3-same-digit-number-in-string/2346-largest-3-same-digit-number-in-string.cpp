class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";

        if (num.size() < 3)
            return res;

        for (int i = 0; i < num.size() - 2; i++) {
            if ((num[i] == num[i + 1]) && (num[i + 1] == num[i + 2])) {
                string res1 = num.substr(i, 3);
                if (res1 > res) {
                    res = res1;
                }
            }
        }

        return res;
    }
};