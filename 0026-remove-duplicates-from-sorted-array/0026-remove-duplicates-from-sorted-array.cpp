class Solution {
public:
    int removeDuplicates(vector<int>& a) {
      /*  int n=arr.size();
        int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;*/
    int n=a.size();
       unordered_map<int,int> mp;
        int c=0;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            if(mp[a[i]]==1){
                a[c++]=a[i];
            }
            
        }
        return c;
    }
};