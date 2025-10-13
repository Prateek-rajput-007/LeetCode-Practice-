class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int avg = totalSum / n;

        for (int i = 1; i <= 101; i++) {
            if (i > avg && freq.find(i) == freq.end()) {
                return i;
            }
        }

        return -1;
    }
};