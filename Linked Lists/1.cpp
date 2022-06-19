// Rotate a linked list
// Problem Link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/?page=1&category[]=Linked%20List&sortBy=submissions
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* temp = head;
        int n = 1;
        while(temp->next != NULL)
        {
            n++;
            temp = temp->next;
        }
        // cout << n << endl;
        if (n == k) return head;
        // temp = head;
        temp->next = head;
        while(k > 0)
        {
            temp = temp->next;
            k--;
        }
        head = temp->next;
        temp->next = NULL;
        // cout << " " << temp->data;
        return head;
    }
};

int main() 
{ 
    int t;
    cin>>t; 
    while(t--) 
    { 
        int n, val, k; 
        cin>>n; 
        cin>> val; 
        Node *head = new Node(val); 
        Node *tail = head; 
        for(int i=0; i<n-1; i++) 
        { 
            cin>> val; 
            tail->next = new Node(val); 
            tail = tail->next; 
        } 
        cin>> k; 
        Solution ob; 
        head = ob.rotate(head, k); 
        printList(head); 
    } 
    return 0; 
} 
