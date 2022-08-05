// Link: https://practice.geeksforgeeks.org/problems/construct-bst-from-post-order/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL) return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

int main ()
{   
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int post[n];

        for(int i=0;i<n;i++) cin >> post[i];

        Node* root = constructTree(post, n);

        printInorder(root);
        cout << "\n";
    }
	return 0;
}

Node* constructor(int mini, int maxi, int start, int end, int post[])
{
    if(start > end) return NULL;
    Node *temp = NULL;
    if(mini < post[end] && post[end] < maxi)
    {
        temp = new Node(post[end]);
        
        int i = end-1;
        for(; i >= start; i--) if(post[i] < post[end]) break;

        temp->left = constructor(mini, temp->data, start, i, post);
        temp->right = constructor(temp->data, maxi, i+1, end-1, post);
    }

    return temp;
}
Node *constructTree (int post[], int size)
{
    Node *root = new Node(post[size-1]);

    int i = size-1;
    for(; i >= 0; i--) if(post[i] < root->data) break;

    root->right = constructor(root->data, INT_MAX, i+1, size-2, post);
    root->left = constructor(INT_MIN, root->data, 0, i, post);
    
    return root;
}