class Solution {
    void dfsAdjustParent(int curr, vector<vector<int>> &adjList, vector<int>& parent, string &s, vector<int>& lastSeen) {
        char ch = s[curr] - 'a';
        int temp = lastSeen[ch];
        if(lastSeen[ch] != -1) {
            parent[curr] = lastSeen[ch];
        } 
        lastSeen[ch] = curr;
        for(int next: adjList[curr]) {
            dfsAdjustParent(next, adjList, parent, s, lastSeen);
        } 
        lastSeen[ch] = temp;
    }
    int dfsCalcSize(int curr, vector<vector<int>> &adjList, vector<int> &subTreeSize) {
        int sum = 1;
        for(int next: adjList[curr]) {
            sum += dfsCalcSize(next, adjList, subTreeSize); 
        }
        return subTreeSize[curr] = sum;
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adjList(n);
        for(int i = 1; i < n; i++) {
            adjList[parent[i]].push_back(i);
        }
        vector<int> lastSeen(26, -1);
        dfsAdjustParent(0, adjList, parent, s, lastSeen);

        vector<vector<int>> newAdjList(n);
        for(int i = 1; i < n; i++) {
            newAdjList[parent[i]].push_back(i);
        }
        vector<int> ans(n);
        dfsCalcSize(0, newAdjList, ans);

        return ans;
    }
};