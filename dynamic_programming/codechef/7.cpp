// Link: https://www.codechef.com/submit/SUBINC

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    
	    vector<> dp(n, 1);
	    long long num_subarrays = 0;
	    
	    for(int i = 0; i < n; ++i) 
	    {
	        cin >> arr[i];
	        
	        if(i > 0 && arr[i] >= arr[i-1]) dp[i] += dp[i-1];
	        
	        num_subarrays += dp[i];
	    }
	    cout << num_subarrays << endl;
	}
	return 0;
}
