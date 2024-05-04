class Solution{
    public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char num=board[i][j];
                if(num!='.')
                {
                    string strNum=to_string(num);  

                    if(!seen.insert(strNum+"in row"+to_string(i)).second||
                        !seen.insert(strNum+"in col"+to_string(j)).second||
                        !seen.insert(strNum+"in box"+to_string(i/3)+"_"+to_string(j/3)).second)
                        return false;
                }
            }
        }
        return true;
        
    }
};