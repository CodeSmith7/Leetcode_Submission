class Solution {
public:
    string reversePrefix(string word, char ch) {
      // APPROACH 1: using brute force

        // int idx = -1;
        // // int j = 0;
      
        // // while (j < word.size()) {
        // //     if (word[j] == ch) {
        // //         idx = j;
        // //         break;
        // //     } 
        // //     j++;
            
        // // }

        // idx = word.find(ch);
        // if (idx == string::npos ) {
        //     return word;
        // }

        // int i = 0;
        // while (i < idx) {
        //     swap(word[i++],word[idx--]);
        // }

        // return word;

        //Approach 2 : using the library function only 

        //reverse(iterator,iterator); reverse[iterator1, iterator2)

        int j = word.find(ch);

        reverse(word.begin(), word.begin() + j + 1);

        return word;

    }
};