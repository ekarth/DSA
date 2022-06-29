// Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        int count = 0;
        Node *temp = head;

        // counting number of nodes
        while(temp != NULL) // O(n)
        {
            count++;
            temp = temp->next;
        }

        // if single node is present, then it is a palindrome
        if(count == 1) return true;

        temp = head;
        int i = 0;

        // Moving t middle of list
        for(; i < count/2; i++) // O(n)
        {
            temp = temp->next;
        }

        // if odd number of nodes, then move 1 node to go to start of other part
        if(count % 2 != 0) 
        {
            temp = temp->next;
            i++;
        }

        // reference of staring of second part
        Node *ptr = temp;

        // moving to last node
        while(temp->next != NULL) temp = temp->next;

        // Adding the starting node to next of original list next node
        while(i++ < count)
        {
            Node *last = temp->next; // storing address of last node
            temp->next = ptr; // creating pointer from original list last node to first node of second part
            ptr = ptr->next; // moving starting pointer to next node
            temp->next->next = last; // adding last node address to next of added node
        }

        // checking if palindrome as now both list are in same order
        while(temp != NULL)
        {
            if(temp->data != head->data) return false;
            temp = temp->next;
            head = head->next;
        }
        return true;
    }
};

int main()
{
    int T,i,n,l,firstdata; 
    cin >> T; 
    while(T--) 
    { 
        struct Node *head = NULL, *tail = NULL; 
        cin >> n; 
        cin >> firstdata; 
        head = new Node(firstdata); 
        tail = head; 
        for(i=1;i<n;i++) { 
            cin >> l; 
            tail->next = new Node(l); 
            tail = tail->next; 
        } 
        Solution obj; 
        cout << obj.isPalindrome(head) << endl; 
    }

    return 0;
}