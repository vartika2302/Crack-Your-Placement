// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* midPoint(Node*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node*slow=head;
        Node*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    // merge two sorted list
    Node* merge(Node*a , Node*b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        Node*c;
        if(a->data < b->data){
            c = a;
            c->next = merge(a->next,b);
        }
        else{
            c=b;
            c->next = merge(a,b->next);
        }
        return c;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        // divide, sort individual parts, merge
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        // find mid point and split the list
        Node* mid = midPoint(head);
        Node* firstList = head;
        Node* secondList = mid->next;
        mid->next=NULL;
        
        // sort individual list using mergeSort and then merge them
        firstList = mergeSort(firstList);
        secondList = mergeSort(secondList);
        Node*new_head=merge(firstList,secondList);
        return new_head;
        
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends