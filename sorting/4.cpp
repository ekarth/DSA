// Link: https://practice.geeksforgeeks.org/problems/insertion-sort/1

#include <stdio.h>
#include <math.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) arr[j+1] = arr[j--];
        arr[j+1] = key;
            
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i = 1; i < n; i++)
        {
            insert(arr, i);
        }
    }
};

int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
