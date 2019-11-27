class Solution
{
public:
    struct TrieNode
    {
        string nWord = "";
        unordered_map<char, TrieNode *> m;
    };

    TrieNode *buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();

        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *p = root;

            for (int j = 0; j < words[i].length(); j++)
            {
                char c = words[i][j];
                if (p->m.count(c) == 0)
                {
                    p->m[c] = new TrieNode();
                }
                p = p->m[c];
            }
            p->nWord = words[i];
        }
        return root;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> result;

        if (board.size() < 1 || board[0].size() < 1 || words.size() < 1)
            return result;

        TrieNode *root = buildTrie(words);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, result, root);
            }
        }

        return result;
    }

    void dfs(vector<vector<char>> &board, int row, int col, vector<string> &result, TrieNode *p)
    {
        char c = board[row][col];

        if (p->m.count(c) == 0)
            return;

        p = p->m[c];
        if (p->nWord.length() > 0)
        {
            result.push_back(p->nWord);
            p->nWord = "";
        }

        board[row][col] = '*';

        if (row - 1 >= 0 && board[row - 1][col] != '*')
            dfs(board, row - 1, col, result, p);
        if (row + 1 < board.size() && board[row + 1][col] != '*')
            dfs(board, row + 1, col, result, p);
        if (col - 1 >= 0 && board[row][col - 1] != '*')
            dfs(board, row, col - 1, result, p);
        if (col + 1 < board[0].size() && board[row][col + 1] != '*')
            dfs(board, row, col + 1, result, p);

        board[row][col] = c;
    }
};