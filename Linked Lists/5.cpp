// Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head;
    Node* slow = head;
    
    while(fast != slow)
    {
        if(!fast || !fast->next ) return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

class Solution
{
    public:
    
    // Floyd's method to detect cycle (returns NULL if no cycle else returns address to a node in cycle)
    Node* isCyclic(Node* head)
    {
        if(!head) return NULL;
        
        Node* fast = head;
        Node* slow = head;
        
        while(fast && slow && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) return slow;
        }
        
        return NULL;
    }
    
    void removeLoop(Node* head)
    {
        Node *ptr1 = isCyclic(head);

        if(ptr1 == NULL) return;
        
        Node *ptr2 = ptr1;

        int k = 1;

        // find number of nodes in the loop
        while(ptr1->next != ptr2)
        {
            k++;
            ptr1= ptr1->next;
        }

        // point both pointers to head
        ptr1 = head;
        ptr2 = head;

        // point second pointer to "k" nodes from head
        while(k--) ptr2 = ptr2->next;
            
        // loop to find the starting node of the cycle
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // loop to find last node of the cycle 
        while(ptr2->next != ptr1)
        {
            ptr2 = ptr2->next;
        }

        // change the next of last node of loop to NULL to remove the loop
        ptr2->next = NULL;       
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

