class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // max heap: {frequency, character}
        priority_queue<pair<int, char>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }

        string result = "";
        pair<int, char> prev = {0, '#'}; // previously used character

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            // add current character
            result.push_back(curr.second);
            curr.first--;

            // push previous back if it still has remaining count
            if (prev.first > 0) {
                pq.push(prev);
            }

            // update prev to current
            prev = curr;
        }

        // if we couldn't use all characters, return empty
        if (result.length() != s.length()) {
            return "";
        }

        return result;
    }
};