class Solution {
public:
    string reversePrefix(string word, char ch) {
      
        int idx = -1;
        // int j = 0;
      
        // while (j < word.size()) {
        //     if (word[j] == ch) {
        //         idx = j;
        //         break;
        //     } 
        //     j++;
            
        // }
        idx = word.find(ch);
        if (idx == string::npos ) {
            return word;
        }

        int i = 0;
        while (i < idx) {
            swap(word[i++],word[idx--]);
        }

        return word;

    }
};