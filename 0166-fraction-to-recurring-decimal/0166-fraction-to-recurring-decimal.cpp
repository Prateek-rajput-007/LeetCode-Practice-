class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0){
            return "0";
        }
        string ans;
        if((numerator<0) ^ (denominator<0)){
            ans.push_back('-');
        }
        long long n=llabs((long long)numerator);
        long long d=llabs((long long)denominator);
        long long intpart=n/d;
        long long rem=n%d;
        ans+=to_string(intpart);
        if(rem==0){
            return ans;
        }
        ans.push_back('.');
        map<long long,int>mp;
        while(rem!=0){
            if(mp.count(rem)){
                int i=mp[rem];
                ans.insert(i,1,'(');
                ans.push_back(')');
                break;
            }
            mp[rem]=ans.size();
            rem*=10;
            ans+=to_string(rem/d);
            rem%=d;
        }
        return ans;
    }
};