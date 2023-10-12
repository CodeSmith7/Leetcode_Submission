//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void permute(string &s,int i,set<string> &ans) {
	        if (i == s.size()-1) {
	            ans.insert(s);
	            return;
	        }
	        for (int j = i;j <s.size();j++) {
	            swap(s[i],s[j]);
	            permute(s,i+1,ans);
	            swap(s[i],s[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    permute(S,0,ans);
		    vector<string> v;
		    for (auto x : ans){
		        v.push_back(x);
		    }
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends