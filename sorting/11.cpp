// Link: https://practice.geeksforgeeks.org/problems/tywins-war-strategy0527/1

#include <bits/stdc++.h>
using namespace std;

int min_soldiers(int arr[], int n, int k);

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        
        for(int i = 0; i < n; i++) cin >> arr[i];
            
        cout << min_soldiers(arr, n, k) << endl;
    }
	
	return 0;
}

int min_soldiers(int arr[], int n, int k)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] %= k;    
    }
    
    sort(arr, arr+n);

    int soldiers_trained = 0;
    int count = 0;
    int i = 0;
    // if remainder is 0: multiple of K
    for(; i < n; i++)
    {
        if(arr[i] == 0) count++;
        else break;
    }
    
    // if remainder say, n: then soldiers to train = k-n
    for(int j = n-1; j >= i; j--)
    {
        if(count >= (n+1)/2) break;
        else
        {
            soldiers_trained += (k-arr[j]);
            count++;
        }
    }
    return soldiers_trained;
}