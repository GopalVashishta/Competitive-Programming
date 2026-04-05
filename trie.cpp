#include<bits/stdc++.h>
using namespace std;

struct Node{
   int child[26];
   bool isEnd = false;
   void init() {
       for (int i = 0; i < 26; i++) 
           child[i] = -1;
       isEnd = false;
   }
};

struct Trie {
    vector<Node> trie;
    void init() {
        Node t;
        t.init();
        trie.push_back(t);
    }

    void insert(string &s) {
        int v = 0;
        for (char c : s) {
            int i = c - 'a';
            if (trie[v].child[i] == -1) {  
                trie[v].child[i] = trie.size();  
                Node t; 
                t.init(); 
                trie.push_back(t);
            }
            v = trie[v].child[i];
        }
        trie[v].isEnd = true;
    }
    
    bool search(const string &s) {
        int v = 0; 
        for (char c : s) {
            int i = c - 'a'; 
            if (trie[v].child[i] == -1) { 
                return false;  
            }
            v = trie[v].child[i];  
        }
        return trie[v].isEnd;
    }

    // Optional: Search for a prefix in the trie
    bool startsWith(const string prefix) {
        int v = 0;  // Start at the root
        for (char c : prefix) {
            int i = c - 'a';  // Convert character to index (0-25)
            if (trie[v].child[i] == -1) {  // If the character path does not exist
                return false;  // Not found
            }
            v = trie[v].child[i];  // Move to the next node
        }
        return true;  // Prefix exists
    }

    bool deleteWord(string &s) {
        return deleteHelper(s, 0, 0);
    }

    // Helper function for delete
    bool deleteHelper(string &s, int v, int depth) {
        // Base case: if the word is not found, return false
        if (v == -1) return false;

        // If we've reached the end of the word
        if (depth == s.size()) {
            if (!trie[v].isEnd) return false;  // Word does not exist

            // Unmark the isEnd flag (the word is no longer present)
            trie[v].isEnd = false;

            // Check if the node has any children. If not, it's safe to delete
            if (isLeafNode(v)) {
                trie[v].init();  // Reset the node to its initial state
                return true;  // Node can be deleted
            }
            return false;  // Don't delete the node if it has children
        }

        // Continue recursively for the next character
        int i = s[depth] - 'a';
        bool childDeleted = deleteHelper(s, trie[v].child[i], depth + 1);

        // If the child node is deleted and the current node has no other children or is not an end node, delete the current node
        if (childDeleted) {
            trie[v].child[i] = -1;

            // If this node is not the end of another word and has no other children, it can be deleted
            if (!trie[v].isEnd && isLeafNode(v)) {
                trie[v].init();
                return true;
            }
        }

        return false;
    }

    // Check if the node is a leaf node (no children)
    bool isLeafNode(int v) {
        for (int i = 0; i < 26; i++) {
            if (trie[v].child[i] != -1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Trie t;
    t.init();  // Initialize the trie

    string words[] = {"hello", "world", "he", "hell", "dog"};
    
    // Insert words into the trie
    for (string &word : words) {
        t.insert(word);
    }

    // Search for words
    cout << t.search("hello") << endl;  // Should return 1 (true)
    cout << t.search("hell") << endl;   // Should return 1 (true)
    cout << t.search("world") << endl;  // Should return 1 (true)
    cout << t.search("dog") << endl;    // Should return 1 (true)
    cout << t.search("he") << endl;     // Should return 1 (true)
    cout << t.search("helloo") << endl; // Should return 0 (false)

    // Search for a prefix
    cout << t.startsWith("he") << endl; // Should return 1 (true)
    cout << t.startsWith("wo") << endl; // Should return 1 (true)
    cout << t.startsWith("dogg") << endl; // Should return 0 (false)

    return 0;
}
