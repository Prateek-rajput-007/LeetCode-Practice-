class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int count=0,row;
        vector<int> one;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++){
            row=0;
            count=0;
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    row=i;
                    count++;
                }
            }
            one.push_back(count);
        }
        int i1=0;
        for(int i=0;i<one.size();i++){
            q.push({one[i],i1});
            i1++;
        }
        vector<int>p;
        while(!q.empty() && k>0){
            int first = q.top().first;
            int second = q.top().second;
            p.push_back(second);
            q.pop();
            k--;
        }
        return p;
    }
};