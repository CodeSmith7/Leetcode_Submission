//Approach 1 : Brute force approach 
class Solution {
public:

    int frquencyOfString(vector<string>& arr,string &s) {
        int count = 0;
        for (string &st : arr) {
            if (st == s) {
                count++;
            }
            if (count > 1) {
                return count;
            }
        }
        return count;
    }
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        
        int count = 0;
        for(string &s : arr) {
            if(frquencyOfString(arr, s) == 1) {
                count++;
                if(count == k) {
                    return s;
                }
            }
        }

        return "";
    }
};



//Approach 2 : using hash map
// class Solution {
// public:
//     string kthDistinct(vector<string>& arr, int k) {

//         unordered_map<string, int> mp;

//         for (string &st: arr) {
//             mp[st]++;
//         }

//         for (auto &[a,b] : mp) {
            
//             cout << a << " -> " << b << endl;
//         }



//         for (string &s : arr) {
            
//             if (mp[s] ==1 ) {
//                 k--;
//             }

//             if (k == 0) {
//                 return s;
//             }
//         }
//         return "";
//     }
// };

