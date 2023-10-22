class Solution {
public:
    int pivotIndex(vector<int>& a) {
         int sum=0,n=a.size();
         int rightsum=0;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
        for(int i=0;i<n;i++){
            sum -=a[i];
            if(sum==rightsum)
                return i;
            
             
             rightsum+=a[i];
        }
        return -1;
    }
};