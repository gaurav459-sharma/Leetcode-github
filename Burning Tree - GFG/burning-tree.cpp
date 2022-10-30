//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node*findnode(Node*root,int target,unordered_map<Node*,Node*>&mp){
      queue<Node*>pq;
      pq.push(root);
      Node*res;
      while(!pq.empty()){
          Node*front=pq.front();
          pq.pop();
          if(front->data==target)res=front;
          
          if(front->left){
              pq.push(front->left);
              mp[front->left]=front;
          }
          if(front->right){
              pq.push(front->right);
              mp[front->right]=front;
          }
      }
      return res;
  }
   
   int timetaken(Node*target,unordered_map<Node*,Node*>&mp){
       
       int maxt=0;
       queue<Node*>q;
       unordered_map<Node*,int>vis;
       q.push(target);
       vis[target]=1;
       while(!q.empty()){
           int size=q.size();
           int f=0;
           
           for(int i=0;i<size;i++){
               Node*front=q.front();
               q.pop();
               
               if(front->left &&!vis[front->left]){
                   q.push(front->left);
                   vis[front->left]=1;
                   f=1;
               }
               if(front->right &&!vis[front->right]){
                   q.push(front->right);
                   vis[front->right]=1;
                   f=1;
               }
               
               if(mp[front]&&!vis[mp[front]]){
                   q.push(mp[front]);
                   vis[mp[front]]=1;
                   f=1;
               }
           }
           if(f==1)maxt++;
       }
       return maxt;
   }
  
  
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>mp;
        Node*res=findnode(root,target,mp);
        
        return timetaken(res,mp);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends