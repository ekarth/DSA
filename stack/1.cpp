// Link: https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()) return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()) return -1;
           int ans;
           
           if(s.top() > 0)
           {
               ans = s.top();
               s.pop();
           }
           else
           {
               ans = minEle;
               minEle = minEle - s.top();
               s.pop();
           }
           return ans;
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty())
           {
               s.push(x);
               minEle = x;
               return;
           }
           if(minEle <= x)
           {
               s.push(x);
           }
           else
           {
               s.push(x-minEle);
               minEle = x;
           }
           //Write your code here
       }
};

int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        int q;
        cin >> q;
        Solution ob;
        while(q--)
        {
            int qt;
            cin >> qt;
            if(qt == 1)
            {
                //push
                int att;
                cin >> att;
                ob.push(att);
            }
            else if(qt == 2)
            {
                //pop
                cout << ob.pop() << ' ';
            }
            else if(qt == 3)
            {
                //get minimum element
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
