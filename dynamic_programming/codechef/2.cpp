// Link: https://www.codechef.com/LP2TO306/problems/KPRIME

#include<bits/stdc++.h>
#define MAX 100000
#define k 5
using namespace std;
// T -> 10^4
// N -> 10^5
// k -> 6
// T*N not possible as it exceedds 10^8,
// So creating a global primeCount vector and numFactors which has count of all previous numbers with 'k' unique prime numbers (inclusive)
vector<int> primeCount(MAX+1, 0);
vector<vector<int>> countPrime(k+1, vector<int>(MAX+1, 0));
void countKPrimes() // O(NlogN) seive method
{
    for(int i = 2; i <= MAX; i+=2) primeCount[i]++;
    for(int i = 3; i <= MAX; i++)
    {
        if (primeCount[i] == 0)
        {
            for(int j = i; j <= MAX; j+=i) primeCount[j]++;
        }
    }

    // O(N)
    // for every number between 2 and MAX (both inclusive) assigning 1 to number corrsponding to its k prime factors
    for(int i = 2; i <= MAX; i++) if(primeCount[i] <= 5) countPrime[primeCount[i]][i] = 1;

    // O(kN)
    // for every j in k, for every i in N: count number of elements with j prime factors including it.
    for(int j = 1; j <= k; j++)
    {
        for(int i = 2; i <= MAX; i++)
        {
            countPrime[j][i] += countPrime[j][i-1]; // prefix sum technique
        }
    }  
}
int main()
{
    int test;
    cin >> test;
    countKPrimes();
    while(test--)
    {
        int a, b, K;
        cin >> a >> b >> K;
        cout << countPrime[K][b] - countPrime[K][a-1] << endl;
    }
    return 0;
}