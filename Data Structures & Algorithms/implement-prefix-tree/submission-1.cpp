class PrefixTree {
    struct Node {
        Node* children[26];
        bool isEnd;
    };

    Node* root;
public:

    PrefixTree() {
        root = new Node();
        for(int i = 0; i < 26; i++) {
            root->children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i = 0; i < word.size(); i++) {
            int c = word[i] - 'a';
            if(!temp->children[c]) temp->children[c] = new Node();
            if(i == word.size() - 1) temp->isEnd = true;
            temp = temp->children[c];
        }
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i = 0; i < word.size(); i++) {
            int c = word[i] - 'a';
            if(!temp->children[c]) return false;
            if(i == word.size() - 1 && !temp->isEnd) return false;

            temp = temp->children[c];
        }

        return true;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i = 0; i < prefix.size(); i++) {
            int c = prefix[i] - 'a';
            if(!temp->children[c]) return false;

            temp = temp->children[c];
        }

        return true;
    }
};
