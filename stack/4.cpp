// Link: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    bool ispar(string x)
    {
        stack<char> s;
        for(auto ch: x)
        {
            switch(ch)
            {
                case '{':
                    s.push(ch);
                    break;

                case '[':
                    s.push(ch);
                    break;

                case '(':
                    s.push(ch);
                    break;
                case ')':
                    if(!s.empty() && s.top() == '(') s.pop();
                    else return false;
                    break;

                case '}':
                    if(!s.empty() && s.top() == '{') s.pop();
                    else return false;
                    break;

                default:
                    if(!s.empty() && s.top() == '[') s.pop();
                    else return false;
                    break;
            }
        }
        return s.empty();
    }

};


int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}