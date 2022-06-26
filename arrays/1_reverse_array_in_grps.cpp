#include<iostream>
#include<vector>
using namespace std;
void reverseInGroups(vector<long long>& arr, int n, int k){
    // code here
    vector <long long> answer(n);
    for(int i = 0; i < n; i++)
    {
        i--;
        for(int j = i+k; j >= 0; j--)
        {
            if(j > n-1) j = n-1; 
            i++;
            answer[i] = arr[j];
        }
    }
    for(int i = 0; i < n; i++) arr[i] = answer[i];
}
int main()
{
    vector<long long> arr = {5,6,8,9};
    for(auto i: arr) cout << i << " ";
}