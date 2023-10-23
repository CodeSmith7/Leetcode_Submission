//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
bool cmp(string a,string b) {
	    if (a+b > b+a) 
	      return true;
	     
	    return false;
	}
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	string printLargest(vector<string> &arr) {
	    // code here
	    string ans;
	    
	    sort(arr.begin(),arr.end(),cmp);
	    
	    for (auto x : arr) {
	        ans += x;
	    }
	    int idx = 0;
	    while (ans[idx] == '0' && idx < ans.size() -1 ){
	        idx++;
	    }
	    return ans.substr(idx);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends