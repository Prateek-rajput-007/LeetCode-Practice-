class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int c=0;

        while(ss >> word){
            bool canType = true;
            for(char ch: word){
                if(brokenLetters.find(ch) != string::npos){
                    canType = false;
                    break;
                }
            }
            if(canType){
                c++;
            }
        }
        return c;
    }
};

// class Solution {
// public:
//     int solve(string s, string brokenLetters) {
//         unordered_set<char> st(s.begin(), s.end());
//         for (char ch : brokenLetters) {
//             if (st.find(ch) != st.end())
//                 return 0;
//         }

//         return 1;
//     }

//     int canBeTypedWords(string text, string brokenLetters) {
//         int n = text.length();
//         int i = 0, j = 0;

//         int count = 0;
//         while (i <= n) {
//             if (i == n || text[i] == ' ') {
//                 string s = text.substr(j, i - j);
//                 count += solve(s, brokenLetters);
//                 j = i + 1;
//             }

//             i++;
//         }

//         return count;
//     }
// };