class Solution {
public:
    struct TrieNode{
        string word = "";
        unordered_map<char, TrieNode*> child;
    };
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            TrieNode* p = root;
            for(int j = 0; j < words[i].size(); j++){
                if(p->child.find(words[i][j])== p->child.end())
                    p->child[words[i][j]] = new TrieNode();
                p = p->child[words[i][j]];
            }
            p->word = words[i];
        }
        return root;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++)
                dfs(board, ans, i, j, root);
        }
        return ans;
    }

    void dfs(vector<vector<char>>& board, vector<string>& res, int i, int j, TrieNode* p){
        if(i < 0 || i >= board.size())      return;
        if(j < 0 || j >= board[0].size())   return;
        if(p == NULL) return;

        char c = board[i][j];
        if(c == '*' || p->child.find(c) == p->child.end()) return;

        p = p->child[c];
        if(p->word != ""){
            res.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '*';
        dfs(board, res, i+1, j, p);
        dfs(board, res, i-1, j, p);
        dfs(board, res, i, j+1, p);
        dfs(board, res, i, j-1, p);
        board[i][j] = c;
    }

};
