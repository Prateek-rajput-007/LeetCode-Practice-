class Solution {
public:
    bool possible(vector<int>& time, int totalTrips, long long mid){
        long long t =0;

        for(int i=0;i<time.size();i++){
            t += mid/time[i];
        }

        return t >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
         int n = time.size();
        
        long long start = 1;
        int mini = INT_MAX;
         for(int i = 0; i < n; ++i) mini = min(mini , time[i]);
        long long end = 1LL * mini * totalTrips;

        while(start < end){
            long long mid = start + (end-start)/2;

            if(possible(time, totalTrips, mid)){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};