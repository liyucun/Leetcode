
class Solution
{
public:
    struct TrieNode
    {
        string nWord = "";
        unordered_map<char, TrieNode *> m;
    };
    TrieNode *root = new TrieNode();
    int delta[5] = {0, 1, 0, -1, 0};

    void buildTrie(vector<string> &words)
    {

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
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> result;

        if (board.size() < 1 || board[0].size() < 1 || words.size() < 1)
            return result;

        buildTrie(words);

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
        for (int i = 0; i < 4; i++)
        {
            int nr = row + delta[i];
            int nc = col + delta[i + 1];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '*')
            {
                dfs(board, nr, nc, result, p);
            }
        }
        board[row][col] = c;
    }
};