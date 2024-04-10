class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      //Approach 1 : simulation
        // int n = deck.size();
        // vector <int> result (n,0);

        // bool skip = false;

        // int i = 0;//deck
        // int j = 0;//result

        // sort(begin(deck),end(deck));

        // while (i < n) {

        //     if (result[j] == 0) {//empt hai

        //         if (skip == false) {
        //             result[j] = deck[i];
        //             i++;
        //         }
        //         skip = !skip;//alternate
        //     }

        //     j = (j+1)%n;
        // }
        // return result;

        //Approach 2 : using proper simulation use queue

        int n = deck.size();

        queue<int> que;
        vector <int> result(n);
       

        for (int i = 0; i < n;i++) {
            que.push(i);
        }
        
        sort(begin(deck),end(deck));
        int i = 0;

        while ( i < n) {
            int idx = que.front();
            que.pop();
            result[idx] = deck[i];

            if(!que.empty()) {
                que.push(que.front());
                que.pop();
            }
            i++;
            
        }
        return result;
    }
};