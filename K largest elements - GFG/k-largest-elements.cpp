//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        // vector<int> ans;
        // priority_queue <int, vector<int>, greater<int>> pq;

        // for (int i = 0;i< n;i++) {
        //     if (pq.size() < k) {
        //         pq.push(arr[i]);
        //     }
        //     if (arr[i] > pq.top()) {
        //         pq.pop();
        //         pq.push(arr[i]);
        //     }
        // }
        // while (!pq.empty()) {
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
          for(int i = 0; i < n; i++) {
            minHeap.push(arr[i]);
            if(minHeap.size() > k) {
               minHeap.pop();
             }
         }
           vector<int> result(minHeap.size());
           for(int i = minHeap.size() - 1; i >= 0; i--) {
                result[i] = minHeap.top();
                minHeap.pop();
            }
           return result;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends