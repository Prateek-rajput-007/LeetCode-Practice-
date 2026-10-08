class Solution {
public:
    string removeOuterParentheses(string s) {
        string output="";int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
                if(count>=2){
                    output.push_back('(');
                }
            }
            else if(s[i]==')'){
                count--;
                if(count>=1){
                    output.push_back(')');
                }
            }
        }
            return output;
    }
};