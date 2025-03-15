class Trie {
public:
    struct trieNode{
        bool isEnd;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* node = new trieNode();
        node->isEnd = 0;
        for(int i = 0; i<26; i++){
            node->children[i] = NULL;
        }
        return node;
    }
    trieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* it = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            int idx = ch-'a';
            if(it->children[idx] == NULL) it->children[idx] = getNode();
            it = it->children[idx];
        }
        it->isEnd = 1;
    }
    
    bool search(string word) {
        trieNode* it = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            int idx = ch-'a';
            if(it->children[idx] == NULL) return 0;
            it = it->children[idx];
        }
        if(it != NULL && it->isEnd == 1) return 1;
        return 0;
    }
    
    bool startsWith(string word) {
        trieNode* it = root;
        int i = 0;
        for(; i<word.size(); i++){
            char ch = word[i];
            int idx = ch-'a';
            if(it->children[idx] == NULL) return 0;
            it = it->children[idx];
        }
        if(i == word.size()) return 1;
        return 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */