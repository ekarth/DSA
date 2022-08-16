// Link: https://www.codechef.com/submit/ANUWTA 

// Bottom up approach;
// Time Complexity: O(N); N-> 10^5
// Subproblem: Distance to turn off i lights 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N = 100000+1;
	long long dist[N];
	
	dist[0] = 0;
	
	for(int i = 1; i < N; i++) dist[i] = dist[i-1]+i+1;
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    
	    cout << dist[n] << endl;
	    
	}
	return 0;
}
