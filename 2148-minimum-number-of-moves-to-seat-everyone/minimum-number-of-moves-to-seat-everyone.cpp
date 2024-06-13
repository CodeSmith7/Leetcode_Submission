class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
       //Approach 1
        // int sum = 0;

        // sort (begin(seats),end(seats));
        // sort (begin(students),end(students));

        // for (int i = 0; i < seats.size();i++) {
        //     sum += abs(seats[i] -students[i]);
        // }

        // return sum;

        //Aproach 2 : counting sort 
        int n = seats.size();

        vector <int> position_seat(101,0);
        vector <int> position_student(101,0);

        for (int i = 0;i < n;i++) {
            position_seat[seats[i]]++;
        }
        for (int i = 0; i < n;i++) {
            position_student[students[i]]++;
        }
        int i = 0;
        int j = 0;
        int moves = 0;


        while ( n > 0) {
            if (position_seat[i] == 0) i++;
            if (position_student[j] == 0) j++;

            if (position_seat[i] != 0 && position_student[j] != 0) {
                moves += abs (i -j);
                n--;
                position_seat[i]--;
                position_student[j]--;
            } 
        }

        return moves;
    }
};