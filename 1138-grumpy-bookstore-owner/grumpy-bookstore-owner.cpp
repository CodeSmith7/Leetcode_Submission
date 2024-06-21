class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int maxUnsatisfyCust = 0;
        int currentUnsat = 0;

        for (int i = 0; i < minutes; i++) {

            currentUnsat += customers[i] * grumpy[i]; 

        }
        maxUnsatisfyCust = currentUnsat;

        int i = 0;
        int j = minutes;

        while (j < n) {
            currentUnsat += customers[j] * grumpy[j];//adding new element in the window 
            currentUnsat -= customers[i] * grumpy[i];//removing first element of the window 
           
            maxUnsatisfyCust = max(maxUnsatisfyCust,currentUnsat);

            j++;
            i++; 
        }
        int totalSatisfy = maxUnsatisfyCust;
        for (int i = 0; i < n;i++ ) {
            if (grumpy[i] == 0) {
                totalSatisfy += customers[i];
            }
        }
        return totalSatisfy;
    }
};