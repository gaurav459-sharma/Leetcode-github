//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
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

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1=0;
    Node*tmp1=head1;
    while(tmp1!=NULL){
        len1++;
        tmp1=tmp1->next;
    }
    int len2=0;
    Node*tmp2=head2;
    while(tmp2!=NULL){
        len2++;
        tmp2=tmp2->next;
    }
    int diff=abs(len1-len2);
   
    if(len1>len2){
        tmp1=head1;
        tmp2=head2;
    }
    else{
        tmp1=head2;
        tmp2=head1;
    }
    int i=0;
    while(i<diff){
            i++;
            tmp1=tmp1->next;
    }
    if(tmp1==tmp2 &&tmp1!=NULL)return tmp1->data;
    while(tmp1!=NULL &&tmp2!=NULL){
        tmp1=tmp1->next;
        tmp2=tmp2->next;
        if(tmp1==tmp2)return tmp1->data;
    }
    return -1;
    
    
}

