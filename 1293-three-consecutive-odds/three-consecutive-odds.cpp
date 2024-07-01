//Approach 1: using sinple for loop chekcing each element 
// class Solution {
// public:
//     bool threeConsecutiveOdds(vector<int>& arr) {

//         int n  = arr.size();
        
//         for (int i = 0; i < n-2;i++) {
//             if (arr[i] &1 && arr[i+1] & 1 && arr[i+2] & 1) {
//                 return true;
//             }
//         }

//         return false;;
        
//     }
// };


//Approach 2 : using counter to track of consequtive odd number 

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int n  = arr.size();
        
        int count = 0;
        for (int i = 0;i < n;i++) {

            if (arr[i] & 1) {
                count++;  //count it 
            } else {
                count = 0; //Reset it
            }

            if (count == 3) {
                return true;
            }

        }

        return false;
        
    }
};

