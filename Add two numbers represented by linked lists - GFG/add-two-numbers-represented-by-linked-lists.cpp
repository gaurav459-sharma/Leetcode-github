//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node*reverse(Node*head){
        if(head==NULL||head->next==NULL)return head;
        
        Node*smallans=reverse(head->next);
        Node*tail=head->next;
        head->next=NULL;
        tail->next=head;
        return smallans;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node*head1=reverse(first);
        Node*head2=reverse(second);
        int carry=0;
        Node*dummy=new Node(0);
        Node*tail=dummy;
        while(head1!=NULL &&head2!=NULL){
            int sum=(head1->data+head2->data+carry);
            int val=sum%10;
            carry=sum/10;
            Node*newnode=new Node(val);
            tail->next=newnode;
            tail=newnode;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1){
            int sum=(head1->data+carry);
            int val=sum%10;
            carry=sum/10;
            Node*newnode=new Node(val);
            tail->next=newnode;
            tail=newnode;
            head1=head1->next;
        }
        while(head2){
            int sum=(head2->data+carry);
            int val=sum%10;
            carry=sum/10;
            Node*newnode=new Node(val);
            tail->next=newnode;
            tail=newnode;
            head2=head2->next;
        }
        if(carry){
            Node*newnode=new Node(carry);
            tail->next=newnode;
        }
        return reverse(dummy->next);
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends