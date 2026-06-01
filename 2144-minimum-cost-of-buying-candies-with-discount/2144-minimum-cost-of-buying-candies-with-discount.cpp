class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int total=0;
        sort(cost.begin(), cost.end(), greater<>());
        for(int i=0;i<n;i+=3){
            total+=cost[i];
            if(i+1<n){
                total+=cost[i+1];
            }
        }
        return total;
    }
};