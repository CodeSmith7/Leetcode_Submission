class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int sum = 0;

        sort (begin(seats),end(seats));
        sort (begin(students),end(students));

        for (int i = 0; i < seats.size();i++) {
            sum += abs(seats[i] -students[i]);
        }

        return sum;
    }
};