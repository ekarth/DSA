// Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/

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

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    

    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> top_view_values; // result to return
        if(root == NULL) return top_view_values;
        
        int left = 0, right = 0; // left and right index values of the final array
        unordered_map<int, int> m; // O(1) time complexity for insertion and to check if current index is already filled or not
        queue<pair<Node*,int> > q; // to store nodes of tree level wise

        q.push({root, 0});
        // cout << left << right;
        while(!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node *currNode = temp.first;
            int num = temp.second;
            if(m.find(num) == m.end()) m[num] = currNode->data; // if no node at current index then insert node
            if(currNode->left) 
            {
                q.push({currNode->left, num-1});
                left = min(left, num-1);
            }
            if(currNode->right) 
            {
                q.push({currNode->right, num+1});
                right = max(right, num+1);
            }
        }
        
        top_view_values.reserve(right-left+1);

        for(int i = left; i <= right; i++)
        {
            top_view_values.push_back(m[i]);
        }
        return top_view_values;
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
        vector <int> res = ob.topView(root); 
        for (int i : res) cout << i << " "; 
        cout << endl; 
    } 
    return 0; 
}
