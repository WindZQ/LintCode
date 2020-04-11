#incldue <iostream>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        bool used[9];

        for(int i = 0; i < 9; ++i)
        {
            std::fill(used, used + 9, false);
            for(int j = 0; j < 9; ++j)
            {
                if(!check(board[i][j], used))
                {
                    return false;
                }
            }

            std::fill(used, used + 9, false);
            for(int j = 0; j < 9; ++j)
            {
                if(!check(board[j][i], used))
                {
                    return false;
                }
            }
        }

        for(int r = 0; r < 3; ++r)
        {
            for(int c = 0; c < 3; ++c)
            {
                std::fill(used, used + 9, false);
                for(int i = r * 3; i < r * 3 + 3; ++i)
                {
                    for(int j = c * 3; j < c * 3 + 3; ++j)
                    {
                        if(!check(board[i][j], used))
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool check(char ch, bool used[9])
    {
        if(ch == '.') return true;
        if(used[ch - '1']) return false;
        return used[ch - '1'] = true;
    }
#endif

#if method2
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        std::vector<std::vector<bool>> rowFlag(9, std::vector<bool>(9));
        std::vector<std::vector<bool>> colFlag(9, std::vector<bool>(9));
        std::vector<std::vector<bool>> cellFlag(9, std::vector<bool>(9));

        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.') continue;
                int c = board[i][j] - '1';
                if(rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c])
                    return false;

                rowFlag[i][c] = true;
                colFlag[c][j] = true;
                cellFlag[3 * (i / 3) + j / 3][c] = true;
            }
        }
        return true;
    }
#endif

#if method3
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        std::unordered_set<std::string> st;
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.') continue;
                std::string t = "(" + to_string(board[i][j]) + ")";
                std::string row = to_string(i) + t, col = t + to_string(j), cell = to_string(i / 3) + t + to_string(j / 3);
                if(st.count(row) || st.count(col) || st.count(cell)) return false;
                st.insert(row);
                st.insert(col);
                st.insert(cell);
            }
        }
        return true;
    }
#endif
};
