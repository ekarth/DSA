// Link: https://www.codechef.com/submit/PLAYFIT

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
	    
	    int goals[n];
	    for(int i = 0; i < n; i++) cin >> goals[i];
	    
	    int mini = goals[0];
	    int diff = 0;
	    
	    for(int i = 1; i < n; i++)
	    {
	        if(goals[i] > mini)
	        {
	            diff = max(diff, goals[i]-mini);
	        }
	        else mini = goals[i];
	    }
	    
	    if(diff == 0) cout << "UNFIT" << endl;
	    else cout << diff << endl;
	}
	return 0;
}