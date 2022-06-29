// Link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    Node(int x) 
    {
        data = x;
        next = NULL;
    }
};

Node *inputList(int size)
{
    if(size == 0) return 0;

    int val;
    cin >> val;
    
    Node *head = new Node(val);
    Node *tail = head;

    for(int i = 0; i < size-1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n = 0, m = 0;
    
    Node *temp = head1;
    while(temp != NULL) 
    {
        temp = temp->next;
        n++;
    }
    
    temp = head2;
    while(temp != NULL)
    {
        temp = temp->next;
        m++;
    }
    
    if(n > m)
    {
        while(n != m)
        {
            head1 = head1->next;
            n--;
        }
    }
    else
    {
        while(m != n)
        {
            head2 = head2->next;
            m--;
        }
    }
    
    while(n)
    {
        if(head1 == head2) return head1->data;
        n--;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

int main()
{
    int T,n1,n2,n3; 
    cin >> T; 
    while(T--) 
    { 
        cin >> n1 >> n2 >> n3; 
        Node* head1 = inputList(n1); 
        Node* head2 = inputList(n2); 
        Node* common = inputList(n3); 
        Node* temp = head1;

        while(temp != NULL && temp->next != NULL) 
            temp = temp->next; 

        if(temp!=NULL) temp->next = common; 

        temp = head2; 

        while(temp != NULL && temp->next != NULL) 
            temp = temp->next; 

        if(temp!=NULL) temp->next = common;
  
        cout << intersectPoint(head1, head2) << endl; 
    } 
    return 0;
}