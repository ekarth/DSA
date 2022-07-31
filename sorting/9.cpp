// Link: https://practice.geeksforgeeks.org/problems/heap-sort/1

//since elements are to be sorted in increasing order, we will implement max heap
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    void heapify(int arr[], int n, int i)  
    {
        int largest = i;
        int l = 2*i+1, r = l+1;

        if(l < n && arr[i] < arr[l]) largest = l;
        if(r < n && arr[largest] < arr[r]) largest = r;

        if(largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void buildHeap(int arr[], int n)  
    {
        for(int i = n/2-1; i >= 0; i--) heapify(arr, n, i);    
    }

    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for(int i = n-1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[1000000],n,T,i;
    cin >> T;
    while(T--)
    {
        cin >> n;

        for(i=0;i<n;i++) cin >> arr[i];
        Solution ob;

        ob.heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}