class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int step = 0;
        queue<int> q;

        for (int i = 0;i < tickets.size();i++) {
            q.push(i);
        }

        while (tickets[k] != 0) {
            int ele =  q.front();
            q.pop();
            tickets[ele]--;
            if (tickets[ele] != 0) {
                q.push(ele);
            }
            step++;
        }

        return step;
    }
};