// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         int a[9][9]={0},b[9][9]={0},c[9][9]={0};
//         for(int i=0;i<board.size();++i){
//             for(int j=0;j<board.size();++j){
//                 if(board[i][j]!='.'){
//                     int num=board[i][j]-'0'-1;
//                     int k= i / 3 * 3 + j / 3;
//                     if(a[i][num]||b[j][num]||c[k][num]){
//                         return false;
//                     }
//                         a[i][num]=b[j][num]=c[k][num]=1;
                    
//                 }

            
//             }

//         }
//         return true;

//     }
// };
class Solution {
public:
    bool checkRow(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            unordered_set<char> st; // Clear set for each row
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board){
        for(int j = 0; j < 9; j++){
            unordered_set<char> st; // Clear set for each column
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool checkGrid(vector<vector<char>>& board){
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                if(!solve(i, i+2, j, j+2, board)) return false;
            }
        }
        return true;
    }

    bool solve(int sr, int er, int sc, int ec, vector<vector<char>>& board){
        unordered_set<char> st;
        for(int i = sr; i <= er; i++){ 
            for(int j = sc; j <= ec; j++){ 
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool row = checkRow(board);
        bool col = checkCol(board);
        bool grid = checkGrid(board);
        return row && col && grid;
    }
};