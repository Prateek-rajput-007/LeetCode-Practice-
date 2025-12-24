class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        for (char c : text) {
            freq[c]++;
        }

        unordered_map<char, int> required = {
            {'b', 1},
            {'a', 1},
            {'l', 2},
            {'o', 2},
            {'n', 1}
        };

        int count = INT_MAX;
        for (auto& [ch, req] : required) {
            if (freq.find(ch) == freq.end()) return 0;
            count = min(count, freq[ch] / req);
        }

        return count;
    }
};