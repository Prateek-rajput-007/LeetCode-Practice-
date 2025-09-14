class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> ans;
        set<int> st; // to track distinct elements
        
        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        for (int i = 0; i < nums.size() && ans.size() < k; i++) {
            if (st.find(nums[i]) == st.end()) { // not seen before
                ans.push_back(nums[i]);
                st.insert(nums[i]);
            }
        }
        
        return ans;
    }
};
