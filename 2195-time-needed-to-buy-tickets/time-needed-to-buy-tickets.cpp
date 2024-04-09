class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       //Approach 1-> simulation of the data structure
        // int step = 0;
        // queue<int> q;

        // for (int i = 0;i < tickets.size();i++) {
        //     q.push(i);
        // }

        // while (tickets[k] != 0) {
        //     int ele =  q.front();
        //     q.pop();
        //     tickets[ele]--;
        //     if (tickets[ele] != 0) {
        //         q.push(ele);
        //     }
        //     step++;
        // }

        // return step;

        //One pass solution

        int time = 0;

        int n = tickets.size();

        for (int i = 0;i < n;i++) {
            if (i <= k) {
                time += min(tickets[i],tickets[k]);
            } else {
                time += min (tickets[k] -1, tickets[i] );
            }
        }
        return time;
    }
};