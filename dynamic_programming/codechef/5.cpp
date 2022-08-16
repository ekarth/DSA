// Link: https://www.codechef.com/submit/ALTARAY

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    for(int i = 0; i < n; i++) cin >> arr[i];
	    
	    vector<int> dp(n, 1);
        
	    // if alternate signs then add 1 else remain 1
	    for(int i = n-2; i >= 0; i--)
	    {
	        if((arr[i] > 0 && arr[i+1] < 0) || (arr[i] < 0 && arr[i+1] > 0))
	        dp[i] = dp[i+1]+1;
	    }
	    
	    for(int i = 0; i < n; i++) cout << dp[i] << " ";
	    cout << endl;
	}
	return 0;
}
