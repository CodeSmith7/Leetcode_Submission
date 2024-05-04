class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort (begin(people),end(people));

        int n = people.size();
        int i = 0;
        int j = n-1;
        int boat = 0;
        while ( i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
            boat += 1;
        }

        return boat;
    }
};