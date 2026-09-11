class WordDictionary {

    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;

        for(int i = 0; i < word.size(); i++) {
            int c = word[i] - 'a';
            if(!temp->children[c]) temp->children[c] = new Node();
            temp = temp->children[c];
        }

        temp->isEnd = true;
    }

    bool dfs(Node* root, string word, int i) {
        if(i == word.size()) return root->isEnd;
        if(word[i] == '.') {
            for(int j = 0; j < 26; j++) {
                if(root->children[j]) {
                    if(dfs(root->children[j], word, i + 1)) 
                        return true;
                }
            }

            return false;
        }

        int c = word[i] - 'a';
        if(!root->children[c]) return false;
        return dfs(root->children[c], word, i + 1);
    }
    
    bool search(string word) {
        Node* temp = root;
        return dfs(temp, word, 0);
    }
};