// Link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// Approach: recursion 

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution
{
    public:
    int solver(Node *head)
    {
        if(head->next == NULL)
        {
            if(head->data == 9) 
            {
                head->data = 0;
                return 1;
            }
            head->data = head->data+1;
            return 0;
        }
        int carry = solver(head->next);
        
        if(head->data == 9 && carry == 1) 
        {
            head->data = 0;
            return 1;
        }
        
        head->data = head->data+carry;
        return 0;
    }
    Node* addOne(Node *head) 
    {
        int carry = solver(head);
        if(carry == 1)
        {
            Node *temp = new Node(1);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 