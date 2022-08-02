// Link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

#include <iostream>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }

int main()
{
    int t, k;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        struct Node *root = NULL;
        Node *pre = NULL;
        Node *suc = NULL;
        while(n--)
        {
            char lr;
            int n1, n2;
            cin >> n1 >> n2;
            cin >> lr;

            if(root == NULL)
            {
                root = new Node(n1);
                switch(lr)
                {
                        case 'L': root->left=new Node(n2);
                        break;

                        case 'R': root->right=new Node(n2);
                        break;
                }
            }
            else
            {
                insert(root, n1, n2, lr);
            }
        
            cin >> key;
            findPreSuc(root, pre, suc, key);
            
            if (pre != NULL)
            cout << pre->key;
            else
            cout << "-1";

            if (suc != NULL) cout << " " << suc->key << endl;
            else cout << " " << "-1" << endl;
        }
    }
	return 0;
}

void find_predecessor(Node *root, Node* &pre, int key)
{
    while(root != NULL)
    {
        if(key > root->key)
        {
            pre = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}

void find_successor(Node *root, Node* &suc, int key)
{
    while(root != NULL)
    {
        if(root->key <= key)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    find_predecessor(root, pre, key);
    find_successor(root, suc, key);
}