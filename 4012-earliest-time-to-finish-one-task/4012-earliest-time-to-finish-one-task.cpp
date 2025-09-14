class Solution {
public:
    int earliestTime(vector<vector<int>>& task) {
        int n = task.size();
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<task[i].size();j++){
                sum = sum + task[i][j];
            }
            mini = min(mini, sum);
        }
        return mini;
    }
};