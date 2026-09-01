class Node {

    public:
    char letter;
    bool completes_word;
    Node* next[26] = {nullptr};

    Node(char c, bool b = false) :
        letter(c), completes_word(b) {};
};

class PrefixTree {
public:

    Node* root;
    PrefixTree() { root = new Node('0'); }
    
    int char_to_int(char c) {
        // char subtraction uses ascii interpretation
        // and lowercase letters have sequential ascii representation
        // 'a' starts the sequence, so this cleanly maps to 0-25
        return c - 'a';
    }

    void insert(string word) {
        
        Node* traveller = root;
        for (int pos = 0; pos < word.size(); pos++) {
            
            char c = word[pos];
            int idx = char_to_int(c);

            // creates a node if it doesn't exist already
            if (traveller->next[idx] == nullptr)
                traveller->next[idx] = new Node(c);
            
            traveller = traveller->next[idx];
        }

        traveller->completes_word = true;
    }
    
    bool search(string word) {
        
        Node* traveller = root;
        for (int pos = 0; pos < word.size(); pos++) {
            
            char c = word[pos];
            int idx = char_to_int(c);
            
            // checks if an expected letter is missing from the tree
            if (traveller->next[idx] == nullptr)
                return false;

            traveller = traveller->next[idx];
        }

        return traveller->completes_word;
    }
    
    bool startsWith(string prefix) {
        
        Node* traveller = root;
        for (int pos = 0; pos < prefix.size(); pos++) {
            
            char c = prefix[pos];
            int idx = char_to_int(c);

            // checks if we're indexing a substring
            if (traveller->next[idx] == nullptr)
                return false;

            traveller = traveller->next[idx];
        }

        return true;
    }
};
