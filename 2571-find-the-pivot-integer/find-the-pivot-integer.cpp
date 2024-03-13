class Solution {
public:
    int pivotInteger(int n) {
        //Approach : two pointer
        // int i = 1;
        // int j = n;
        
        // int leftSum = 1;
        // int rightSum = n;

        // while ( i < j) {
        //     if (leftSum < rightSum ) {
        //         i++;
        //         leftSum += i;
        //     }
        //     else  {
        //         j--;
        //         rightSum += j;
        //     }
        // }

        // return leftSum == rightSum ? i : -1;


        //Approach : mathematic O(1)

        int totalSum = n * (n+1)/2;

        int pivot = sqrt(totalSum);

        return (pivot * pivot) == totalSum ? pivot : -1;
        
    }
};