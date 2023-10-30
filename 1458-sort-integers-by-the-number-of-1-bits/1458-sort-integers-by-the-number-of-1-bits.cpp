class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        int n = 0,x;
        
        priority_queue<pair<int,int>> pq;
        for(auto &i: arr){
            n = 0;
            x = i;
            while(i){
                n += i&1;
                i = i >> 1;
            }
            pq.push({n,x});
        }
        n = arr.size();
        while(n--){
            arr[n] = pq.top().second;
            pq.pop();
        }
        return arr;
    }
};