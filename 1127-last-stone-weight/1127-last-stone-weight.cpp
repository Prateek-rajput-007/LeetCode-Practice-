class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        int n = stones.size();

        for(int i=0;i<n;i++){
            q.push(stones[i]);
        }

        while(q.size()>1){
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if(y != x){
                q.push(y-x);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};