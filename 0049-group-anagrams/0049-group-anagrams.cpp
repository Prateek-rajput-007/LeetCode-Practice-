class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Base case
		if(strs.size() == 1)
            return {{strs[0]}};
        
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        int n = strs.size();

        for(int i=0;i<n;i++){
            string t = strs[i];
            sort(t.begin(),t.end());
            mp[t].push_back(strs[i]);
        }

        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};