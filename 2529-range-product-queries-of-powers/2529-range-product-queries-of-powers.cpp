class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> powers;
        int mul=1;
        while(n>0){
            if(n%2){
                powers.push_back(mul);
            }
            mul = mul*2;
            n= n/2;
        }
        for(auto it: queries){
            int start = it[0];
            int end = it[1];
            long long pro = 1;

            for(int i=start;i<=end;i++){
                pro=(pro*powers[i])%mod;
            }
            ans.push_back(pro);
        }
    
    return ans;
    }
};