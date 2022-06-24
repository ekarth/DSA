// Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
Node* newNode(int val) 
{
    Node* temp = new Node; 
    temp->data = val; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
}

// Function to Build Tree 
Node* buildTree(string str) { 
    // Corner Case 
    if(str.length() == 0 || str[0] == 'N') return NULL; 
    // Creating vector of strings from input 
    // string after spliting by space 
    vector<string> ip; 
    istringstream iss(str); 
    for(string str; iss >> str;) 
        ip.push_back(str); 

    // Create the root of the tree 
    Node* root = newNode(stoi(ip[0])); 
    // Push the root to the queue 

    queue<Node*> queue; 
    queue.push(root); 

    // Starting from the second element 
    int i = 1; 
    while(!queue.empty() && i < ip.size()) 
    { 
        // Get and remove the front of the queue 
        Node* currNode = queue.front(); 
        queue.pop(); 
        // Get the current node's value from the string 
        string currVal = ip[1]; 
        // If the left child is not null 
        if(currVal != "N") 
        { 
            // Create the left child for the current node 
            currNode->left = newNode(stoi(currVal)); 
            // Push it to the queue. 
            queue.push(currNode->left); 
        }

        // For the right child 
        i++; 
        if(i >= ip.size()) 
            break; 
        currVal = ip[i]; 

        // If the right child is not null 
        if(currVal != "N") 
        { 
        
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal)); 

            // Push it to the queue 
            queue.push(currNode->right); 
        }
        i++;
    }
    return root;
}

class Solution {
public:
    vector<int> boundary_values;
    unordered_set<Node*> s;
    void left_boundary(Node *root)
    {
        if(root == NULL) return;
        boundary_values.push_back(root->data);
        s.insert(root);
        if(root->left) left_boundary(root->left);
        else left_boundary(root->right);
    }
    void leaf_nodes(Node *root)
    {
        if(root == NULL) return;
        if((root->left == NULL && root->right == NULL) && (s.find(root) == s.end()))
        {
            boundary_values.push_back(root->data);
            s.insert(root);
            return;
        }
        leaf_nodes(root->left);
        leaf_nodes(root->right);
    }
    void right_boundary(Node *root)
    {
        if(root == NULL) return;
        if(root->right) right_boundary(root->right);
        else right_boundary(root->left);
        if(s.find(root) == s.end())
        {
            boundary_values.push_back(root->data);
            s.insert(root);
        }
        
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        if(root == NULL) return boundary_values;
        boundary_values.push_back(root->data);
        s.insert(root);
        left_boundary(root->left);
        leaf_nodes(root);
        right_boundary(root->right);
        // vector<int> values;
        // values.push_back(boundary_values[0]);
        // for(int i = 1; i < boundary_values.size()-1; i++)
        // {
        //     if(boundary_values[i] == boundary_values[i-1]) continue;
        //     values.push_back(boundary_values[i]);
        // }
        return boundary_values;
    }
};

int main() 
{ 
    int t; 
    string tc; 
    getline(cin, tc); 
    t=stoi(tc); 
    while(t--) 
    { 
        string s, ch; 
        getline(cin, s); 
        Node* root = buildTree(s); 
        Solution ob; 
        vector <int> res = ob.boundary(root); 
        for (int i : res) cout << i << " "; 
        cout << endl; 
    } 
    return 0; 
}
