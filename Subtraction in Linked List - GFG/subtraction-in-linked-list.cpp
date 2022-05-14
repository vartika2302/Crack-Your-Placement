// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

Node* subLinkedList(Node* l1, Node* l2);

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
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

//Function to iteratively reverse the linked list
void iterativeReverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nex;
    while(curr){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;
}

//Function to check which linked list denotes greater number
//Return 1 if l1 is denotes greater number and 2 if l2 denotes greater number
int greaterList(Node* l1, Node* l2){
    while(l1 && l1->data==0){
        l1=l1->next;
    }
    while(l2 && l2->data==0){
        l2=l2->next;
    }
    Node* t1 = l1,*t2 = l2;
    int n1 = 0,n2 = 0;
    while(t1){
        n1++;
        t1 = t1->next;
    }
    while(t2){
        n2++;
        t2 = t2->next;
    }
    if(n1 > n2){
        return 1;
    }
    else if(n1 < n2){
        return 2;
    }
    
        t1 = l1;
        t2 = l2;
        while(t1 && t2){
            if(t1->data < t2->data){
                return 2;
            }
            else if(t1->data > t2->data){
                return 1;
            }
            else{
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        return 1;
    
}

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    
    int check = greaterList(l1,l2);
    iterativeReverse(l1);
    iterativeReverse(l2);
    Node* t1 = l1, *t2 = l2;
    Node* newList = new Node(0);
    Node* temp = newList;
    int f,s;
    bool flag = true;
    if(check == 1){
        while(t1 || t2){
                f = t1 ? t1->data : 0;
                s = t2 ? t2->data : 0;
            if(f >= s){
                if(flag == false){
                    if(f>s){
                        temp->next = new Node(f-1-s);
                        flag = true;
                    }else{
                        temp->next = new Node(9+f-s);
                    }
                   
                }
                else{
                    temp->next = new Node(f-s);
                }
                temp = temp->next;
            }
            else{
                if(flag){
                    temp->next = new Node(10+f-s);
                    flag = false;
                }
                else{
                    temp->next = new Node(9+f-s);
                }
                temp=temp->next;
            }
            t1 = t1 ? t1->next : NULL;
            t2 = t2 ? t2->next : NULL;
        }
    }
    else {
        while(t1 || t2){
            f = t2 ? t2->data : 0;
            s = t1 ? t1->data : 0;
            if(f >= s){
                if(flag == false){
                    if(f>s){
                        temp->next = new Node(f-1-s);
                        flag = true;
                    }else{
                        temp->next = new Node(9+f-s);
                    }
                   
                }
                else{
                    temp->next = new Node(f-s);
                }
                temp = temp->next;
            }
            else{
                if(flag){
                    temp->next = new Node(10+f-s);
                    flag = false;
                }
                else{
                    temp->next = new Node(9+f-s);
                }
                temp = temp->next;
            }
            t1 = t1 ? t1->next : NULL;
            t2 = t2 ? t2->next : NULL;
        }
    }
    temp->next = NULL;
    newList = newList->next;
    iterativeReverse(newList);
    while(newList && newList->data == 0){
        newList = newList->next;
    }
    if(newList){
        return newList;
    }
    return new Node(0);
    
    
    
    
    
    
}