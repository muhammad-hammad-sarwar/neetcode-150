class Solution {

    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }

            isEnd = false;
        }
    };

    Node* root;
    vector<vector<bool>> vis;
    vector<string> ans;
    int rows, cols;
    vector<vector<int>> dir;
    unordered_set<string> res;

    void addWords(Node* root, vector<string>& words) {
        for(string w: words) {
            Node* temp = root;
            for(char c: w) {
                if(!temp->children[c - 'a']) {
                    temp->children[c - 'a'] = new Node();
                }

                temp = temp->children[c - 'a'];
            }

            temp->isEnd = true;
        }
    }

    void dfs(vector<vector<char>>& board, Node* root, int r, int c, string word) {
        if(r < 0 || c < 0 || r == rows || c == cols) return;
        if(vis[r][c]) return;
        if(!root->children[board[r][c] - 'a']) return;
        vis[r][c] = true;

        word.push_back(board[r][c]);
        if(root->children[board[r][c] - 'a']->isEnd) res.insert(word);

        for(auto& d: dir) {
            dfs(
                board, root->children[board[r][c] - 'a'],
                r + d[0], c + d[1], word
            );
        }

        vis[r][c] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        addWords(root, words);
        rows = board.size(), cols = board[0].size();
        vis = vector<vector<bool>>(rows, vector<bool>(cols, false));
        dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                char c = board[i][j];
                if(root->children[c - 'a']!=nullptr) {
                    dfs(board, root, i, j, "");
                }
            }
        }
        
        return vector<string>(res.begin(), res.end());
    }
};