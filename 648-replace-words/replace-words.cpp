//   Approoach 1 : using map 
// class Solution {
// public:
//     string findRoot(string& word, unordered_set<string>& st) {

//         //try all length substring starting from 0th index
//         for(int l = 1; l <= word.length(); l++) {
//             string root = word.substr(0, l);
//             if(st.count(root)) {
//                 return root;
//             }
//         }

//         return word;

//     }

//     string replaceWords(vector<string>& dictionary, string sentence) {
//         unordered_set<string> st(dictionary.begin(), dictionary.end());

//         stringstream ss(sentence);
//         string word;
//         string result;

//         while(getline(ss, word, ' ')) {
//             result += findRoot(word, st) + " ";
//         }

//         //result.pop_back();
//         return result.substr(0,result.size()-1);

//     }
// };


//Approach 2 : uaing Trie

class Solution {
public:
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }

            
    trieNode* root;

    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                crawler->children[index] = getNode();
            
            crawler = crawler->children[index]; 
        }
        
        crawler->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    string search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return word; 
            crawler = crawler->children[index];
            if(crawler->isEndOfWord) {
                return word.substr(0, i+1);
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        stringstream ss(sentence);
        string word;
        string result;
        root = getNode();
        for (string word : dictionary) {
            insert(word);
        }

        while(getline(ss, word, ' ')) {
            result += search(word) + " ";
        }

        result.pop_back();
        return result;
    }
};
