// Link: https://practice.geeksforgeeks.org/problems/peak-element/1

// Approach: Bianry Search 

#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // side cases
       if(n == 1) return 0;
       if(arr[0] >= arr[1]) return 0;
       if(arr[n-1] >= arr[n-2]) return n-1;
       
       int ind;
       int l = 1, r = n-2;
       while(l <= r)
       {
           int m = l + (r-l)/2;
           
           if(arr[m] >= arr[m-1] && arr[m] >= arr[m+1]) 
           {
               ind = m;
               break;
           }
           else if(arr[m-1] >= arr[m]) r = m-1;
           else if(arr[m] <= arr[m+1]) l = m+1;
           
       }
       
       return ind;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}