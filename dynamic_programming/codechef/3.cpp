// Link: https://www.codechef.com/submit/NAME2 

// Code: length of man's name is always less than or equal to length of woman's name 
// Time Complexity: O(T*N) 
// T -> number of test cases; N-> max(length(man's name), length(woman's name))


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--)
	{
	    string man, woman;
	    cin >> man >> woman;
	    
	    if(man.length() > woman.length())
	    {
	        swap(man, woman);
	    }
	    int i = man.length(), j = woman.length();
	    int match = 0;
	    
	    for(int k = 0; k < j; k++)
	    {
	        if(match < i && man[match] == woman[k])
	        {
	            match++;
	        }
	    }
	    if(match == i) 
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
	}
	return 0;
}
