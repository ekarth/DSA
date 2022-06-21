// Problem Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/
// Merge Sort is used: Will count inversions while merging

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long count = 0;
    void Merge(long long arr[], long long l, long long mid, long long r)
    {
        long long  n = mid-l+1, m = r-mid;
        long long temp[n+m];
        long long i = l, j = mid+1, k = 0;

        while(i <= mid && j <= r)
        {
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else if(arr[i] > arr[j])
            {
                temp[k++] = arr[j++];
                count+= (mid+1-i);
            }
        }
        while(i <= mid) temp[k++] = arr[i++];
        while(j <= r) temp[k++] = arr[j++];
        i = r;
        while(k) arr[i--] = temp[--k];
        // cout << l << " " << r << " " << count << endl;
    }
    long long MergeSort(long long arr[], long long l, long long r)
    {
        if(l < r)
        {
            long long mid = l + (r-l)/2;
            MergeSort(arr, l, mid);
            MergeSort(arr, mid+1, r);
            Merge(arr, l, mid, r);

        }
        return count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return MergeSort(arr, 0, N-1);
    }
};

int main() 
{ 
    long long T; 
    cin >> T; 
    while(T--)
    { 
        long long N; 
        cin >> N; 
        long long A[N]; 
        for(long long i = 0; i<N; i++) cin >> A[i]; 
        Solution obj; 
        cout << obj.inversionCount(A,N) << endl; 
    } 
    return 0; 
} 