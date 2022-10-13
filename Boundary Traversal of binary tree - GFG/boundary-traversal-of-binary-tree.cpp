//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

     vector<int>leaf;
    void helper(Node*root){
        if(root==NULL)return;
        if(!root->left &&!root->right){
            leaf.push_back(root->data);
            return;
        }
        helper(root->left);
        helper(root->right);
    }
    
    vector<int>boundary(Node *root)
    {
        //Your code here
        if(root==NULL)return {};
        vector<int>res;
        Node*t=root;
         res.push_back(t->data);
         t=t->left;
         Node*prev=root;
        while(t){
            res.push_back(t->data);
            prev=t;
            if(t->left){
                t=t->left;
            }
            else{
                t=t->right;
            }
        }
        helper(root);
        if(!prev->left &&!prev->right){
            res.pop_back();
        }
        for(int i=0;i<leaf.size();i++){
            res.push_back(leaf[i]);
        }
        // return res;
        vector<int>rit;
        Node*r=root->right;
        while(r){
            rit.push_back(r->data);
            if(r->right){
                r=r->right;
            }
            else r=r->left;
            
        }
        reverse(rit.begin(),rit.end());
        for(int i=1;i<rit.size();i++){
            res.push_back(rit[i]);
        }
        return res;
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends